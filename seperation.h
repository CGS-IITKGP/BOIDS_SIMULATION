#pragma once

#include <raylib.h>
#include <raymath.h>
#include "particle.h"


void seperation(Boid boid_array[], BoidNeighbor boid_neighbors[][MAX_PARTICLES], int boid_neighbor_count[],BoidNeighbor boid_protected_neighbors[][MAX_PARTICLES],int boid_protected_neighbors_count[]);


