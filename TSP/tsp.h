// COPYRIGHT (C) HARRY CLARK 2025
// CS3_CI TRAVELLING SALESMAN PROBLEM 

// THIS FILE PERTAINS TOWARDS THE MODULARISATION OF AREAS ENCOMPASSING THE TSP
// AS PER MODULE AND LAB CONTENTS OF CS3_CI

#ifndef TSP_H
#define TSP_H

// SYSTEM INCLUDES

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#if defined(USE_TSP)
    #define USE_TSP
#else
    #define USE_TSP

    #define     TSP_MAX_CITIES      5
    #define     TSP_INF             INT_MAX

    // DEFINE AN ENUM WHICH REPRESENTS THE VARIOUS ALGORITHM TYPES
    // THAT CAN BE TESTED AGAINST
    typedef enum
    {
        TSP_BRUTE_FORCE,
        TSP_NEAREST,
        TSP_HELD_KARP

    } TSP_ALGO;

    // DEFINE THE BASELINE IMPLEMENTATION FOR HOW
    // WE CAN REPRESENT A CITY
    typedef struct
    {
        char NAME[32];          
        int X;                  
        int Y;

    } TSP_CITY;

    // DEFINE THE BASELINE IMPLEMENTAITON FOR HOW
    // WE CAN REPRESENT THE MATRICES BETWEEN CITY

    // THIS IS THE MEANS BY WHICH WE CAN DETERMINE THE
    // DISTANCE BETWEEN CITIES
    typedef struct
    {
        int TSP_MATRIX[TSP_MAX_CITIES][TSP_MAX_CITIES];         // 2D ARRAY FOR MAX DIST BETWEEN
        int TSP_DIST_SIZE;
            
    } TSP_DIST;

    // DEFINE THE BASELINE IMPLEMENTATION FOR HOW
    // WE CAN REPRESENT THE PATHING THAT STARTS AT
    // A SPECIFIC CITY (TOUR)
    typedef struct
    {
        int TSP_PATH[TSP_MAX_CITIES + 1];
        int TSP_TOTAL_DIST;
        int TSP_CITY_COUNT;
        TSP_ALGO ALGO;

    } TSP_TOUR;

    // ALL ENCOMPASSING TSP STRUCT TO ACCESS THESE METHODS
    typedef struct
    {
        TSP_CITY CITY[TSP_MAX_CITIES];
        TSP_DIST DIST;
        TSP_TOUR TOUR;
        int CITY_COUNT;

    } TSP_STATE;


    /////////////////////////////////////////////////////
    //             TSP FUNCTION PROTOTYPES
    /////////////////////////////////////////////////////

    void TSP_INIT(TSP_STATE*);
    int TSP_ADD_CITY(TSP_STATE*, const char*, int, int);
    void TSP_CALC_DIST(TSP_STATE*);
    int TSP_BRUTE(TSP_STATE*);
    void TSP_RESULT(const TSP_STATE*);

    inline int TSP_BEST_DIST;
    inline int TSP_BEST_PATH[TSP_MAX_CITIES + 1];

#endif
#endif
