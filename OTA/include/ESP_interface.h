/************************************************/
/* Author :Hussin Ebrahim                       */
/* Date   :30/9/2020                            */
/* Version:V01                                  */
/************************************************/
#ifndef        ESP_INTERFACE_H
#define        ESP_INTERFACE_H

void ESP_voidInit(void);
void ESP_voidWifiConnect(void);
void ESP_voidServerConnect(void);
u8 ESP_voidGetValFromServer(void);
 u8* ESP_voidGetRecordFromServer(void);
void ESP_voidSendOkToServer(void);
#endif
