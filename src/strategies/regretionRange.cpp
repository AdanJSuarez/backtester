#include "regretionRange.h"
#include "../backtestResult/backtestResult.h"

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
void RegretionRange::quoteEvent(const RawDataLine &quoteEvent) {
   if (!triggerIn(quoteEvent)) {
       triggerOut(quoteEvent);
   };
   updateParameters(quoteEvent);
}
/**
 * @brief  Return amount of money resulted from the strategi
 * @note
 * @retval double
 */
double RegretionRange::getResult() {
    return m_result.getResult();
};
/**
 * @brief  Check if the namber of tick is bigger than the range and if so update parameters.
 * @note
 * @retval None
 */
void RegretionRange::updateParameters(const RawDataLine &quoteEvent) {
   if (m_numOfTicks < m_range) {
       ++m_numOfTicks;
   } else {
       m_entryPriceLong = quoteEvent.m_price + m_entryDistance;
       m_entryPriceShort = quoteEvent.m_price - m_entryDistance;
   }
}
/**
 * @brief  Simulate send an order, and update result, inventory and trigger out.
 * @note
 * @retval bool
 */
bool RegretionRange::triggerIn(const RawDataLine &quoteEvent) {
    if (m_inventory >= m_max_inventory) return false;
    if (quoteEvent.m_price > m_entryPriceLong) {
        m_result.setInputPrice(m_entryPriceLong, true);
        m_inventory += m_lot;
        return true;
    } else if (quoteEvent.m_price < m_entryPriceShort) {
        m_result.setInputPrice(m_entryPriceShort, false);
        m_inventory += m_lot;
        return true;
    }
    return false;
}
/**
 * @brief  Check if trigger out, and if so, calculate result.
 * @note
 * @retval
 */
bool RegretionRange::triggerOut(const RawDataLine &quoteEvent) {
    if (quoteEvent.m_price > m_entryPriceLong + m_entryDistance) {
        m_result.setOutputPrice(m_entryPriceLong + m_entryDistance);
        m_inventory = 0.0;
        return true;
    } else if (quoteEvent.m_price < m_entryPriceShort - m_entryDistance) {
        m_result.setOutputPrice(m_entryPriceShort - m_entryDistance);
        m_inventory = 0.0;
        return true;
    }
    return false;
}
