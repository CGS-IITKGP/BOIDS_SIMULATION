#ifndef PARTICLE_H
#define PARTICLE_H

#include <raylib.h>
#include <raymath.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int RADIUS_OF_VISION = 40;
const int ANGLE_IN_DEGREES = 150;
#define MAX_PARTICLES  50


class Boid {
public:

    Vector2 pos;
    Vector2 vel = {5, 5};
    Vector2 force = {0, 0};

    void update() {
        pos.x += vel.x + 0.5f * force.x;
        vel.x += force.x;

        pos.y += vel.y + 0.5f * force.y;
        vel.y += force.y;

        // Optional: bounce off walls
        if (pos.x < 0) pos.x += SCREEN_WIDTH;
        if (pos.x > SCREEN_WIDTH) pos.x -= SCREEN_WIDTH;
        if (pos.y < 0) pos.y += SCREEN_HEIGHT;
        if (pos.y > SCREEN_HEIGHT) pos.y -= SCREEN_HEIGHT;

    }

void draw() {
    // Triangle shape pointing in +X (local space)
    float base = 14.0f;
    float height = 10.0f;

    Vector2 p1 = {  base / 2.0f, 0 };               // tip (pointing right)
    Vector2 p2 = { -base / 2.0f, -height / 2.0f };  // bottom left
    Vector2 p3 = { -base / 2.0f,  height / 2.0f };  // top left

    // Get angle from velocity
    float angle = atan2f(vel.y, vel.x);  // radians

    // Rotate each point and translate to pos
    Vector2 tip    = Vector2Add(pos, Vector2Rotate(p1, angle));
    Vector2 left   = Vector2Add(pos, Vector2Rotate(p2, angle));
    Vector2 right  = Vector2Add(pos, Vector2Rotate(p3, angle));

    DrawTriangle(tip, left, right, WHITE);
}
};



Boid boid_array[MAX_PARTICLES];
Boid boid_in_range[MAX_PARTICLES][MAX_PARTICLES];


void make(){
    for (int i = 0; i < MAX_PARTICLES; i++) {
        boid_array[i].pos = {
            static_cast<float>(rand() % SCREEN_WIDTH),
            static_cast<float>(rand() % SCREEN_HEIGHT)
        };

    }
}
#endif

