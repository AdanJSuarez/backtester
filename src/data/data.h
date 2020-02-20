#ifndef BACKTESTER_SRC_DATA_DATA_H
#include <vector>
#include "rawData.h"

/*
Dataline represents one datapoint in a specific timeframe.
*/
struct DataLine {
    int m_timeStamp {0}; // At the beginning of the timeframe
    double m_high {0.0};
    double m_low {0.0};
    double m_open {0.0};
    double m_close {0.0};
    double m_volume {0.0};
};

/*
Data is the central class that define the main actions on data for loading
and transform from raw data to Data.
*/
class Data {
    std::vector<DataLine> m_data;
    public:
        Data(RawData& rawData);
        std::vector<DataLine> getData();
    private:
        void transformRawData(RawData& rawData);
        std::vector<RawDataLine> selectRange(const std::vector<RawDataLine>&, int, int);
        DataLine setOHLCV(const std::vector<RawDataLine>&);

};

#endif
