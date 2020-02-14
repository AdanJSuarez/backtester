#ifndef BACKTESTER_SRC_DATA_DATA_H
#include <vector>

struct DataLine {
    int m_timeStamp;
    double m_high;
    double m_low:
    double m_open;
    double m_close;
}

/*
Genaral documentation for the class, should go here.
*/
class Data {
    std::vector<DataLine> m_data;
    public:
        Data();
        transformRawData(RawData rawData);
};

#endif
