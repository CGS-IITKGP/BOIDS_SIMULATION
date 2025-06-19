#pragma once

#include <iostream>
#include <raylib.h>
#include <raymath.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int RADIUS_OF_VISION = 50;
const float ANGLE_IN_RADIANS = (150.0f/360.0f)*PI;
const int RADIUS_OF_VISION_SQR = RADIUS_OF_VISION*RADIUS_OF_VISION ;
const int VELOCITY = 6;
const int MAX_PARTICLES =6;


// Forward declarations
struct Boid;
struct BoidNeighbor;

extern Boid boid_array[MAX_PARTICLES];  // ✅ extern, not definition
extern BoidNeighbor boid_neighbors[MAX_PARTICLES][MAX_PARTICLES];
extern int boid_neighbor_count[MAX_PARTICLES];


class Boid {
public:

    float total_vel;
    Vector2 pos;
    Vector2 vel;
    Vector2 force = {0, 0};
    float angle;
    void update() {
        
        pos.x += vel.x + 0.5f * force.x;
        vel.x += force.x;

        pos.y += vel.y + 0.5f * force.y;
        vel.y += force.y;
        angle = atan2f(vel.y, vel.x);
        
        if (pos.x < 0) pos.x += SCREEN_WIDTH;
        if (pos.x > SCREEN_WIDTH) pos.x -= SCREEN_WIDTH;
        if (pos.y < 0) pos.y += SCREEN_HEIGHT;
        if (pos.y > SCREEN_HEIGHT) pos.y -= SCREEN_HEIGHT;
        force = {0, 0};

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



void make();
void raycast(Boid boid_array[], BoidNeighbor boid_neighbors[][MAX_PARTICLES], int boid_neighbor_count[]);
void print_boids_in_neighborhood(Boid boid_array[], BoidNeighbor boid_neighbors[][MAX_PARTICLES], int boid_neighbor_count[]);
Vector2 getDirection(Vector2 from, Vector2 to);