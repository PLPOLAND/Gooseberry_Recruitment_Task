#include "WhiteNoiseGenerator.h"

WhiteNoiseGenerator::WhiteNoiseGenerator()
{

}

WhiteNoiseGenerator::~WhiteNoiseGenerator()
{

}

/// \brief Generate white noise data with rand()
std::vector<double> WhiteNoiseGenerator::generateNoiseData(size_t howManySamples)
{
    srand((unsigned int) time(NULL)); // set seed for rand()
    this->noiseData.clear();
    for (size_t i = 0; i < howManySamples; i++)
    {
        this->noiseData.push_back(((double)rand() / RAND_MAX)*2 -1);// generate random number between -1 and 1 and push it to the vector
    }
    return getNoiseData();
}

/// \brief Generate white noise data with normal distribution using C++11 random library
std::vector<double> WhiteNoiseGenerator::generateNoiseDataWithNormalDistribution(size_t howManySamples)
{
    this->noiseData.clear();

    std::random_device rd; 
    std::mt19937 generator(rd());

    std::normal_distribution<double> distribution(1,2); // mean = 1, standard deviation = 2
    size_t i = 0;
    while (i < howManySamples)
    {
        double tmpNum = distribution(generator);
        if ( tmpNum >= -1 && tmpNum <= 1) // only accept number between -1 and 1
        {
            this->noiseData.push_back(tmpNum);
            i++;
        }
        else
        {
            continue;
        }
    }
    
    return getNoiseData();
}

