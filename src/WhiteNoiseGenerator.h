#ifndef WHITENOISEGENERATOR_H
#define WHITENOISEGENERATOR_H

#include <vector>
#include <random>
#include <algorithm>
#include "NoiseGenerator.h"

class WhiteNoiseGenerator : public NoiseGenerator
{
public:
    WhiteNoiseGenerator();
    ~WhiteNoiseGenerator();


    std::vector<double> generateNoiseData(size_t howManySamples);

    std::vector<double> generateNoiseDataWithNormalDistribution( size_t howManySamples );

private: 
};

#endif