//
//  Gaussian.cpp
//  NoiseFields
//
//  Created by Sam Ludford on 23/01/2018.
//

#include "Gaussian.h"

// code from: https://quentinmckay.wordpress.com/2010/06/01/simple-gaussian-openframeworks/

float Gaussian::randomNormal() {
    return sqrt(-2*log(randomUniform())) * cos(2*M_PI*randomUniform());
}

float Gaussian::randomUniform() {
    return (rand()+1.0)/(RAND_MAX+1.0);
}

