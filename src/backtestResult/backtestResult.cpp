#include "backtestResult.h"
#include <cmath>

BacktestResult::BacktestResult() {
    // Do nothing.
};

void BacktestResult::setInputPrice(const double inputPrice, const bool longEntry) {
    m_longEntry = longEntry;
    m_inputPrice = inputPrice;
};

void BacktestResult::setOutputPrice(const double outputPrice) {
    double subResult {0};
    m_outputPrice = outputPrice;
    if(m_longEntry) {
        subResult = m_outputPrice - m_inputPrice;
    } else {
        subResult = m_inputPrice - m_outputPrice;
    }
    m_vectorOfResult.push_back(subResult);
};

double BacktestResult::getResult() {
    double sumOfElements {0};
    std::for_each(m_vectorOfResult.begin(), m_vectorOfResult.end(), [&] (double n) {
        sumOfElements += n;
    });
    return sumOfElements;
}
