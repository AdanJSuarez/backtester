#ifndef BACKTESTER_SRC_DATA_DATA_H

class Data {
    int m_timeStamp;
    double m_high;
    double m_low:
    double m_open;
    double m_close;
    public:
        Data();
        transformRawData(RawData rawData);
};

#endif
