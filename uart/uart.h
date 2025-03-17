#ifndef UART_H
#define UART_H

#include <stdint.h>

#define UART0 0x10000000

typedef struct
{
    volatile uint8_t *base;
} UART_HandleTypeDef;

// Initialize the UART handle
static inline void UART_Init(UART_HandleTypeDef *huart, uintptr_t base_address);

// Send a byte via UART
static inline void UART_Transmit(UART_HandleTypeDef *huart, uint8_t data);

// Read a byte from UART
static inline uint8_t UART_Receive(UART_HandleTypeDef *huart);

// Send a string via UART
static inline void UART_TransmitString(UART_HandleTypeDef *huart, const char *str);

#endif // UART_H