#ifndef BROWNNOISEGENERATOR_H
#define BROWNNOISEGENERATOR_H

#include <vector>
#include <random>
#include <algorithm>
#include "WhiteNoiseGenerator.h"


class BrownNoiseGenerator : public WhiteNoiseGenerator
{
public:
    BrownNoiseGenerator();
    ~BrownNoiseGenerator();

    std::vector<double> generateNoiseData(size_t howManySamples);

    std::vector<double> generateNoiseDataWithNormalDistribution( size_t howManySamples );

private:
    void generateNoiseData(std::vector<double> &data);
};

#endif