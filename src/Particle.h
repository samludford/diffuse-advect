//
//  Particle.h
//  NoiseFields
//
//  Created by Sam Ludford on 23/01/2018.
//

#pragma once

#include "ofMain.h"

class Particle {
    
    public:
    
        Particle(ofVec3f _pos, ofVec3f _vel);
        Particle();
    
        void update();
    
        ofVec3f getPosition();
    
        static const float max_dist;

    protected:
    
        ofVec3f pos;
        ofVec3f vel;
 
};
