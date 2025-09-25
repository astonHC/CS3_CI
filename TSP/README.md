## Travelling Salesman Problem

## Motive:

The following serves to provide my implememtation for the enigmatic Travelling Sales Problem presented as per the lecture materials within Week 1.

The idea with this introductory algorithm is that it is meant to provide us with an opportunity to be able to become accustomed to new means of Computational Intelligence, to look beyond the looking-glass at how we are able to implement.

This should prove to be fruitful once it comes to contextualisation and comparison betweens various other algorithms.

## What is TSP?

Akin to the likeness of Djisktra's or any other A* searching/path finding, TSP aims to be a quick and modularised implementation of being able to find the quickest path. The scenario is to project the quickest path by which the Salesman is able to get the most out of their sales.
Using Matrix Addition, we are able to create a pseudo-implementation to determine the most viable option in accordance with these parameters:

  - NAME OF CITY
  - X POS
  - Y POS
  - DISTANCE
  - NO. OF CITIES

## Building:

It is just a simple case of running the following within this folder 
```
gcc --std=c99 -pedantic main.c tsp.c -o tsp

./tsp
