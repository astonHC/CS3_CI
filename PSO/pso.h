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

    #define         PSO_VALID_PARTICLE(VALUE, MAX)              ((VALUE) >= 0 && (VALUE) < (MAX))
    #define         PSO_VALID_DIMENSIONS(VALUE, MAX)            ((VALUE) >= 0 && (VALUE) < (MAX))
    #define         PSO_VALID_FITNESS(VALUE)                    (!isnan(VALUE) && !isinf(VALUE))

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
            double GLOBAL_POS[PSO_MAX_DIMENSIONS];
            double GLOBAL_FITNESS;
            
            union
            {
                int COUNT;
                int ITERATION;
                int CONVERGENCE;
                
            } PARTICLE_PARAMS;

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
            double LOWER;
            double UPPER;

        } PSO_BOUNDS;

        // PSO STATE REPRESENTATION
        // FIELD ARRANGEMENTS MAY CHANGE TO BETTER ACCOMMODATE
        // FOR PADDING
        typedef struct
        {
            PSO_SWARM SWARM;
            PSO_BOUNDS BOUNDS[PSO_MAX_DIMENSIONS];
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


        #define PSO_HANDLE(OP, ERROR, MSG, ...) \
                do { \
                    printf("\n[INFO] %c -> %-20s   " MSG "\n", \
                        (char)OP, PSO_ERR[ERROR], ##__VA_ARGS__); \
                } while(0)

        #define PSO_ERROR_HANDLE(OP, ERROR, MSG, ...) \
                do { \
                    printf("[ERROR] %c -> %-20s   " MSG "\n", \
                        (char)OP, PSO_ERR[ERROR], ##__VA_ARGS__); \
                } while(0)

        #define PSO_DEBUG_ITER(ITER, GBEST, MSG, ...) \
                do { \
                    printf("[ITER %3d] GBEST_FIT: %.6f   " MSG "\n", ITER, GBEST, ##__VA_ARGS__); \
                } while(0)

        #define PSO_FITNESS_NAME(VALUE) \
            ((VALUE) == PSO_SIMPLE ? "SIMPLE" : \
            (VALUE) == PSO_VALLEY ? "VALLEY" : \
            "UNKNOWN")

        /////////////////////////////////////////////////////
        //             PSO FUNCTION PROTOTYPES
        /////////////////////////////////////////////////////

        int PSO_INIT(PSO*, int, PSO_FITNESS_TYPE);
        void PSO_SET_BOUNDS(PSO*, int, double, double);

#endif
#endif
