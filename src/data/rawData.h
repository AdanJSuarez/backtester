#ifndef BACKTESTER_SRC_DATA_RAWDATA_H
#define BACKTESTER_SRC_DATA_RAWDATA_H
#include <vector>

struct RawDataLine {
    int m_timeStamp = 0;
    double m_price = 0.0;
    double m_volume = 0.0;
};
struct RawData {
    std::vector <RawDataLine> m_rawData;
};

#endif // BACKTESTER_SRC_DATA_DATASTRUCTURES_H
