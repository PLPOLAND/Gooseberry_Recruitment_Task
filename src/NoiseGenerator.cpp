#include "NoiseGenerator.h"

NoiseGenerator::NoiseGenerator()
{

}

NoiseGenerator::~NoiseGenerator()
{

}

///\brief Returns the noise data or empty vector if no noise data wasn't generated yet
///\return A vector of doubles containing the noise data / empty vector 
std::vector<double> NoiseGenerator::getNoiseData() const
{
    return this->noiseData;
}
