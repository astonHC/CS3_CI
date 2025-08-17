## Evolutionary Computation

The following aims to act as a demonstration for the innate ways in which Evolutionary Genetic Algorithms are able to advance and grow within the contexts of innate natural selection.

This environment is emulated through the means of Mutation, characteristics of a Person, their Wellbeing/Fitness as well as the size of the Population within the pseudo environment.

The best comparison I can make to all of this is Season 8 Episode 1 of The Simpsons where Lisa makes a small inhabitable environment 

![lisa-simpson-life](https://github.com/user-attachments/assets/23915258-b37a-473f-bdfd-9a407d84541d)


## How does this work?

This will all presuppose the following elements:

- Selection: the process of Natural Selection between two Parent Objects (based on the pre-tense of how good their wellbeing is)
- Recombination: a emulated means by which we are able to replicate the joining/combination of genetics to create child nodes (to copy offspring off of to make healthy opportunities for exploration)
- Exchange: the segments that have been copied beyond the crossover point will trickle down into the remaining elements to subsequently create new offspring.

All of this is done in O(n) Linear Time and Space Complexity as what with the expansion of Nth elements between the Parents to create the Children, coupled with the innate values encompassing the health and circumstance of the offspring, it has to run those subsequent iterations

## Building:

Just run the following in this folder:

``
gcc --std=c99 main.c crossover.c mutate.c
``
