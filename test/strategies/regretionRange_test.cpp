#include "../../src/strategies/regretionRange.h"
#include "../../src/loadData/loadData.h"
#include "../../lib/catch.hh"

TEST_CASE("Test suit for regretionRange.ccp") {

    RegretionRange strategy1 {3, 0.01, 0.01, 0.03};
    LoadData loadData1 {"dataExamples/dataExample.csv"};
    RawData rawData {loadData1.getData()};
    double lastPrice {0.0};
    for (RawDataLine event: rawData.m_rawData) {
        strategy1.quoteEvent(event);
        lastPrice = event.m_price;
    };
    strategy1.getBacktestResult().setOutputPrice(lastPrice);

    SECTION("Transform a basic raw data in data") {
        REQUIRE(strategy1.getResult() == 0);

    };

};
