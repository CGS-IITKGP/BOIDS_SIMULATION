#include "particle.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

Boid boid_array[MAX_PARTICLES];  
BoidNeighbor boid_neighbors[MAX_PARTICLES][MAX_PARTICLES];
int boid_neighbor_count[MAX_PARTICLES];
BoidNeighbor boid_protected_neighbors[MAX_PARTICLES][MAX_PARTICLES];
int boid_protected_neighbors_count[MAX_PARTICLES];

void make(){
    float rand_angle;
    for (int i = 0; i < MAX_PARTICLES; i++) {
        boid_array[i].pos = {
            static_cast<float>(rand() % SCREEN_WIDTH),
            static_cast<float>(rand() % SCREEN_HEIGHT)
        };
    rand_angle = static_cast<float>((rand() % 360) * DEG2RAD);
    boid_array[i].vel = { VELOCITY * cosf(rand_angle), VELOCITY * sinf(rand_angle) };
        // to check velocities
        // std :: cout<< boid_array[i].vel.x << boid_array[i].vel.y << std :: endl;
    }
}



void raycast(Boid boid_array[], BoidNeighbor boid_neighbors[][MAX_PARTICLES], int boid_neighbor_count[],BoidNeighbor boid_protected_neighbors[][MAX_PARTICLES],int boid_protected_neighbors_count[]) {
    int i,j,k,l;
    for (i = 0; i < MAX_PARTICLES; i++) {
        k = 0;
        l =0;
            // For visualization of raycast
        

            // float angle = atan2f(boid_array[i].vel.y, boid_array[i].vel.x);
            // float deg = angle * RAD2DEG;
            // float fov = ANGLE_IN_RADIANS*RAD2DEG;

            // DrawCircleSector(boid_array[i].pos, RADIUS_OF_VISION,deg - fov, deg + fov, 30, GREEN);

            
        for (j = 0; j < MAX_PARTICLES; j++) {
            if (i == j) continue;
            Vector2 direction = getDirection(boid_array[i].pos, boid_array[j].pos);
            float angle_to_j = atan2f(direction.y, direction.x);
            float angle_diff = atan2f(sinf(angle_to_j - boid_array[i].angle), cosf(angle_to_j - boid_array[i].angle));
            float dist_sqr = Vector2LengthSqr(direction);

            if (dist_sqr < RADIUS_OF_VISION_SQR && fabs(angle_diff) <= ANGLE_IN_RADIANS) {
                boid_neighbors[i][k].ref = &boid_array[j];
                boid_neighbors[i][k].direction = direction;
                boid_neighbors[i][k].distance = sqrtf(dist_sqr);
                k++;
            }
        }

        boid_neighbor_count[i] = k;

        for( j = 0; j<k;j++)
        {
            Vector2 direction = getDirection(boid_array[i].pos, boid_array[j].pos);
            float angle_to_j = atan2f(direction.y, direction.x);
            float angle_diff = atan2f(sinf(angle_to_j - boid_array[i].angle), cosf(angle_to_j - boid_array[i].angle));
            float dist_sqr = Vector2LengthSqr(direction);

            if (dist_sqr < RADIUS_OF_VISION_PROTECTED_SQR && fabs(angle_diff) <= ANGLE_IN_RADIANS) {
                boid_neighbors[i][k].ref = &boid_array[j];
                boid_neighbors[i][k].direction = direction;
                boid_neighbors[i][k].distance = sqrtf(dist_sqr);
                l++;
            }
            
        }       
        
        
        for( j = l; j<MAX_PARTICLES;j++)
        {
            boid_neighbors[i][j] = {};
        }
        for( j = k; j<MAX_PARTICLES;j++)
        {
            boid_protected_neighbors[i][j] = {};
        }
    }
}

void print_boids_in_neighborhood(Boid boid_array[], BoidNeighbor boid_neighbors[][MAX_PARTICLES], int boid_neighbor_count[])
{
        for (int i = 0; i < MAX_PARTICLES; i++) 
        {

                std :: cout <<  " size: " << i << "  "<<  boid_neighbor_count[i] << std :: endl;
            
        }
}

Vector2 getDirection(Vector2 from, Vector2 to)
{
    return  Vector2Normalize(Vector2Subtract(to,from));
}



