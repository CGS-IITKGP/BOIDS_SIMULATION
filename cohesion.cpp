#include "cohesion.h"
#include "particle.h"

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
