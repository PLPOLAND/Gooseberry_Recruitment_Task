#include "PinkNoiseGenerator.h"

PinkNoiseGenerator::PinkNoiseGenerator()
{

}

PinkNoiseGenerator::~PinkNoiseGenerator()
{

}

///\brief Generates pink noise data using the Paul Kellet's refined method 
///\return A vector of doubles containing the pink noise data
std::vector<double> PinkNoiseGenerator::generateNoiseData(size_t howManySamples)
{
    WhiteNoiseGenerator::generateNoiseData(howManySamples);
    makePinkNoise(this->noiseData);
    return this->getNoiseData();
}

///\brief Generates pink noise data using the Paul Kellet's refined method
///\return A vector of doubles containing the pink noise data
///\see https://www.firstpr.com.au/dsp/pink-noise/
std::vector<double> PinkNoiseGenerator::generateNoiseDataWithNormalDistribution(size_t howManySamples)
{
    WhiteNoiseGenerator::generateNoiseDataWithNormalDistribution(howManySamples);
    makePinkNoise(this->noiseData);
    return this->getNoiseData();
}

///\brief Generates pink noise data using the Paul Kellet's refined method and the given white noise data
std::vector<double> PinkNoiseGenerator::makePinkNoise(std::vector<double>& whiteNoiseData)
{
    double b0 = 0.0;
    double b1 = 0.0;
    double b2 = 0.0;
    double b3 = 0.0;
    double b4 = 0.0;
    double b5 = 0.0;
    double b6 = 0.0;

    for (size_t i = 0; i < this->noiseData.size(); i++)
    {
        double white = this->noiseData[i];
        b0 = 0.99886 * b0 + white * 0.0555179;
        b1 = 0.99332 * b1 + white * 0.0750759;
        b2 = 0.96900 * b2 + white * 0.1538520;
        b3 = 0.86650 * b3 + white * 0.3104856;
        b4 = 0.55000 * b4 + white * 0.5329522;
        b5 = -0.7616 * b5 - white * 0.0168980;
        double output = b0 + b1 + b2 + b3 + b4 + b5 + b6 + white * 0.5362;
        output *= 0.11; // compensation to make the output not too high
        b6 = white * 0.115926;
        this->noiseData[i] = output;
    }
    
    return this->noiseData;
}
