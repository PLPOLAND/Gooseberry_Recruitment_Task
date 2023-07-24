#include "BrownNoiseGenerator.h"

BrownNoiseGenerator::BrownNoiseGenerator()
{

}

BrownNoiseGenerator::~BrownNoiseGenerator()
{

}

/// \brief Generate brown noise data with white noise data with uniform distribution of random values
std::vector<double> BrownNoiseGenerator::generateNoiseData(size_t howManySamples)
{
    WhiteNoiseGenerator::generateNoiseData(howManySamples);
    generateNoiseData(this->noiseData);
    return this->getNoiseData();
}

/// \brief Generate brown noise data with white noise data with normal distribution of random values
std::vector<double> BrownNoiseGenerator::generateNoiseDataWithNormalDistribution(size_t howManySamples)
{
    WhiteNoiseGenerator::generateNoiseDataWithNormalDistribution(howManySamples);
    generateNoiseData(this->noiseData);
    return this->getNoiseData();
}

/// \brief Generate brown noise data 
/// \see https://noisehack.com/generate-noise-web-audio-api/
void BrownNoiseGenerator::generateNoiseData(std::vector<double>& data)
{
    double lastOut = 0.0;

    for (size_t i = 0; i < data.size(); i++)
    {
        double white = getNoiseData()[i];
        double output = (lastOut + (0.02 * white)) / 1.02;
        lastOut = output;
        output *= 1.5; // (roughly) compensate for gain
        this->noiseData[i] = output;
    }
}
