# CS3_CI
All of my study material pertaining towards the Computational Intelligence Module (Aston University)

## Motive:

This repository aims to provide reliable solutions for any and all problems discussed and studied in the Computational Intelligence module - this serves to be my learning aid moreover if anything else. 

## Contents:

The following topics and subject areas that will be provided in this repository are the following:

- [Evolutionary Computation](https://github.com/astonHC/CS3_CI/tree/main/EC)
- Neural Networks
- Particle Swarm Optimisation

## Repository Structure & Building:

Each of the subject areas will be delegated to their own folder, each with their own source file.

To run each solution, look at he provided build instructions in each folder's README

## Features:

One of the many features exclusive to this project is the ``ERROR_TRACE`` handling for being able to properly discern the inner workings 
of all of the contents encompassing this repository

```c
// ACCESSES AN OPERATION FROM AN ENUM
// THE ERROR STRING, AND ANY VARIDATIC ARGS 
// AS PER EACH UNIQUE USE CASE

#if ERROR_TRACE_HOOK    
    #define ERROR_TRACE(OP, ERR, MSG, ...) \
        printf("[TRACE] %c -> %s - " MSG "\n", \
              (char)(OP), \
                  EVO_TRACE_ERR[(ERR)], \
              ##__VA_ARGS__)
#else
    #define ERROR_TRACE(OP, ERR, MSG, ...) ((void)0)
#endif
```

#### Example Usage of ERROR_TRACE:

```c
// main.c - ACCESS THE FINAL STRING IF THE WELLBEING OF THE PERSON IS MATCHED
if(CURRENT_POPULATION[0].WELLBEING == EC_STRLEN)
{
    ERROR_TRACE(EVO, TRACE_OK, "SOLUTION FOUND IN GENERATION %d", GEN);
    printf("FINAL STRING: %s\n", CURRENT_POPULATION[0].CHROMOSOMES);
    break;
}
```
