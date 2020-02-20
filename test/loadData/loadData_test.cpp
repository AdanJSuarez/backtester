#include "../../src/loadData/loadData.h"
#include "../../lib/catch.hh"
#include <iostream>

TEST_CASE("Test suit for loadData.cpp") {
    LoadData loadData1 {"dataExamples/dataExample.csv"};

    SECTION("It should load data from a file filtering out headers") {
        int actual1 = loadData1.getData().m_rawData[0].m_timeStamp;
        double actual2 = loadData1.getData().m_rawData[0].m_price;
        double actual3 = loadData1.getData().m_rawData[0].m_volume;
        int expected1 = 1417412036;
        double expected2 = 300.0;
        double expected3 = 0.01;
        REQUIRE(actual1 == expected1);
        REQUIRE(actual2 == expected2);
        REQUIRE(actual3 == expected3);
    }
};
