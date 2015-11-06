/*
 * pi.c
 * Andy Sayler
 * CSCI 3308
 * Summer 2014
 *
 * Description:
 * This file contains a simple program for statistically calculating pi.
 *
 */

/* Local Includes */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <errno.h>

/* Local Defines */
#define DEFAULT_ITERATIONS 1000000
#define RADIUS (RAND_MAX / 2)

/* Local Types */
typedef struct coordinate {
    float x;
    float y;
} coordinate_t;

/* Local Functions */
float dist(const coordinate_t* pt_a, const coordinate_t* pt_b){
    return sqrt((pt_a->x - pt_b->x)*(pt_a->x - pt_b->x) + (pt_a->y - pt_b->y)*(pt_a->y-pt_b->y));
}

float zeroDist(const coordinate_t* other_pt){

    /* Local vars */
    float d = 0.0;
    coordinate_t* zero_pt = NULL;

    /* Create new zero point */
    zero_pt = malloc(sizeof(*zero_pt));
    if(!zero_pt){
        fprintf(stderr, "Malloc failed\n");
        return NAN;
    }
    zero_pt->x = 0.0;
    zero_pt->y = 0.0;

    /* Calculate Distance */
    d = dist(zero_pt, other_pt);
	free(zero_pt);
    /* Return distance */
    return d;

}

/* Main */
int main(int argc, char* argv[]){

    /* Local vars */
    long i;
    long iterations;
    coordinate_t* pt = NULL;
    long inCircle = 0;
    long inSquare = 0;
    float  pCircle = 0.0;
    float  piCalc = 0.0;

    /* Process program arguments to select iterations */
    if(argc < 2){
        /* Set default iterations if not supplied */
        iterations = DEFAULT_ITERATIONS;
    }
    else{
        /* Set iterations if supplied */
        iterations = atol(argv[1]);
        if(iterations < 1){
            fprintf(stderr, "Bad iterations value\n");
            exit(EXIT_FAILURE);
        }
    }

    /* Seed RNG */
    srand(time(NULL));
    pt = malloc(sizeof(*pt));
 
    /* Calculate pi using statistical methode across all iterations*/
    for(i=0; i<iterations; i++){
        /* todo: remember to allocate pt */
        pt->x = (rand() % (RADIUS * 2)) - RADIUS;
        pt->y = (rand() % (RADIUS * 2)) - RADIUS;
        if(zeroDist(pt) < RADIUS){
            inCircle++;
        }
        inSquare++;
    }

    /* Finish calculation */
    pCircle = (float) inCircle / (float) inSquare;
    piCalc = pCircle * 4.0;

    /* Print result */
    fprintf(stdout, "pi = %f\n", piCalc);
   free(pt);
    return 0;
}
