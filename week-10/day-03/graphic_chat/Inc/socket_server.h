/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SOCKET_SERVER_H
#define __SOCKET_SERVER_H

/* Includes ------------------------------------------------------------------*/
#define SERVER_PORT			54545
#define SERVER_QUEUE_SIZE	2
#define SERVER_BUFF_LEN		100

#include <stdint.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void TS_thread(void const *argument);
void socket_server_thread(void const *argument);
void get_cord(char *buf, int32_t *n1, int32_t *n2);

#endif /* __SOCKET_SERVER_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
