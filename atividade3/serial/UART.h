#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "Singleton.h"
#include "Fila.h"

typedef Fila<uint8_t, 30> Fila;

class UART : public Singleton<UART> {
public:
    enum DataBits_t {
        FIVE_DB = 0,
        SIX_DB = 2,
        SEVEN_DB = 4,
        EIGHT_DB = 6
    };

    enum Parity_t {
        NONE_PAR = 0,
        EVEN_PAR = 32,
        ODD_PAR = 48
    };

    enum StopBit_t {
        ONE_SB = 0,
        TWO_SB = 8
    };

    enum DoubleSpeed_t {
    	DS_ENABLE = 1,
		DS_DISABLE = 0
    };

    UART(uint16_t baud, DataBits_t db, Parity_t par, StopBit_t sb, uint8_t double_speed=0);
    ~UART();
    void put(uint8_t data);
    void puts(char* data);
    uint8_t get();
    bool has_data();

    //Handles de interrupção
    static void rx_isr_handler();
    static void tx_isr_handler();

private:
    Fila rx_buffer;
    Fila tx_buffer;
};

#endif /* UART_H_ */
