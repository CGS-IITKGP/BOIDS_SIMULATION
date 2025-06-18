#ifndef PARTICLE_H
#define PARTICLE_H

#include <raylib.h>
#include "raymath.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int RADIUS_OF_VISION = 100;
const float ANGLE_IN_RADIANS = (150.0f/360.0f)*PI;
const int RADIUS_OF_VISION_SQR = RADIUS_OF_VISION*RADIUS_OF_VISION  ;
#define MAX_PARTICLES  10


class Boid {
public:

    Vector2 pos;
    Vector2 vel = {5, 5};
    Vector2 force = {0, 0};
    float angle;
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
    
    float base = 14.0f;
    float height = 10.0f;

    Vector2 p1 = {  base / 2.0f, 0 };               
    Vector2 p2 = { -base / 2.0f, -height / 2.0f };  
    Vector2 p3 = { -base / 2.0f,  height / 2.0f };  

    // Get angle from velocity
     angle = atan2f(vel.y, vel.x);  // radians

    // Rotate each point and translate to pos
    Vector2 tip    = Vector2Add(pos, Vector2Rotate(p1, angle));
    Vector2 left   = Vector2Add(pos, Vector2Rotate(p2, angle));
    Vector2 right  = Vector2Add(pos, Vector2Rotate(p3, angle));

    DrawTriangle(tip, left, right, WHITE);
}
};

struct BoidNeighbor {
    Boid* ref;           
    Vector2 direction;   
    float distance;      
};


Boid boid_array[MAX_PARTICLES];
BoidNeighbor boid_neighbors[MAX_PARTICLES][MAX_PARTICLES];
int boid_neighbor_count[MAX_PARTICLES];


void make(){
    for (int i = 0; i < MAX_PARTICLES; i++) {
        boid_array[i].pos = {
            static_cast<float>(rand() % SCREEN_WIDTH),
            static_cast<float>(rand() % SCREEN_HEIGHT)
        };

    }
}

void raycast(Boid boid_array[], BoidNeighbor boid_neighbors[][MAX_PARTICLES], int boid_neighbor_count[]) {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        int k = 0;
            //For visualization of raycast
            // float angle = atan2f(boid_array[i].vel.y, boid_array[i].vel.x);
            // float deg = angle * RAD2DEG;
            // float fov = ANGLE_IN_RADIANS*RAD2DEG;

            // DrawCircleSector(boid_array[i].pos, RADIUS_OF_VISION,deg - fov, deg + fov, 30, GREEN);

            // Draw the boid
            
        for (int j = 0; j < MAX_PARTICLES; j++) {
            if (i == j) continue;

            Vector2 direction = Vector2Subtract(boid_array[j].pos, boid_array[i].pos);
            float angle_to_j = atan2f(direction.y, direction.x);
            float angle_diff = atan2f(sinf(angle_to_j - boid_array[i].angle), cosf(angle_to_j - boid_array[i].angle));
            float dist_sqr = Vector2LengthSqr(direction);

            if (dist_sqr < RADIUS_OF_VISION_SQR && fabs(angle_diff) <= ANGLE_IN_RADIANS) {
                boid_neighbors[i][k].ref = &boid_array[j];
                boid_neighbors[i][k].direction = Vector2Normalize(direction);
                boid_neighbors[i][k].distance = sqrtf(dist_sqr);
                k++;
            }
        }
        boid_neighbor_count[i] = k;
    }
}



#endif

