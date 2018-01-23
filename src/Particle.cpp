//
//  Particle.cpp
//  NoiseFields
//
//  Created by Sam Ludford on 23/01/2018.
//

#include "Particle.h"

const float Particle::max_dist = 20000.0f;

Particle::Particle() {
    this->pos = ofVec3f(0.0,0.0,0.0);
    this->vel = ofVec3f(0.0,0.0,0.0);
}

Particle::Particle(ofVec3f _pos, ofVec3f _vel) {
    this->pos = _pos;
    this->vel = _vel;
}

void Particle::update() {
    
    
    // get distance of particle from center
    // (slow operation - do I need true value?)
//    float dist = pos.length();
    float dist = pos.lengthSquared();
    
    // normalise
    dist = ofMap(dist,0,max_dist,0,1);
    
    // update particle velocity based on a time-evolving vector field
    // vector field determined by noise (using position as input), with scale factors evolving with time
    // (and in one case distance from center, for tentacular wiggling)
    
    float slowness = 1.2;
    
    vel.x += 0.01 * cos (slowness * TWO_PI * ofNoise(0.2 * pos.x, 1.5 * pos.y, 0.01 * pos.z));
    
    vel.y += dist * 2 * ofMap(ofNoise(0.1 * pos.x, ofNoise(ofGetFrameNum()/200.0) * 1.5 * pos.y, sin(slowness * TWO_PI * ofGetFrameNum()/300.0) * 0.2 * pos.z),0,1,-1,1);
    
    vel.z += 0.08*ofMap(ofNoise(ofNoise(ofGetFrameNum()/100.0) * 0.9 * pos.x, vel.y * 0.1 * pos.y, 0.4 * pos.z),0,1,-1,1);
    
    //velocity adjustment (the further a particle is from the center, the more it gets pulled back):
    // get the vector from particle to position (i.e. position * -1)
    ofVec3f center_v = pos;
    center_v *= -1;
    
    // lerp velocity it towards the center
    vel.interpolate(center_v, dist);
    
    pos += vel;
    
}

ofVec3f Particle::getPosition() {
    return this->pos;
}
