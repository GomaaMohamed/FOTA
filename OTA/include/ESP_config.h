/************************************************/
/* Author :Hussin Ebrahim                       */
/* Date   :30/9/2020                            */
/* Version:V01                                  */
/************************************************/
#ifndef        ESP_CONFIG_H
#define        ESP_CONFIG_H

////AT+CWJAP_CUR="Apple","1998_2021_balah"
//#define        SSID_PASS         ((u8 *)("AT+CWJAP_CUR=\"Apple\",\"1998_2021_balah\"\r\n"))
#define        SSID_PASS           ((u8 *)("AT+CWJAP_CUR=\"Beno\",\"Shakal_20312031\"\r\n"))
#define        SERVER_IP          ((u8 *)("AT+CIPSTART=\"TCP\",\"162.253.155.226\",80\r\n"))

#endif
