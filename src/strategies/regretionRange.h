#ifndef BACKTEST_SRC_STRATEGIES_REGRETIONRANGE_H
#define BACKTEST_SRC_STRATEGIES_REGRETIONRANGE_H

#include "../data/data.h"
#include "../backtestResult/backtestResult.h"

class RegretionRange {

    const int m_range {10};
    int m_numOfTicks {0};
    int m_numOfEntries {1};
    double m_entryDistance {0.1};
    double m_entryPriceLong {0.0};
    double m_entryPriceShort {0.0};
    double m_lot {0.01};
    double m_inventory {0.0};
    BacktestResult m_result {m_lot};
    const double m_max_inventory {m_lot};

    public:
        RegretionRange(int numOfEntry, double entryDistance, double lot, double inventory);
        void quoteEvent(const RawDataLine& quoteEvent);
        double getResult();
        BacktestResult getBacktestResult();
    private:
        void updateParameters(const RawDataLine&);
        bool triggerIn(const RawDataLine&);
        bool triggerOut(const RawDataLine&);
        bool maxInventory();
};

#endif
