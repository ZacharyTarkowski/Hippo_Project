/*
 * UART_Utils.h
 *
 *  Created on: Aug 13, 2024
 *      Author: zacht
 */

#ifndef SRC_GENERAL_UTILS_H_
#define SRC_GENERAL_UTILS_H_

#include "usart.h"
#include "string.h"
#include "stdio.h"
#include "stdarg.h"

extern UART_HandleTypeDef huart2;


typedef enum {
    ADD,
    SUB,
    MULTIPLY,
    DIVIDE,
}operation_e;

typedef enum {
    STATE_IDLE,
    STATE_ACTIVE
}STATE_E;


#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

#define s8  int8_t
#define s16 int16_t
#define s32 int32_t

typedef s32 dtw_seq_t;

#define BAD_PRINT_STRING "Bad Print Call\n\r"

void printstring(char* msg);

void uart_printf(const char* fmt, ...);

void uart_println(const char* fmt, ...);

#endif /* SRC_GENERAL_UTILS_H_ */
