// COPYRIGHT (C) HARRY CLARK 2025
// COMMON UTILITY

// THIS FILE PERTAINS MOSTLY TOWARDS COMMON UTILITY TO HELP WITH DEBUGGING AND PRINTING

// SYSTEM INCLUDES

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define     OPT_OFF             0
#define     OPT_ON              1

#define     OPT_BASIC            (1 << 0)
#define     OPT_VERB             (1 << 1)

#define     OPT_ALL              (OPT_BASIC | OPT_VERB)

typedef enum
{
    READ = 'R',
    WRITE = 'W',
    INVALID_READ = '!',
    INVALID_WRITE = '?',
    MAP = 'M',
    UNMAP = 'U'

} PRINT_OP;

typedef enum
{   
    PRINT_OK,
    PRINT_ERR_UNMAPPED,
    PRINT_ERR_SIZE,
    PRINT_ERR_RESERVED,
    PRINT_ERR_OVERFLOW,
    PRINT_ERR_BAD_READ,
    PRINT_ERR_BAD_WRITE

} PRINT_ERROR;

/////////////////////////////////////////////////////
//              GLOBAL DEFINITIONS
/////////////////////////////////////////////////////

static bool TRACE_ENABLED = true;
static uint8_t ENABLED_FLAGS = OPT_ALL;

/////////////////////////////////////////////////////
//            TRACE CONTROL FUNCTIONS
/////////////////////////////////////////////////////

#define         VERBOSE_TRACE_HOOK              OPT_ON

bool IS_TRACE_ENABLED(uint8_t FLAG)
{
    return (ENABLED_FLAGS & FLAG) == FLAG;
}

#define VERBOSE_TRACE(MSG, ...) \
    do { \
        if (VERBOSE_TRACE_HOOK == OPT_ON && IS_TRACE_ENABLED(OPT_VERB)) \
            printf("[VERBOSE] " MSG "\n", ##__VA_ARGS__); \
    } while(0)

#define SHOW_TRACE_STATUS() \
    printf("\nTRACE CONFIG:\n"); \
    printf("  BASIC:            %s\n", IS_TRACE_ENABLED(OPT_BASIC) ? "ENABLED" : "DISABLED"); \
    printf("  VERBOSE:          %s\n", (VERBOSE_TRACE_HOOK == OPT_ON && IS_TRACE_ENABLED(OPT_VERB)) ? "ENABLED" : "DISABLED"); \
    printf("\n")
