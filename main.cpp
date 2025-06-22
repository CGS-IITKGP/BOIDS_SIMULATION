#include <iostream>
#include <raylib.h>
#include "particle.h"
#include "rules.h"
#include <cstdlib>
#include <raymath.h>


int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Boids Simulation");
    SetTargetFPS(60);
    make();

    while (!WindowShouldClose()) {
        raycast(boid_array, boid_neighbors, boid_neighbor_count,boid_protected_neighbors,boid_protected_neighbors_count);

        BeginDrawing();
        ClearBackground(BLACK);

        // allignment(boid_array, boid_neighbors, boid_neighbor_count);

        seperation(boid_array, boid_neighbors, boid_neighbor_count,boid_protected_neighbors,boid_protected_neighbors_count);

        // cohesion(boid_array, boid_neighbors, boid_neighbor_count);



        // print_boids_in_neighborhood(boid_array, boid_neighbors, boid_neighbor_count);
        print_boids_in_neighborhood_protected(boid_array,boid_protected_neighbors_count);
        for (int i = 0; i < MAX_PARTICLES; i++) {
            boid_array[i].draw();
            boid_array[i].update();
            
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}