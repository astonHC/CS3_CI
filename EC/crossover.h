// COPYRIGHT (C) HARRY CLARK 2025
// CS3_CI EVOLUTIONARY COMPUTATION 

// THIS FILE PERTAINS TOWARDS AN EXAMPLE OF HOW UTILISING CROSSOVER
// ALLOWS FOR THE GRADUAL MUTATION/REPRODUCTION OF AN ALGORITHM OVER THE COURSE
// OF IT'S RUNTIME

#ifndef EC_CROSSOVER_H
#define EC_CROSSOVER_H

// SYSTEM INCLUDES

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define     EC_POP_SIZE         50
#define     EC_STRING           "HARRY CLARK"
#define     EC_STRLEN           strlen(EC_STRING)
#define     EC_MAX_GEN          200
#define     EC_MUT_RATE         3
#define     EC_CRS_RATE         70
#define     EC_SELECT           5
#define     EC_PFRM             5
#define     EC_GUIDE_PROB       20
#define     EC_CS               46

#define EC_STATUS() \
    printf("EVO CONFIG:\n"); \
    printf("    TARGET STRING: %s\n", EC_STRING);                   \
    printf("    CURRENT CROSSOVER TYPE: %s\n", CROSSOVER_TYPE_STRINGS[CURRENT_CROSSOVER_METHOD]); \
    printf("    POPULATION SIZE: %d\n", EC_POP_SIZE);               \
    printf("    MAXIMUM GENERATIONS: %d\n", EC_MAX_GEN);            \
    printf("    MUTATION RATE: %d%%\n", EC_MUT_RATE);               \
    printf("    CROSSOVER RATE: %d%%\n", EC_CRS_RATE);              \
    printf("    CHROMOSOMES: %d\n",     EC_CS);                     \
    printf("    TOURNAMENT SIZE: %d\n", EC_SELECT);                 \
    printf("    ELITE PRESERVATION: %d\n", EC_PFRM);                \
    printf("    GUIDED PROBABILITY RATE: %d\n\n", EC_GUIDE_PROB);   \
    printf("\n")                                                \

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

bool RANDOM_MUTATE(int);
bool USE_GUIDED_MUT(int);

int SELECTION(PERSON* P);
int COMPARE_PERSON(const void* PERSON_A, const void* PERSON_B);

void POPULATION_INIT(PERSON* POPULATION);
void POPULOUS_FITNESS(PERSON* POP, int SIZE);
void PRESERVE_ELITE(PERSON* CURRENT, PERSON* NEW_POP, int ELITE);

void GEN_OFFSPRING(PERSON* CURRENT, PERSON* NEW_POP, int START, int END);
void COPY_POP(PERSON* SRC, PERSON* DEST, int SIZE);

static TYPE CURRENT_CROSSOVER_METHOD;
static const char* CROSSOVER_TYPE_STRINGS[] = 
{
    "SINGLE",
    "DOUBLE",
    "UNIFORM"
};

#endif
