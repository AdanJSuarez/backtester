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
    /*
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
   updateParameters();
   if (!triggerIn()) {
       triggerOut();
   };
}
/**
 * @brief  Check if the namber of tick is bigger than the range and if so update parameters.
 * @note
 * @retval None
 */
void RegretionRange::updateParameters() {
    /*
    Check the number of ticks have been pass, if it
    pass that number, update distance.

    If it doesn't, do nothing.
    */
}
/**
 * @brief  Simulate send an order, and update result, inventory and trigger out.
 * @note
 * @retval bool
 */
bool RegretionRange::triggerIn() {
    /*
    Add to result
    Add to inventory.
    Add to trigger out.
    Check inventory, if > max_inventory, allow only trigger out.
    */
    return false;
}
/**
 * @brief  Check if trigger out, and if so, calculate result.
 * @note
 * @retval
 */
bool RegretionRange::triggerOut() {
    /*
    Calculate result.
    */
    return false;
}
