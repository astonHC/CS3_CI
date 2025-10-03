// COPYRIGHT (C) HARRY CLARK 2025
// CS3_CI PARTICLE SWARM OPTIMISATION FOR GENETIC PROGRAMMING

// THIS FILE PERTAINS TOWARDS THE IMEPLEMENTATION AND MODULARISATION OF THE PSO
// THE FOLLOWING WILL PRESUPPOSE A CURATION OF PARTICLES TO ACT AS A SEPARATED
// COLLECTION OF SOLUTIONS TO CREATE A MORE EFFICIENT SEARCH SPACE FOR A POTENTIAL SOLUTION
//
// SUPPOSE THE BEST COMPARISON COULD BE THAT OF MEMORY ALLOCATION
// WHEREBY LITTLE CHUNKS ARE CREATED TO DELEGATE SPACE FOR ALLOCATION AND DISCERNMENT 
// FOR SOLUTION SPACE

#ifndef PSO_H
#define PSO_H

// SYSTEM INCLUDES

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(USE_PSO)
    #define USE_PSO
#else
    #define USE_PSO

    #define         PSO_MAX_PARTICLES           30
    #define         PSO_MAX_ITERATIONS          100
    #define         PSO_MAX_DIMENSIONS           10

    #define         PSO_WEIGHT                      0.8
    #define         PSO_COG                         1.5
    #define         PSO_SOC                         1.5

    #define         PSO_LOWER                       (1 << 0)
    #define         PSO_UPPER                       (1 << 1)

    #define     PSO_MEM_ERROR(VALUE) \
        do { \
            if ((VALUE) == NULL) { \
                printf("MEMORY ALLOCATION FAILED FOR %s, 0x%p\n", #VALUE, (void*)&(VALUE)); \
                return 1; \
            } \
        } while(0)

        // DEFINE THE FUNCTION TYPES FOR THE TYPE OF GP ALGO
        // THIS MAY BE EXPANDED AT SOME POINT
        typedef enum
        {
            PSO_SIMPLE,
            PSO_VALLEY,

        } PSO_FITNESS_TYPE;
 

#endif
#endif
