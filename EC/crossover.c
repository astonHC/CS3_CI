// COPYRIGHT (C) HARRY CLARK 2025
// CS3_CI EVOLUTIONARY COMPUTATION 

// THIS FILE PERTAINS TOWARDS AN EXAMPLE OF HOW UTILISING CROSSOVER
// ALLOWS FOR THE GRADUAL MUTATION/REPRODUCTION OF AN ALGORITHM OVER THE COURSE
// OF IT'S RUNTIME

// SYSTEM INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define     EC_POP_SIZE         200
#define     EC_STRING           "HARRY CLARK"
#define     EC_STRLEN           strlen(EC_STRING)
#define     EC_MAX_GEN          100
#define     EC_MUT_RATE         15
#define     EC_CRS_RATE         85
#define     EC_SELECT           5
#define     EC_PFRM             10