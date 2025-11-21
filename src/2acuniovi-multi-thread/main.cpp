/*
 * Main.cpp
 *
 *  Created on: Fall 2019
 */

#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <CImg.h>

#define R_WEIGHT 0.3
#define G_WEIGHT 0.59
#define B_WEIGHT 0.11
#define MAX_BRIGHTNESS 255.0



#define NUM_THREADS 6

//Number of iterations of the filter so it reaches the required time
#define N_ITERATIONS 125

using namespace cimg_library;

// Data type for image components
typedef double data_t;

const char* SOURCE_IMG      = "bailarina.bmp";
const char* DESTINATION_IMG = "bailarina2.bmp";

pthread_barrier_t barrier_start; 
pthread_barrier_t barrier_end; 
volatile bool keep_running = true; 
int current_iteration = 0;

// Structure used by each thread to know which part of the image to process.
typedef struct {
    data_t *pRsrc, *pGsrc, *pBsrc;
    data_t *pRdst, *pGdst, *pBdst;
    uint start, end;
	uint iteration;
} thread_args_t;

// Filter argument data type
typedef struct {
	data_t *pRsrc; // Pointers to the R, G and B components
	data_t *pGsrc;
	data_t *pBsrc;
	data_t *pRdst;
	data_t *pGdst;
	data_t *pBdst;
	uint pixelCount; // Size of the image in pixels
} filter_args_t;

/***********************************************
 * 
 * Algorithm. B&W inversion (#3).
 * 
 * Formula:
 * 
 * Para cada i = 0,...,pixelCount:
 * 1) Convertir a B&W
 * 	L(i) = 0.3 R(i) + 0.59 G(i) + 0.11 B(i)
 * 
 * 2) Invertir
 * 	L(i) = 255 - L(i)
 * 		
 * *********************************************/
void* thread_filter(void* args){
    thread_args_t* tArgs = (thread_args_t*) args;
    
    data_t *pR_base = tArgs->pRsrc + tArgs->start;
    data_t *pG_base = tArgs->pGsrc + tArgs->start;
    data_t *pB_base = tArgs->pBsrc + tArgs->start;
    data_t *pRdst_base = tArgs->pRdst + tArgs->start;
    data_t *pGdst_base = tArgs->pGdst + tArgs->start;
    data_t *pBdst_base = tArgs->pBdst + tArgs->start;
    
    uint length = tArgs->end - tArgs->start;
    uint length_unroll = (length / 4) * 4; // Múltiplo de 4 para unrolling
    
    for(uint iter = 0; iter < tArgs->iteration; iter++){
        data_t *pR = pR_base;
        data_t *pG = pG_base;
        data_t *pB = pB_base;
        data_t *pRdst = pRdst_base;
        data_t *pGdst = pGdst_base;
        data_t *pBdst = pBdst_base;
        
        // Procesar 4 píxeles por iteración
        for (uint i = 0; i < length_unroll; i += 4) {
            // Píxel 0
            data_t L0 = MAX_BRIGHTNESS - (pR[0] * R_WEIGHT + pG[0] * G_WEIGHT + pB[0] * B_WEIGHT);
            pRdst[0] = L0;
            pGdst[0] = L0;
            pBdst[0] = L0;
            
            // Píxel 1
            data_t L1 = MAX_BRIGHTNESS - (pR[1] * R_WEIGHT + pG[1] * G_WEIGHT + pB[1] * B_WEIGHT);
            pRdst[1] = L1;
            pGdst[1] = L1;
            pBdst[1] = L1;
            
            // Píxel 2
            data_t L2 = MAX_BRIGHTNESS - (pR[2] * R_WEIGHT + pG[2] * G_WEIGHT + pB[2] * B_WEIGHT);
            pRdst[2] = L2;
            pGdst[2] = L2;
            pBdst[2] = L2;
            
            // Píxel 3
            data_t L3 = MAX_BRIGHTNESS - (pR[3] * R_WEIGHT + pG[3] * G_WEIGHT + pB[3] * B_WEIGHT);
            pRdst[3] = L3;
            pGdst[3] = L3;
            pBdst[3] = L3;
            
            // Avanzar punteros 4 posiciones
            pR += 4;
            pG += 4;
            pB += 4;
            pRdst += 4;
            pGdst += 4;
            pBdst += 4;
        }
        
        // Procesar píxeles restantes
        for (uint i = length_unroll; i < length; i++) {
            data_t L = MAX_BRIGHTNESS - (*pR++ * R_WEIGHT + *pG++ * G_WEIGHT + *pB++ * B_WEIGHT);
            *pRdst++ = L;
            *pGdst++ = L;
            *pBdst++ = L;
        }
    }
    pthread_exit(NULL);
}

/***********************************************
 * Multithreaded filter execution
 * Creates threads, distributes work, and waits for completion
 * *********************************************/
void execute_multithreaded_filter(filter_args_t filter_args, uint pixelsPerThread) {
	pthread_t threads[NUM_THREADS];
	thread_args_t thread_args[NUM_THREADS];

	uint iterationsPerThread = N_ITERATIONS / NUM_THREADS;
	uint remainingIterations = N_ITERATIONS % NUM_THREADS;
	
	// Prepare thread arguments and create threads
	for (uint t = 0; t < NUM_THREADS; t++) {
		thread_args[t].pRsrc = filter_args.pRsrc;
		thread_args[t].pGsrc = filter_args.pGsrc;
		thread_args[t].pBsrc = filter_args.pBsrc;
		thread_args[t].pRdst = filter_args.pRdst;
		thread_args[t].pGdst = filter_args.pGdst;
		thread_args[t].pBdst = filter_args.pBdst;
		thread_args[t].iteration = (t < remainingIterations) ?
		iterationsPerThread + 1 : iterationsPerThread;
		
		// Calculate start and end pixels for this thread
		thread_args[t].start = t * pixelsPerThread;
		// Last thread processes remaining pixels
		if (t == NUM_THREADS - 1) {
			thread_args[t].end = filter_args.pixelCount;
		} else {
			thread_args[t].end = (t + 1) * pixelsPerThread;
		}
		
		if(pthread_create(&threads[t],NULL,thread_filter, &thread_args[t])!=0){
			fprintf(stderr,"Error creating thread");
			exit(EXIT_FAILURE);
		}
	}
	
	// Wait for all threads to finish
	for (uint t = 0; t < NUM_THREADS; t++) {
		if (pthread_join(threads[t], NULL) != 0) {
			fprintf(stderr, "Error joining thread %d\n", t);
			exit(EXIT_FAILURE);
		}
	}
}

int main() {
	CImg<data_t> srcImage;
	// Cargar imagen fuente - Controlando si existe
	try {
    	srcImage = CImg<data_t>(SOURCE_IMG);
	} catch (CImgException& e) {
		fprintf(stderr, "ERROR: la imagen '%s' no existe.\n", SOURCE_IMG);
		exit(EXIT_FAILURE);
	}

	filter_args_t filter_args;
	data_t *pDstImage; // Pointer to the new image pixels
	 

	/***************************************************
	 *   - Prepare variables for the algorithm
	 *   - This is not included in the benchmark time
	 */
	struct timespec tStart, tEnd; // Variables for time measurement
	double elapsedTime;     // Elapsed time in seconds

	srcImage.display(); // Displays the source image
	uint width = srcImage.width();// Getting information from the source image
	uint height = srcImage.height();	
	uint nComp = srcImage.spectrum();// source image number of components
	         // Common values for spectrum (number of image components):
				//  B&W images = 1
				//	Normal color images = 3 (RGB)
				//  Special color images = 4 (RGB and alpha/transparency channel)

	// Calculating image size in pixels
	filter_args.pixelCount = width * height;
	uint pixelsPerThread = filter_args.pixelCount / NUM_THREADS;
	
	// Allocate memory space for destination image components
	pDstImage = (data_t *) malloc (filter_args.pixelCount * nComp * sizeof(data_t));
	if (pDstImage == NULL) {
		perror("Allocating destination image");
		exit(-2);
	}

	// Pointers to the componet arrays of the source image
	filter_args.pRsrc = srcImage.data(); // pRcomp points to the R component array
	filter_args.pGsrc = filter_args.pRsrc + filter_args.pixelCount; // pGcomp points to the G component array
	filter_args.pBsrc = filter_args.pGsrc + filter_args.pixelCount; // pBcomp points to B component array
	
	// Pointers to the RGB arrays of the destination image
	filter_args.pRdst = pDstImage;
	filter_args.pGdst = filter_args.pRdst + filter_args.pixelCount;
	filter_args.pBdst = filter_args.pGdst + filter_args.pixelCount;


	/***********************************************
	 *   - Measure initial time
	 */
	if(clock_gettime(CLOCK_REALTIME, &tStart) == -1) {
		printf("Error al obtener el tiempo inicial");
		exit(EXIT_FAILURE);
	}

	/************************************************
	 * Algorithm - Multithreaded version
	 */
	
		execute_multithreaded_filter(filter_args, pixelsPerThread);


	/***********************************************
	 *   - Measure the end time
	 *   - Calculate the elapsed time
	 */
	if(clock_gettime(CLOCK_REALTIME, &tEnd) == -1){
		printf("Error al obtener el tiempo final");
		exit(EXIT_FAILURE);
	}
	elapsedTime = (tEnd.tv_sec - tStart.tv_sec) + (tEnd.tv_nsec - tStart.tv_nsec) / 1e+9;
	printf("Elapsed time (%d repetitions, %d threads): %.6f seconds\n", N_ITERATIONS, NUM_THREADS, elapsedTime);

		
	// Create a new image object with the calculated pixels
	// In case of normal color images use nComp=3,
	// In case of B/W images use nComp=1.
	CImg<data_t> dstImage(pDstImage, width, height, 1, nComp);

	if (static_cast<unsigned int>(dstImage.width()) != width || 
		static_cast<unsigned int>(dstImage.height()) != height || 
		static_cast<unsigned int>(dstImage.spectrum()) != nComp) {
		fprintf(stderr, "Error: las dimensiones de la imagen de salida no coinciden con la original.\n");
		free(pDstImage);
		exit(EXIT_FAILURE);
	}

	// Store destination image in disk
	dstImage.save(DESTINATION_IMG); 

	// Display destination image
	dstImage.display();
	
	// Free memory
	free(pDstImage);

	return 0;
}
