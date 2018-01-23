//
//  ParticleSystem.h
//  NoiseFields
//
//  Created by Sam Ludford on 23/01/2018.
//

#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "Gaussian.h"

class ParticleSystem {
    
    public:
    
        static const float max_speed;
        static const int gen = 1000;         // number of particles created every frame
        static const int capacity = 50000;  // maximum number of particles
    
        ParticleSystem();
        void update();
        void draw();
    
    protected:
    
        deque<Particle*> particles;
    
};
