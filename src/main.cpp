#include "main.h"

int main(int argc, const char** argv) {
    std::string fileName {argv[argc - 1]};
    printf(fileName.c_str());
    printf("\n");

    LoadData loadedData {fileName};
    RawData rawData {loadedData.getData()};
    Data data {rawData, 10};
    RegretionRange strategy {3, 0.03, 0.01, 0.03};

    for (RawDataLine event: rawData.m_rawData) {
        strategy.quoteEvent(event);
    };
    std::cout << "The result is: ";
    std::cout<< strategy.getResult() << "/n";
    // Develop the strategy.
    // Pass event to regretionRange
    // Calculate result.
    // Show result.

    return 0;
}
