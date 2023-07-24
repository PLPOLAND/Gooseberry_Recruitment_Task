#include <iostream>
#include <random>
#include <vector>
#include "WhiteNoiseGenerator.h"
#include "PinkNoiseGenerator.h"
#include "BrownNoiseGenerator.h"
#include "VelvetNoiseGenerator.h"
#include "NoiseToCSVWriter.h"

#define TIME 1.0
#define SAMPLE_RATE 44100



int main( int argc, char* argv[]) {
    size_t samples = TIME * SAMPLE_RATE;

    PinkNoiseGenerator pinkNoiseGenerator;
    BrownNoiseGenerator brownNoiseGenerator;
    VelvetNoiseGenerator valvetNoiseGenerator;
    pinkNoiseGenerator.generateNoiseData(samples);
    brownNoiseGenerator.generateNoiseData(samples);
    valvetNoiseGenerator.generateNoiseData(samples, 2000, SAMPLE_RATE);
    
    NoiseToCSVWriter noiseToCSVWriter;
    noiseToCSVWriter.addData("pink", pinkNoiseGenerator.getNoiseData());
    noiseToCSVWriter.addData("brown", brownNoiseGenerator.getNoiseData());
    noiseToCSVWriter.addData("valvet", valvetNoiseGenerator.getNoiseData());
    noiseToCSVWriter.writeData("noise.csv");

    return 0;
}
