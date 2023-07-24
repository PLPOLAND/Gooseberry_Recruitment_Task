#include "NoiseToCSVWriter.h"

NoiseToCSVWriter::NoiseToCSVWriter()
{

}

NoiseToCSVWriter::~NoiseToCSVWriter()
{

}

void NoiseToCSVWriter::addData(std::string name,const  std::vector<double> data)
{
    std::vector<double>* tempData = new std::vector<double>(data);
    this->mapData(tempData, -1.0, 1.0, 0.0, 255.0);
    this->data.push_back(std::make_pair(name, tempData));
}

void NoiseToCSVWriter::writeData(std::string filename)
{
    csvWriter.enableAutoNewRow( data.size() );

    std::ofstream file;
    file.open(filename);
    for (long unsigned int i = 0; i < data.size(); i++) { // print header
        csvWriter<<data[i].first;
    }
    // csvWriter.newRow();
    size_t max_size = 0; // find max size of data
    for (long unsigned int i = 0; i < data.size(); i++) {
        if (data[i].second->size() > max_size) {
            max_size = data[i].second->size();
        }
    }

    for (long unsigned int j = 0; j < data[0].second->size(); j++) {
        for (long unsigned int i = 0; i < data.size(); i++) {
            if (j >= data[i].second->size())
            {
                csvWriter<<0;
            }
            
            csvWriter<<(int)round(data[i].second->at(j));
        }
        // csvWriter.newRow();
    }
    file << csvWriter;
    file.close();
    
}

void NoiseToCSVWriter::mapData(std::vector<double>* data, double minIn, double maxIn, double outMin, double outMax)
{
    double min = *std::min_element(data->begin(), data->end());
    double max = *std::max_element(data->begin(), data->end());
    for (long unsigned int i = 0; i < data->size(); i++) {
        (*data)[i] = (outMax - outMin) * ((*data)[i] - min) / (max - min) + outMin;
    }
}
