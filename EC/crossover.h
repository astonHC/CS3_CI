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

// CROSSOVER METHODS
// DETERMINES THE WAY IN WHICH CROSSOVER WILL BE HANDLED
// OVER THE DURATION OF THE ALGORITHM

typedef enum TYPE
{
    SINGLE,
    DOUBLE,
    UNIFORM,

} TYPE;

// REPRESENT AN INVIDUAL IN THE POPULATION

typedef struct PERSON
{
    char CHROMOSOMES[46];
    int WELLBEING;

} PERSON;

int FITNESS_CALC(char*);
int CROSS_SINGLE(char*, char*, char*, char*);
int CROSS_DOUBLE(char*, char*, char*, char*);
void CROSS_UNI(char*, char*, char*, char*);

void CROSS_ALL(char*, char*, char*, char*, TYPE CROSS_TYPE);
void MUTATE(char*);

int SELECTION(PERSON* P);
int COMPARE_PERSON(const void* PERSON_A, const void* PERSON_B);
