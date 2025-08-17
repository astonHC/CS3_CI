// COPYRIGHT (C) HARRY CLARK 2025
// COMMON UTILITY

// THIS FILE PERTAINS MOSTLY TOWARDS COMMON UTILITY TO HELP WITH DEBUGGING AND PRINTING

// SYSTEM INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    MEM_OK,
    MEM_ERR_UNMAPPED,
    MEM_ERR_SIZE,
    MEM_ERR_RESERVED,
    MEM_ERR_OVERFLOW,
    MEM_ERR_BAD_READ,
    MEM_ERR_BAD_WRITE

} MEM_ERROR;