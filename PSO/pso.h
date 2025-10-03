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

        // DEFINE THE BASIS BY WHICH THE PSO
        // WILL BE DEFINED, BASED ON IT'S RESPECTIVE PARAMS
        typedef struct
        {
            double POSITION[PSO_MAX_DIMENSIONS];
            double VELOCITY[PSO_MAX_DIMENSIONS];
            double BEST_POS[PSO_MAX_DIMENSIONS];
            double BEST_FITNESS;
            double CURRENT_FITNESS;
            int STAGNATE;
            
        } PSO_PARTICLE;

        // DEFINE THE BASIS FOR THE SWARM ITSELF
        // ACCESSES ALL OF THE CONCURRENT PARTICLES
        // AND THEIR "BEST FITNESS" PARAMS
        typedef struct
        {
            PSO_PARTICLE PARTICLE[PSO_MAX_PARTICLES];
            double GLOBAL_POS;
            double GLOBAL_FITNESS;
            
            union
            {
                int COUNT;
                int ITERATION;
                int CONVERGENCE;
                
            } PARTICLE;

        }  PSO_SWARM;

        // DEFINE ALL OF THE PARAMETERS
        // SPECIFIC TO THE GP ITSELF
        // HELPS WITH OPTMISING THE SPACE AS WE CAN REDUCE
        // THE AMOUNT OF OVERHEAD ENCOMPASSED BY SEARCH SPACE
        typedef union
        {   
            double MUTATION;
            double CROSSOVER;
            double ELITISM;
            double TOUR_SIZE;
            double MAX_DEPTH;
            double POP_SIZE;

        } PSO_GP;

        typedef struct
        {
            PSO_SWARM SWARM;
            int BOUNDS;
            PSO_FITNESS_TYPE FITNESS;
            PSO_GP GP;
            int DIMENSIONS;
            double CONV_THRESHOLD;

        } PSO;

        typedef enum
        {
            PSO_ERROR_NONE = 0,
            PSO_ERROR_OOB,
            PSO_ERROR_PARTICLE,
            PSO_ERROR_CONVERGENCE,
            PSO_ERROR_FITNESS,
            PSO_ERROR_DIM

        } PSO_ERROR;

        typedef enum
        {
            NONE = 'N',
            OOB = 'O',
            PART = 'P',
            CONV = 'C',
            FIT = 'F',
            DIM = 'D'

        } PSO_ERROR_OP;

#endif
#endif
