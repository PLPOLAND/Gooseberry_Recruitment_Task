#include <iostream>
#include <random>
#include <vector>
#include "WhiteNoiseGenerator.h"
#include "PinkNoiseGenerator.h"
#include "BrownNoiseGenerator.h"
#include "VelvetNoiseGenerator.h"
#include "NoiseToCSVWriter.h"

// in seconds
#define TIME 1.0 
// in Hz
#define SAMPLE_RATE 44100 
// for velvet noise generator; how many pulses per second
#define PULSE_DENSITY 2000 


///\brief Main function
///\author Marek Pałdyna
int main( int argc, char* argv[]) {
    size_t samples = TIME * SAMPLE_RATE;

    PinkNoiseGenerator pinkNoiseGenerator;
    BrownNoiseGenerator brownNoiseGenerator;
    VelvetNoiseGenerator valvetNoiseGenerator;
    pinkNoiseGenerator.generateNoiseData(samples);
    brownNoiseGenerator.generateNoiseData(samples);
    valvetNoiseGenerator.generateNoiseData(samples, PULSE_DENSITY, SAMPLE_RATE);
    
    NoiseToCSVWriter noiseToCSVWriter;
    noiseToCSVWriter.addData("pink", pinkNoiseGenerator.getNoiseData());
    noiseToCSVWriter.addData("brown", brownNoiseGenerator.getNoiseData());
    noiseToCSVWriter.addData("velvet", valvetNoiseGenerator.getNoiseData());
    noiseToCSVWriter.writeData("pink_brown_velvet_noise_data.csv");

    return 0;
}
