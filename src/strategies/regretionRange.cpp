#include "regretionRange.h"

/**
 * @brief  Generate an instance of RegretionRange
 * @note
 * @param  data: const Data&
 * @retval Constructor
 */
RegretionRange::RegretionRange(const Data& data){
    m_data = data;
};
/**
 * @brief  Get result of the strategy.
 * @note
 * @retval double
 */
double RegretionRange::getResult() {
    return m_result;
}
