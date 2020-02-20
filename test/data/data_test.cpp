#define CATCH_CONFIG_MAIN
// #include "../../src/data/data.h"
#include "../../lib/catch.hh"
#include "../../src/loadData/loadData.h"

TEST_CASE("Test suit for data.ccp") {

    RawData rawData1;
    LoadData loadData1 {"dataExamples/dataExample.csv"};
    rawData1 = loadData1.getData();
    Data data1 {rawData1};

    SECTION("Transform a basic raw data in data") {
        DataLine dataLine1 = data1.getData()[0];
        REQUIRE(dataLine1.m_timeStamp == 1417412036);
        REQUIRE(dataLine1.m_high == 378.0);
        REQUIRE(dataLine1.m_low == 300.0);
        REQUIRE(dataLine1.m_open == 300.0);
        REQUIRE(dataLine1.m_close == 378.0);
        REQUIRE(dataLine1.m_volume == 14.26655554);
        DataLine dataLine2 = data1.getData()[1];
        REQUIRE(dataLine2.m_timeStamp == 1417546703);
        REQUIRE(dataLine2.m_high == 378.0);
        REQUIRE(dataLine2.m_low == 377.9);
        REQUIRE(dataLine2.m_open == 378.0);
        REQUIRE(dataLine2.m_close == 378.0);
        REQUIRE(dataLine2.m_volume == 0.90020842);
    };

};
