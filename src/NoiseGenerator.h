#ifndef NOISEGENERATOR_H
#define NOISEGENERATOR_H

#include <vector>
#include <random>
#include <algorithm>


class NoiseGenerator
{
public:
    NoiseGenerator();
    ~NoiseGenerator();
        virtual std::vector<double> generateNoiseData(size_t howManySamples) = 0;

        std::vector<double> getNoiseData() const;

    protected:
        std::vector<double> noiseData;
};

#endif