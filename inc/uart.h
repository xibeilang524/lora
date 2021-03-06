#ifndef __UART_H
#define __UART_H
#include "lora.h"
extern bool IsLoraSend;
extern bool IsDevSend;

#define DevCom USART2
#define LoraCom USART1

typedef enum
{
    DevUSART,
    LoraUSART
} USART;

#define LORA_DMA_RX DMA1_Channel2
#define LORA_DMA_TX DMA1_Channel1
#define DEV_DMA_RX DMA1_Channel3
#define DEV_DMA_TX DMA1_Channel0
#define LORA_RECV_BUFF_SIZE 100
#define LORA_SEND_BUFF_SIZE 50
#define DEV_RECV_BUFF_SIZE 100
#define DEV_SEND_BUFF_SIZE 50
#define DEV_DMA_FLAG_TCRX DMA1_FLAG_TC3
#define DEV_DMA_FLAG_TCTX DMA1_FLAG_TC0
#define LORA_DMA_FLAG_TCRX DMA1_FLAG_TC2
#define LORA_DMA_FLAG_TCTX DMA1_FLAG_TC1

extern uint8_t LORA_RECV_BUFF[LORA_RECV_BUFF_SIZE];
extern uint8_t LORA_SEND_BUFF[LORA_SEND_BUFF_SIZE];
extern uint8_t DEV_RECV_BUFF[DEV_RECV_BUFF_SIZE];
extern uint8_t DEV_SEND_BUFF[DEV_SEND_BUFF_SIZE];
extern uint8_t LoraRecvPos;
extern uint8_t DevRecvPos;

#define LORA_RX_BUFF_ADDR (uint32_t)(&LORA_RECV_BUFF)
#define LORA_TX_BUFF_ADDR (uint32_t)(&LORA_SEND_BUFF)
#define DEV_RX_BUFF_ADDR (uint32_t)(&DEV_RECV_BUFF)
#define DEV_TX_BUFF_ADDR (uint32_t)(&DEV_SEND_BUFF)

#define LORA_DR_ADDR ((uint16_t)0x5231) //(USART1_BASE + 1)(uint16_t) 0x5230 + 1
#define DEV_DR_ADDR ((uint16_t)0x53E1)  //(USART2_BASE + 1)(uint16_t) 0x53E0 + 1

extern void SendLora(uint8_t *data, uint8_t dataLen);
extern void SendDevice(uint8_t *data, uint8_t dataLen);
extern void SetRS485CTL(BitAction state);
extern int putchar(int c);
extern int getchar(void);
extern void ShowString(char *str);
extern void InitUart();
extern void ResetDevRx();
extern void ResetLoraRx();
extern void SetLoraReadySend();
extern void ReConfDeviceUart();
extern void SendCmdToDevice(uint8_t cmdNum);

#endif // !__UART_H
