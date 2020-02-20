#include "loadData.h"
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <iostream>

/*
Get a (read) file and store it in m_fileName as rawData.
*/
LoadData::LoadData(std::string fileName) {
    m_fileName = fileName;
    std::string line;
    std::vector<std::string> container;
    RawDataLine rawLine;
    std::ifstream myFile (fileName);
    if (myFile.is_open()) {
        while(std::getline(myFile, line)) {
            // Filter out lines without comma
            if (line.find(",") != std::string::npos) {
                LoadData::splitLine(container, line);
                LoadData::addVectorToRawData(container, rawLine);
                m_rawData.m_rawData.push_back(rawLine);
            }
        }
        myFile.close();
    } else {
        std::cerr << "- Error: Unable to open the file!" << "\n";
    };
};

RawData LoadData::getData() {
    return m_rawData;
};
/*
Returns a vector of strings when split a string separated by commas(,)
*/
void LoadData::splitLine(std::vector<std::string>& container, std::string& line) {
    boost::split(container, line, boost::is_any_of(","));
}
/*
Add data from each line to RawDataLine struct.
*/
void LoadData::addVectorToRawData(const std::vector<std::string>& container, RawDataLine& rawLine) {
    rawLine.m_timeStamp = std::stoi(container[0]);
    rawLine.m_price = std::stod(container[1]);
    rawLine.m_volume = std::stod(container[2]);
};
