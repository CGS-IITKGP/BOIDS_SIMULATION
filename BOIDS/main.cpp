#include <iostream>
#include <raylib.h>
#include "particle.h"
#include <cstdlib>
#include <ctime>



int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Boid Test");
    SetTargetFPS(60);
    srand(time(NULL));
    make();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < MAX_PARTICLES; i++) {
            boid_array[i].update();
            boid_array[i].draw();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}