#include "../data/data.h"

class RegretionRange {

    int m_numOfEntries {3};
    double m_entryDistance {0.1};
    Data m_data;
    double m_result;

    public:
        RegretionRange(const Data&);
        double getResult();
}
