// COPYRIGHT (C) HARRY CLARK 2025
// COMMON UTILITY

// THIS FILE PERTAINS MOSTLY TOWARDS COMMON UTILITY TO HELP WITH DEBUGGING AND PRINTING

#ifndef UTIL_H
#define UTIL_H

// SYSTEM INCLUDES

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define     OPT_OFF             0
#define     OPT_ON              1

#define     OPT_BASIC           (1 << 0)
#define     OPT_VERB            (1 << 1)

#define     OPT_ALL             (OPT_BASIC | OPT_VERB)

typedef enum
{
    EVO = 'E',
    SELECT = 'S',
    CROSS = 'C',
    MUT = 'M',
    FITNESS = 'F',
    INIT = 'I',
    ERROR = '!'

} TRACE_OP;

typedef enum 
{   
    TRACE_OK,                   
    TRACE_ERR_INIT,             
    TRACE_ERR_FITNESS,           
    TRACE_ERR_SELECTION,         
    TRACE_ERR_CROSSOVER,        
    TRACE_ERR_MUTATION,          
    TRACE_ERR_GENERATION

} TRACE_ERROR;

/////////////////////////////////////////////////////
//              GLOBAL DEFINITIONS
/////////////////////////////////////////////////////

static bool TRACE_ENABLED = true;
static uint8_t ENABLED_FLAGS = OPT_ALL;

static const char* EVO_TRACE_ERR[] = 
{
    "OK",
    "INITIALIZATION",
    "FITNESS CALCULATION",
    "SELECTION PROCESS",
    "CROSSOVER OPERATION",
    "MUTATION OPERATION",
    "GENERATION PROCESS"
};

/////////////////////////////////////////////////////
//            TRACE CONTROL FUNCTIONS
/////////////////////////////////////////////////////

#define         VERBOSE_TRACE_HOOK              OPT_ON
#define         ERROR_TRACE_HOOK                OPT_ON

static inline bool IS_TRACE_ENABLED(uint8_t FLAG) 
{
    return TRACE_ENABLED && (ENABLED_FLAGS & FLAG);
}

static inline void ENABLE_TRACE_FLAGS(uint8_t FLAGS) 
{
    ENABLED_FLAGS |= FLAGS;
}

static inline void DISABLE_TRACE_FLAGS(uint8_t FLAGS) 
{
    ENABLED_FLAGS &= ~FLAGS;
}

#if VERBOSE_TRACE_HOOK
#define VERBOSE_TRACE(MSG, ...) \
    do { \
        if (VERBOSE_TRACE_HOOK == OPT_ON && IS_TRACE_ENABLED(OPT_VERB)) \
            printf("[VERBOSE] " MSG "\n", ##__VA_ARGS__); \
    } while(0)
#else
    #define VERBOSE_TRACE(MSG, ...) ((void)0)
#endif

#if ERROR_TRACE_HOOK    
    #define ERROR_TRACE(OP, ERR, MSG, ...) \
        printf("[TRACE] %c -> %s - " MSG "\n", \
              (char)(OP), \
                  EVO_TRACE_ERR[(ERR)], \
              ##__VA_ARGS__)
#else
    #define ERROR_TRACE(OP, ERR, MSG, ...) ((void)0)
#endif

#define SHOW_TRACE_STATUS() \
    printf("TRACE CONFIG:\n"); \
    printf("  GLOBAL TRACE:      %s\n", TRACE_ENABLED ? "ENABLED" : "DISABLED");                \
    printf("  BASIC TRACE:       %s\n", IS_TRACE_ENABLED(OPT_BASIC) ? "ENABLED" : "DISABLED");  \
    printf("  VERBOSE TRACE:     %s\n", IS_TRACE_ENABLED(OPT_VERB) ? "ENABLED" : "DISABLED");   \
    printf("\n");

#endif
