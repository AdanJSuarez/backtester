#include "regretionRange.h"

/**
 * @brief  Generate an instance of RegretionRange
 * @note
 * @param numOfEntry
 * @param entryDistance
 * @param lot
 * @param inventory
 * @retval Constructor
 */
RegretionRange::RegretionRange(int numOfEntry, double entryDistance, double lot, double inventory) {
    m_numOfEntries = numOfEntry;
    m_entryDistance = entryDistance;
    m_lot = lot;
    m_inventory = inventory;
};
/**
 * @brief  Get result of the strategy.
 * @note
 * @retval RawDataLine
 */
void RegretionRange::quoteEvent(const RawDataLine& quoteEvent) {
    /* TODO:
    Check if it's needed to update parameters.
    Check if only allowed trigger out.
    Check if trigger in:
        Add to result.
        Add to inventory.
        Add to trigger out.
        Check inventory, if > max_inventory, allow only trigger out.
    Check if trigger out:
        Calculate result.
    */
}
