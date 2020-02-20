#include "main.h"

int main(int argc, const char** argv) {
    std::string fileName {argv[argc - 1]};
    printf(fileName.c_str());
    printf("\n");

    LoadData loadedData {fileName};
    RawData rawData {loadedData.getData()};
    Data data {rawData, 10};

    // Develop the strategy.
    // Run the strategy.
    // Calculate result.
    // Show result.

    return 0;
}
