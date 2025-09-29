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

using namespace cimg_library;

// Data type for image components
// FIXME: Change this type according to your group assignment
typedef float data_t;

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
    for (uint i = 0; i < args.pixelCount; i++) {
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
	// Open file and object initialization
	CImg<data_t> srcImage(SOURCE_IMG);

	filter_args_t filter_args;
	data_t *pDstImage; // Pointer to the new image pixels


	/***************************************************
	 * TODO: Variables initialization.
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
	 * TODO: Algorithm start.
	 *   - Measure initial time
	 */
	clock_gettime(CLOCK_REALTIME, &tStart); // Initial time


	/************************************************
	 * Algorithm.
	 */
	filter(filter_args);


	/***********************************************
	 * TODO: End of the algorithm.
	 *   - Measure the end time
	 *   - Calculate the elapsed time
	 */
	clock_gettime(CLOCK_REALTIME, &tEnd); // End time
	elapsedTime = (tEnd.tv_sec - tStart.tv_sec) + (tEnd.tv_nsec - tStart.tv_nsec) / 1e+9;
	printf("Elapsed time: %.6f seconds\n", elapsedTime);

		
	// Create a new image object with the calculated pixels
	// In case of normal color images use nComp=3,
	// In case of B/W images use nComp=1.
	CImg<data_t> dstImage(pDstImage, width, height, 1, nComp);

	// Store destination image in disk
	dstImage.save(DESTINATION_IMG); 

	// Display destination image
	dstImage.display();
	
	// Free memory
	free(pDstImage);

	return 0;
}
