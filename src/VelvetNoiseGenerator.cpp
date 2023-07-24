#include "VelvetNoiseGenerator.h"

VelvetNoiseGenerator::VelvetNoiseGenerator()
{

}

VelvetNoiseGenerator::~VelvetNoiseGenerator()
{

}

/// \brief Generates valvet noise data, default pulse density = 2000, default sample rate = 44100
/// \see generateNoiseData(size_t howManySamples, unsigned int pulseDensity, unsigned int sampleRate)
std::vector<double> VelvetNoiseGenerator::generateNoiseData(size_t howManySamples)
{
    return this->generateNoiseData(howManySamples, 2000, 44100);
}

/// \brief Generates valvet noise data
/// \see https://www.researchgate.net/publication/260701331_A_Perceptual_Study_on_Velvet_Noise_and_Its_Variants_at_Different_Pulse_Densities
std::vector<double> VelvetNoiseGenerator::generateNoiseData(size_t howManySamples, unsigned int pulseDensity, unsigned int sampleRate)
{
    //data
    std::vector<double> tmpNoiseData(howManySamples);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    

    for_each(tmpNoiseData.begin(), tmpNoiseData.end(), [](double& d) {
        d = 0.0;
    }); // initialize all elements to 0.0

    double seconds = (double) howManySamples / sampleRate;
    //m
    int pulseCounter = 0;
    //Td
    double averagePulseDistance = (double)sampleRate / (double) pulseDensity;

    while (pulseCounter < pulseDensity * seconds)// until we have not reached the pulse density
    {
        // kovn(m) = round(m * Td + rand(0,1)*(Td-1));
        unsigned int location = (unsigned int)round(pulseCounter * averagePulseDistance + dis(gen)*(averagePulseDistance -1));
        if (location >= howManySamples)
        {
            //if the location is out of range, we skip this iteration
            continue;
        }
        tmpNoiseData[location] = 2 * round(dis(gen)) - 1;
        pulseCounter++;
    }

    this->noiseData = tmpNoiseData;// copy the data to the member variable
    
    return this->getNoiseData();
}


