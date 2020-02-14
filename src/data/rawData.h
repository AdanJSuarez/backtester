#ifndef BACKTESTER_SRC_DATA_RAWDATA_H

struct RawDataLine {
    int m_timeStamp;
    double m_price;
    double m_volume;
};

struct RawData {
    std::vector<RawDataLine> rawData;
}

#endif // BACKTESTER_SRC_DATA_DATASTRUCTURES_H
