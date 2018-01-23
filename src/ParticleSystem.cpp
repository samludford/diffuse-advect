//
//  ParticleSystem.cpp
//  NoiseFields
//
//  Created by Sam Ludford on 23/01/2018.
//

#include "ParticleSystem.h"

const float ParticleSystem::max_speed = 0.1f;

ParticleSystem::ParticleSystem() {}

void ParticleSystem::update() {
    
    // each frame emit some new particles
    for(int i=0 ; i < this->gen ; i++) {
        
        // all particles start at the center
        ofVec3f pos;
        
        // calculate initial velocities based on a normal distribution
        float r = ofMap( Gaussian::randomNormal(), 0, 1, -max_speed, max_speed );
        ofVec3f vel = ofVec3f(r,r,r);
        
        particles.push_front(new Particle( pos, vel ));
    }
    
    // when the total number of particles exceeds capacity, remove the oldest ones
    if(particles.size() > capacity) {
        for(int i=0 ; i < gen ; i++) {
            particles.pop_back();
        }
    }
    
    for(int i=0 ; i < particles.size() ; i++) {
        particles[i]->update();
    }
    
}

void ParticleSystem::draw() {
    ofPushMatrix();
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(1);
    for(int i=0 ; i < particles.size() ; i++) {
        ofVec3f p = particles[i]->getPosition();
        mesh.addVertex(p);
    }
    mesh.drawVertices();
    ofPopMatrix();
}


