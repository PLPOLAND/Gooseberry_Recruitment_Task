#ifndef NOISECSVWRITER_H
#define NOISECSVWRITER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../lib/CSVWriter.h"

///\brief Class for writing noise data to a csv file 
class NoiseToCSVWriter
{
public:
    NoiseToCSVWriter();
    ~NoiseToCSVWriter();

    void addData(std::string name, const std::vector<double> data);
    void writeData(std::string filename);

private:
    std::vector<std::pair<std::string, std::vector<double>*>> data;
    CSVWriter* csvWriter;


    void mapData(std::vector<double>* data, double minIn, double maxIn, double outMin, double outMax);
};

#endif