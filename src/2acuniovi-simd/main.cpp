/*
 * Main.cpp
 *
 *  Created on: Fall 2019
 */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <CImg.h>

#define R_WEIGHT 0.3
#define G_WEIGHT 0.59
#define B_WEIGHT 0.11
#define MAX_BRIGHTNESS 255.0

//Number of iterations of the filter so it reaches the required time
#define N_ITERATIONS 125

using namespace cimg_library;

// Data type for image components
typedef double data_t;
typedef __m256d simd_t;

const char* SOURCE_IMG      = "bailarina.bmp";
const char* DESTINATION_IMG = "bailarina2.bmp";

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

#define ITEMS_PER_PACKET (sizeof(simd_t)/sizeof(data_t))

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
void filter (filter_args_t args) {
	// 
	simd_t r_weight = _mm256_set1_pd(R_WEIGHT);
	simd_t g_weight = _mm256_set1_pd(G_WEIGHT);
	simd_t b_weight = _mm256_set1_pd(B_WEIGHT);
	simd_t max_brightness = _mm256_set1_pd(MAX_BRIGHTNESS);

	// Calculation of the size of the resulting array
    uint nPackets = (args.pixelCount / ITEMS_PER_PACKET);

	// 32 bytes (256 bits) packets. Used to stored aligned memory data
    simd_t vr, vg, vb, L; 

	// Main loop with SIMD instructions
	for(uint i = 0; i < nPackets; i++){
		uint pos = i * ITEMS_PER_PACKET;

		vr = _mm256_loadu_pd(args.pRsrc + pos);
		vg = _mm256_loadu_pd(args.pGsrc + pos);
		vb = _mm256_loadu_pd(args.pBsrc + pos);

		vr = _mm256_mul_pd(vr, r_weight);
		vg = _mm256_mul_pd(vg, g_weight);
		vb = _mm256_mul_pd(vb, b_weight);

		L = _mm256_add_pd(vr, vg);
		L = _mm256_add_pd(L, vb);

		L = _mm256_sub_pd(max_brightness, L);

		*(simd_t*)(args.pRdst + pos) = L;
		*(simd_t*)(args.pGdst + pos) = L;
		*(simd_t*)(args.pBdst + pos) = L;
	}
	
	// Calculation of the remaining data, not enough items to use SIMD
	for (uint i = nPackets * ITEMS_PER_PACKET; i < args.pixelCount; i++){
		data_t L = *(args.pRsrc + i) * R_WEIGHT + 
				*(args.pGsrc + i) * G_WEIGHT + 
				*(args.pBsrc + i) * B_WEIGHT;
		
		L = MAX_BRIGHTNESS - L;

		*(args.pRdst + i) = L;
		*(args.pGdst + i) = L;
		*(args.pBdst + i) = L;
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
	
	// Allocate memory space for destination image components (aligned to 32 bytes)
	pDstImage = (data_t *) _mm_malloc (filter_args.pixelCount * nComp * sizeof(data_t), 32);
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
	 * Algorithm.
	 */
	for (int i = 0; i < N_ITERATIONS; i++){
		filter(filter_args);
	}


	/***********************************************
	 *   - Measure the end time
	 *   - Calculate the elapsed time
	 */
	if(clock_gettime(CLOCK_REALTIME, &tEnd) == -1){
		printf("Error al obtener el tiempo final");
		exit(EXIT_FAILURE);
	}
	elapsedTime = (tEnd.tv_sec - tStart.tv_sec) + (tEnd.tv_nsec - tStart.tv_nsec) / 1e+9;
	printf("Elapsed time (%d repetitions): %.6f seconds\n", N_ITERATIONS, elapsedTime);

		
	// Create a new image object with the calculated pixels
	// In case of normal color images use nComp=3,
	// In case of B/W images use nComp=1.
	CImg<data_t> dstImage(pDstImage, width, height, 1, nComp);

	if (static_cast<unsigned int>(dstImage.width()) != width || 
		static_cast<unsigned int>(dstImage.height()) != height || 
		static_cast<unsigned int>(dstImage.spectrum()) != nComp) {
		fprintf(stderr, "Error: las dimensiones de la imagen de salida no coinciden con la original.\n");
		_mm_free(pDstImage);
		exit(EXIT_FAILURE);
	}

	// Store destination image in disk
	dstImage.save(DESTINATION_IMG); 

	// Display destination image
	dstImage.display();
	
	// Free memory
	_mm_free(pDstImage);

	return 0;
}
