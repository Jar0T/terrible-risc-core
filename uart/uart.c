#include "uart.h"

#define UART_DATA 0x00
#define UART_STATUS 0x01
#define UART_RX_COUNT 0x02
#define UART_TX_COUNT 0x03

#define RX_FULL 0x01
#define RX_EMPTY 0x02
#define TX_FULL 0x04
#define TX_EMPTY 0x08

static inline void UART_Init(UART_HandleTypeDef *huart, uintptr_t base_address)
{
    huart->base = (volatile uint8_t *)base_address;
}

static inline void UART_Transmit(UART_HandleTypeDef *huart, uint8_t data)
{
    while (huart->base[UART_STATUS] & TX_FULL)
        ;
    huart->base[UART_DATA] = data;
}

static inline uint8_t UART_Receive(UART_HandleTypeDef *huart)
{
    while (huart->base[UART_STATUS] & RX_EMPTY)
        ;
    return huart->base[UART_DATA];
}

static inline void UART_TransmitString(UART_HandleTypeDef *huart, const char *str)
{
    while (*str)
    {
        UART_Transmit(huart, (uint8_t)*str++);
    }
}
