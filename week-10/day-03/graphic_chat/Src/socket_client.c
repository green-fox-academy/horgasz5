/* Includes ------------------------------------------------------------------*/
#include "socket_client.h"
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
TS_StateTypeDef TS_State;
char ip_to_connect[] = "10.27.6.11";
uint16_t serv_port = 12122;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

// TODO:
// Implement this function!
void socket_client_thread(void const *argument)
{
	uint16_t maxx = (uint16_t) BSP_LCD_GetXSize();
	uint16_t maxy = (uint16_t) BSP_LCD_GetYSize();

	BSP_TS_Init(maxx, maxy);
	LCD_UsrLog ("start client ... \n");
	uint8_t buflen = 64;
	char buf[buflen];
	int cli_sock;
	if ((cli_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_IP)) < 0) {
		LCD_ErrLog ("error create sock \n");
	}
	LCD_UsrLog ("sock created \n");
	struct sockaddr_in servaddr;
	bzero( &servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(ip_to_connect);
	//inet_pton(AF_INET,"10.27.6.11",&(servaddr.sin_addr));
	servaddr.sin_port = htons(serv_port);
	osDelay(5);
	long int del = 2350;
	printf("try connecting to %s:%d\n",ip_to_connect , serv_port);
	while( connect(cli_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		LCD_ErrLog ("error connect \n");
		osDelay(del);
		del += 100;
		printf("try connecting to %s:%d\n",ip_to_connect , serv_port);
	}
	printf("Connected to %s:%d\n",ip_to_connect , serv_port);
	int sent_bytes;
	int received_bytes;
	do {
		// Send data to the server
		//BSP_TS_GetState(&TS_State);
		if(TS_State.touchDetected > 0 && TS_State.touchX[0] > 0 && TS_State.touchX[0] < maxx
				&& TS_State.touchY[0] > 0 && TS_State.touchY[0] < maxy) {
			sprintf(buf, "%d %d%c", TS_State.touchX[0], TS_State.touchY[0], '\0');
			printf("%d %d\n", TS_State.touchX[0], TS_State.touchY[0]);
			 //draw_circ(TS_State.touchX[0],TS_State.touchY[0],5);
		} else {
			strcpy(buf, "5 5");
		}
		sent_bytes = send(cli_sock, buf, strlen(buf), 0);
		if (sent_bytes < 0 )
			LCD_ErrLog ("error send \n");
		// Receive the answer if message was sent
		else {
			received_bytes = recv(cli_sock, buf, buflen, 0);
			if ( received_bytes < 0) {
				LCD_ErrLog ("error recv \n");
			} else {
				LCD_UsrLog (buf);
			}
		}
		osDelay(5);
	} while (sent_bytes > 0);
	closesocket(cli_sock);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
