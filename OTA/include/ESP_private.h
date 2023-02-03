/************************************************/
/* Author :Hussin Ebrahim                       */
/* Date   :30/9/2020                            */
/* Version:V01                                  */
/************************************************/
#ifndef        ESP_PRIVATE_H
#define        ESP_PRIVATE_H

u8 voidEspValidateCmd(u32 Copy_u32TimeOut);
#define    ESP_INIT_TIMEOUT                     100
#define    ESP_WIFI_TIMEOUT                     500000
#define    ESP_SERVER_CONNECT_TIMEOUT           300000
#define    ESP_GET_SERVER_VAL_TIMEOUT           100000
#endif
