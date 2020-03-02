#ifndef BACKTESTER_SRC_BACKTESTRESULT_BACKTESTRESULT_H
#define BACKTESTER_SRC_BACKTESTRESULT_BACKTESTRESULT_H
#include <vector>

class BacktestResult {
    double m_inputPrice {0.0};
    double m_outputPrice {0.0};
    double m_pnl {0.0};
    bool m_longEntry {true};
    double m_lot {0.0};
    std::vector<bool> m_vectorOfResult;

    public:
        BacktestResult(const double);
        void setInputPrice(const double, const bool);
        void setOutputPrice(const double);
        double getResult();
};

#endif
