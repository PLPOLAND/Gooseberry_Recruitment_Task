#ifndef VALVETNOISEGENERATOR_H
#define VALVETNOISEGENERATOR_H

#include <vector>
#include <random>
#include <algorithm>
#include "NoiseGenerator.h"

///\brief A class that generates valvet noise data
class VelvetNoiseGenerator: public NoiseGenerator
{
public:
    VelvetNoiseGenerator();
    ~VelvetNoiseGenerator();

    std::vector<double> generateNoiseData(size_t howManySamples);
    std::vector<double> generateNoiseData(size_t howManySamples, unsigned int pulseDensity, unsigned int sampleRate);

private:
};

#endif