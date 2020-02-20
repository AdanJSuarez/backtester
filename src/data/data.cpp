#include "data.h"
#include <vector>
#include <math.h>

/*
Default constuctor, we don't initialize with data.
*/
Data::Data(RawData& rawData){
    Data::transformRawData(rawData);
};

std::vector<DataLine> Data::getData() {
    return m_data;
}

/*
Documentation should go here for this method.
*/
void Data::transformRawData(RawData& rawData){

    std::vector<RawDataLine> rawDataData = rawData.m_rawData;
    // TODO:
    int range_size {10};
    for (int i = 0; i <= ceil(rawDataData.size()/range_size); i++){
        int index = i * range_size;
        // Select range size.
        std::vector<RawDataLine> subVector {selectRange(rawDataData, index, index+range_size - 1)};
        // Calculate and set high, low, open, close.
        DataLine dataLine {setOHLCV(subVector)};
        // Store them as dataLine in m_data
        m_data.push_back(dataLine);
    }

    // Keep processing until get the last "range size" or less.

}

/*
* Return a subVector selected between indexStart and indexEnd.
* it don't modify vector.
*/
std::vector<RawDataLine> Data::selectRange (const std::vector<RawDataLine>& vector, int indexStart = 0, int indexEnd = 9) {
    // Avoid out of range indexEnd
    if (vector.begin() + indexEnd > vector.end()) {
        // This should not work because it is returning an pointer not an int.
        indexEnd = vector.end() - (vector.begin() + indexStart);
    }
    std::vector<RawDataLine> subVector (vector.begin() + indexStart, vector.begin() + indexEnd);
    return subVector;
}
/*
Return a Dataline with OHLCV set.
*/
DataLine Data::setOHLCV(const std::vector<RawDataLine>& subVector) {
    int timestamp {subVector[0].m_timeStamp};
    double high {subVector[0].m_price};
    double low {subVector[0].m_price};
    double open {subVector[0].m_price};
    double close {subVector[subVector.size() - 1].m_price};
    double volume {subVector[0].m_volume};
    for (RawDataLine line: subVector) {
         if(line.m_price > high) {
             high = line.m_price;
         };
         if(line.m_price < low) {
             low = line.m_price;
         }
         volume += line.m_volume;
    DataLine result {timestamp, high, low, open, close, volume};
    return result;
    }
}
