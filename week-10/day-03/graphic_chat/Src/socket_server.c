/* Includes ------------------------------------------------------------------*/
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>
#include <stdint.h>

/* Private typedef -----------------------------------------------------------*/
typedef struct {
	int32_t x;
	int32_t y;
} coordinate_t;

TS_StateTypeDef TS_State;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void get_cord(char *buf, int32_t *n1, int32_t *n2)
{
    char szam1[20];
    char szam2[20];
    memset(szam1,'\0', 20);
    memset(szam2,'\0', 20);
    int i = 0;
    int j = 0;
    while(i < strlen(buf) && buf[i] != ' ') {
    	szam2[j] = buf[i];
        i++;
        j++;
    }
    szam2[j]='\0';
    j = 0;
    i = i + 1;
    while(i < strlen(buf) && buf[i] != '\0') {
    	szam1[j] = buf[i];
        j++;
        i++;
    }
    szam1[j]='\0';

   char * pEnd;
   *n1 = strtol(szam1, &pEnd, 10);
   *n2 = strtol(szam2, &pEnd, 10);

   return;
}

void terminate_thread()
{
	while (1)
		osThreadTerminate(NULL);
}

void TS_thread(void const *argument)
{
	while (1) {
		if (BSP_PB_GetState(BUTTON_KEY) == 1)
		{
			BSP_LCD_Clear(LCD_COLOR_WHITE);
			osDelay(5);
		}
		BSP_TS_GetState(&TS_State);
		BSP_LCD_SelectLayer(2);
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
		int rad2 = 5;
		if (TS_State.touchX[0] > rad2 && TS_State.touchX[0] < (480 - rad2)
				&& TS_State.touchY[0] > rad2 && TS_State.touchY[0] < (272 - rad2))
			BSP_LCD_FillCircle(TS_State.touchX[0], TS_State.touchY[0], rad2);

		BSP_LCD_SelectLayer(1);
		osDelay(5);
	}
}

// TODO:
// Implement this function!
void socket_server_thread(void const *argument)
{
	BSP_LCD_SelectLayer(1);
	LCD_UsrLog("Socket server - startup...\n");
	LCD_UsrLog("Socket server - waiting for IP address...\n");

	// Wait for an IP address
	while (!is_ip_ok())
		osDelay(10);
	LCD_UsrLog("Socket server - IP address is ok\n");

	// Create server socket
	int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	if (server_socket < 0) {
		LCD_ErrLog("Socket server - can't create socket\n");
		terminate_thread();
	}
	LCD_UsrLog("Socket server - socket created\n");

	// Create address structure and bind the socket to it
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(server_socket, (struct sockaddr*)&(server_addr), sizeof(server_addr)) < 0) {
		LCD_ErrLog("Socket server - can't bind socket\n");
		terminate_thread();
	}
	LCD_UsrLog("Socket server - socket bind ok\n");

	// Start listening
	if (listen(server_socket, SERVER_QUEUE_SIZE) < 0) {
		LCD_ErrLog("Socket server - can't listen\n");
		terminate_thread();
	}
	LCD_UsrLog("Socket server - listening...\n");

	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	int client_socket;

	while (1) {
		coordinate_t buff_coord;
		buff_coord.x = 0;
		buff_coord.y = 0;

		// Accept incoming connections
		client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
		LCD_UsrLog("Socket server - connection accepted\n");

		// Check the client socket
		if (client_socket < 0) {
			LCD_ErrLog("Socket server - invalid client socket\n");
		} else {
			// Define buffer for incoming message
			char buff[SERVER_BUFF_LEN];
			int received_bytes;
			// Receive data
			do {
				received_bytes = recv(client_socket, buff, SERVER_BUFF_LEN, 0);
				buff[received_bytes] = '\0';
				get_cord(buff, &buff_coord.y, &buff_coord.x);
				// Check for error
				if (received_bytes < 0) {
					LCD_ErrLog("Socket server - can't receive\n");
				} else {
					// Close the string

					if (BSP_PB_GetState(BUTTON_KEY) == 1)
					{
						BSP_LCD_Clear(LCD_COLOR_WHITE);
						osDelay(10);
					}

					BSP_LCD_SelectLayer(3);
					BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
					int rad = 8;
					if (buff_coord.x > rad && buff_coord.x < (480 - rad) && buff_coord.y > rad && buff_coord.y < (272 - rad))
						BSP_LCD_FillCircle(buff_coord.x, buff_coord.y, rad);


					// Send back the message
					send(client_socket, buff, received_bytes, 0);
				}
			}
			while (received_bytes > 0);

			// Close the socket
			closesocket(client_socket);
			LCD_UsrLog("Socket server - connection closed\n");
		}
	}

	// Close socket
	closesocket(server_socket);

	while (1) {
		osDelay(10);
	}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
