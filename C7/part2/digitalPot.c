/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *          View this license at http://creativecommons.org/about/licenses/
 */

#include "spi.h"

void init_pot(void)
{
    /* TODO: Code to initiliase interface */
    init_spi_master();
}

void decXpot(void)
{
    /* TODO: Code to decrement first pot by 1 */
    spi_tx(0b00001000);
}

void incXpot(void)
{
    /* TODO: Code to increment first pot by 1 */
    spi_tx(0b00000100);
}

void decYpot(void)
{
    /* TODO: Code to decrement second pot by 1 */
    spi_tx(0b00011000);
}

void incYpot(void)
{
    /* TODO: Code to increment second pot by 1 */
    spi_tx(0b00010100);
}

void setXpot(uint8_t x)
{
    /* TODO: Code to set first pot to a value between 0 and 255 */
    spi_tx(0b00000000);
    spi_tx(x);
}

void setYpot(uint8_t y)
{
    /* TODO: Code to set second pot to a value between 0 and 255 */
    spi_tx(0b00010000);
    spi_tx(y);
}

