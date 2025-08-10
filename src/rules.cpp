#include "rules.h"
#include <raymath.h>

void cohesion(Boid boid_array[],BoidNeighbor boid_neighbors[][MAX_PARTICLES],int boid_neighbour_count[])
{
    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (boid_neighbor_count[i] == 0) continue;

        Vector2 avg_pos = {0, 0};
        int count = 0;

        for (int j = 0; j < boid_neighbor_count[i]; j++) {
            Boid* neighbor = boid_neighbors[i][j].ref;
            if (neighbor == nullptr) continue;
            avg_pos = Vector2Add(avg_pos, neighbor->pos);
            count++;
        }

        if (count > 0) {
            avg_pos = Vector2Scale(avg_pos, 1.0f / count);

            Vector2 steering = Vector2Subtract(avg_pos, boid_array[i].pos);

            boid_array[i].vel = Vector2Add(boid_array[i].vel, steering*COHESION_FACTOR);

        }
    }

}


void seperation(Boid boid_array[], BoidNeighbor boid_neighbors[][MAX_PARTICLES], int boid_neighbor_count[], BoidNeighbor boid_protected_neighbors[][MAX_PARTICLES], int boid_protected_neighbors_count[]) {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        Vector2 steering = { 0, 0 };

        for (int j = 0; j < boid_protected_neighbors_count[i]; j++) {
            Boid* neighbor = boid_protected_neighbors[i][j].ref;
            Vector2 diff = Vector2Subtract(boid_array[i].pos, neighbor->pos);
            float dist = Vector2Length(diff);

            if (dist != 0) {
                Vector2 repulse = Vector2Scale(diff, 1.0f / (dist * dist)); // Stronger repulsion for closer neighbors
                steering = Vector2Add(steering, repulse);
            }
        }

        // Apply scaled separation force
        boid_array[i].vel = Vector2Add(boid_array[i].vel, Vector2Scale(steering, SEPERATION_FACTOR));
    }
}

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