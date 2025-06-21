#include "seperation.h"
#include <raymath.h>


void seperation(Boid boid_array[], BoidNeighbor boid_neighbors[][MAX_PARTICLES], int boid_neighbor_count[],BoidNeighbor boid_protected_neighbors[][MAX_PARTICLES],int boid_protected_neighbors_count[])
{
    Vector2 steering;
    for (int i = 0; i < MAX_PARTICLES; i++) 
    {
        steering = {0,0};
        if (boid_protected_neighbors_count[i] == 0) continue;
        for (int j = 0; j < boid_protected_neighbors_count[i]; j++) 
        {
            Boid* neighbor = boid_protected_neighbors[i][j].ref;
            if (neighbor == nullptr) continue;
            steering = Vector2Add( steering ,Vector2Subtract( boid_array[i].pos , neighbor->pos));
            
            boid_array[i].vel = Vector2Add(boid_array[i].vel,Vector2Scale(steering,SEPERATION_FACTOR));
        }

    }
    
}

