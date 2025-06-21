#include "allignment.h"
#include <raymath.h>

void allignment(Boid boid_array[], BoidNeighbor boid_neighbors[][MAX_PARTICLES], int boid_neighbor_count[]) {


    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (boid_neighbor_count[i] == 0) continue;

        Vector2 avg_vel = {0, 0};
        int count = 0;

        for (int j = 0; j < boid_neighbor_count[i]; j++) {
            Boid* neighbor = boid_neighbors[i][j].ref;
            if (neighbor == nullptr) continue;
            avg_vel = Vector2Add(avg_vel, neighbor->vel);
            count++;
        }

        if (count > 0) {
            avg_vel = Vector2Scale(avg_vel, 1.0f / count);

            Vector2 steering = Vector2Subtract(avg_vel, boid_array[i].vel);

            boid_array[i].vel = Vector2Add(boid_array[i].vel, steering*ALLIGNMENT_FACTOR);

        }
    }
}