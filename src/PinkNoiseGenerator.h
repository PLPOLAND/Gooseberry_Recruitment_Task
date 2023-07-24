#ifndef PINKNOISEGENERATOR_H
#define PINKNOISEGENERATOR_H

#include <vector>
#include <random>
#include <algorithm>
#include "WhiteNoiseGenerator.h"

class PinkNoiseGenerator : public WhiteNoiseGenerator
{
public:
    PinkNoiseGenerator();
    ~PinkNoiseGenerator();

    std::vector<double> generateNoiseData(size_t howManySamples);

    std::vector<double> generateNoiseDataWithNormalDistribution( size_t howManySamples );

private:
    std::vector<double> makePinkNoise( std::vector<double>& whiteNoiseData );
};

#endif