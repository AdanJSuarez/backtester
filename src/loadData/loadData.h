#ifndef BACKTEST_SRC_LOADDATA_LOADDATA_H
#define BACKTEST_SRC_LOADDATA_LOADDATA_H
#include "../data/data.h"
#include <string>

/*
Load data from a file giving the file path.
*/
class LoadData {

    std::string m_fileName;
    RawData m_rawData;

    public:
        LoadData(std::string fileName);
        RawData getData();

    private:
        void splitLine(std::vector<std::string> & container, std::string & line);
        void addVectorToRawData(const std::vector<std::string>& container, RawDataLine& rawLine);

};

#endif // !BACKTEST_SRC_LOADDATA_LOADDATA_H
