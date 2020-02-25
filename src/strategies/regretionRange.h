#include "../data/data.h"

class RegretionRange {

    int m_numOfEntries {3};
    double m_entryDistance {0.1};
    double m_lot {0.01};
    double m_inventory {0};
    const double m_max_inventory {m_lot * 3};

    public:
        RegretionRange(int numOfEntry, double entryDistance, double lot, double inventory);
        void quoteEvent(const RawDataLine& quoteEvent);
        // double getResult(); Not in here!
    private:
        void updateParameters();
        bool triggerIn();
        bool triggerOut();
        bool maxInventory();
};
