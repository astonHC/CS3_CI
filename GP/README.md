## Genetic Programming

## Motive:

The following serves to provide my implementation for the module contents encompassing Genetic Programming; a subsection of Evolutionary Computation which focusses on the node-based structure and represetnation of respective elements.

Much different to the contempoaries of it's parent association, GP focusses on the gradual building of the Evolutionary model during runtime - mitigating the overhead to painstakingly create the fitness for your Population.

Rather, GP does this manually by creating nodes which uses Depth-first traversal to make node connections a lot more common, at the subsequent cost of performance and speed.


## Building:

Everything as of now, is a WIP though, it is a simple case of running:

``gcc --std=c99 -pedantic main.c gp.c -o gp -lm``
