#include "backtestResult.h"
#include <iostream>

BacktestResult::BacktestResult(const double lot) {
    m_lot = lot;
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
    std::cout << "inputPrice: " << m_inputPrice <<  "\n";/////////
    std::cout << "outputPrice: " << outputPrice << " " << "isLong: " << m_longEntry << "\n";
    std::cout << "subResult: " << subResult << "\n"; /////////
    m_vectorOfResult.push_back(subResult * m_lot);
};

double BacktestResult::getResult() {
    double sumOfElements {0};
    for (double element: m_vectorOfResult) {
        std::cout << element << "\n"; ////////////
        sumOfElements += element;
    }
    return sumOfElements;
}
