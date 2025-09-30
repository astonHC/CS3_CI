// COPYRIGHT (C) HARRY CLARK 2025
// CS3_CI GENETIC PROGRAMMING DEMONSTRATION

// THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY ENCOMPASSING A GENETIC PROGRAMMING DEMO
// PRESUPPOSES ALL OF THE CONSTANTS AND FIELDS NEEDED TO REPRESENT A GENERIC GA
//
// ALL OF THIS IS CREATED WITHIN THE SCOPE OF THE MODULES CONTENTS AS PER CS3_CI
// AND MADE WITHIN THE CONTEXT OF PROVIDING A CONTEXTUALISED POINT FOR COMPARISON BETWEEN ALGORITHMS 

#ifndef GP_H
#define GP_H

// SYSTEM INCLUDES

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(USE_GP)
    #define USE_GP
#else
    #define USE_GP

    #define     GP_MAX_POP                  100                 // MAXIMUM POPULATION
    #define     GP_MAX_TREE_DEPTH           6                   // MAX DEPTH FOR TRAVERSAL
    #define     GP_MAX_NODES                127                 
    #define     GP_TOUR_SIZE                3                   // TOURNAMENT SELECTION SIZE
    #define     GP_DIV_APPR                 0.001f              // APPROXMIATION VALUE TO HANDLE DIVISION BETTER


    #define     GP_SEED()                   srand((unsigned int)time(NULL))
    #define     GP_RAND()                   ((double)rand() / (double))         // LEVERAGE DOUBLE FOR GREATER FP ACCURACY

#endif
#endif
