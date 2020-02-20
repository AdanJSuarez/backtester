#include "data.h"
#include <vector>
#include <math.h>
#include <iostream>

/**
 * @brief  Default constuctor, we don't initialize with data.
 * @note
 * @param  rawData: RawData
 * @param  range_size: int
 * @retval Constructor
 */
Data::Data(RawData& rawData, int range_size = 10){
    Data::transformRawData(rawData, range_size);
};
/**
 * @brief  Return m_data
 * @note
 * @retval vetor<DataLine>
 */
std::vector<DataLine> Data::getData() {
    return m_data;
}
/**
 * @brief  Documentation should go here for this method.
 * @note
 * @param  rawData:
 * @param  range_size:
 * @retval None
 */
void Data::transformRawData(RawData& rawData, int range_size){
    std::vector<RawDataLine> rawDataData = rawData.m_rawData;
    for (int i = 0; i <= ceil(int(rawDataData.size())/range_size); i++){
        int index = i * range_size;
        // Select range size.
        std::vector<RawDataLine> subVector {selectRange(rawDataData, index, index + range_size)};
        // Calculate and set high, low, open, close.
        DataLine dataLine {setOHLCV(subVector)};
        // Store them as dataLine in m_data
        m_data.push_back(dataLine);
    }
}
/**
 * @brief  Return a subVector selected between indexStart and indexEnd.
 * @note   It don't modify vector.
 * @param  vector: std::vector<RawDataLine>
 * @param  indexStart: int
 * @param  indexEnd: int
 * @retval std::vector<RawDataLine>
 */
std::vector<RawDataLine> Data::selectRange (const std::vector<RawDataLine>& vector, int indexStart = 0, int indexEnd = 10) {
    // Avoid out of range indexEnd
    if (indexEnd > int(vector.size())) {
        indexEnd = vector.size();
    }
    std::vector<RawDataLine> subVector (vector.begin() + indexStart, vector.begin() + indexEnd);
    return subVector;
}
/**
 * @brief  Return a Dataline with OHLCV set.
 * @note
 * @param  subVector: std::vector<RawDataLine>
 * @retval DataLine
 */
DataLine Data::setOHLCV(const std::vector<RawDataLine>& subVector) {
    int timestamp {subVector[0].m_timeStamp};
    double high {subVector[0].m_price};
    double low {subVector[0].m_price};
    double open {subVector[0].m_price};
    double close {subVector[subVector.size() - 1].m_price};
    double volume {0};
    for (RawDataLine line: subVector) {
        if(line.m_price > high) {
            high = line.m_price;
        };
        if(line.m_price < low) {
            low = line.m_price;
        }
        volume += line.m_volume;
    }
    DataLine result {timestamp, high, low, open, close, volume};
    return result;
}
