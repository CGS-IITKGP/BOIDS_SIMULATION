#include <iostream>
#include <raylib.h>
#include "req_files/particle.h"
#include <cstdlib>
#include <ctime>





int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Boids Simulation");
    SetTargetFPS(60);

    make();  // Initialize boids with random positions

    while (!WindowShouldClose()) {
        // Update neighbors
        raycast(boid_array, boid_neighbors, boid_neighbor_count);

        // Update all boids
        for (int i = 0; i < MAX_PARTICLES; i++) {
            boid_array[i].update();
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < MAX_PARTICLES; i++) {

            boid_array[i].draw();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}