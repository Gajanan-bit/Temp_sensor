#include<reg51.h>
#include<string.h>
#include"types.h"
#include"i2c.h"
#include"lcd.h"
#include"delay.h"
#include"i2c_defines.h"
#include"uart.h"
#include"ds1307_1.h"
#include"mcp3204.h"
#include"mcp3204_defines.h"
void RTC_init(void);
main()
{
u8 i=0;
LCD_init();
uart_init();
RTC_init();
delay_ms(500);
while(1)
{
LCD_cmd(0x80);
LCD_str(gettime());
string(gettime());

LCD_cmd(0x89);
LCD_int(read1_adc_mcp3204(i)*100);
LCD_str("deg");
//LCD_cmd(0x06);
uart_int(read1_adc_mcp3204(i)*100);
string("deg");

LCD_cmd(0xc0);
LCD_str(getdate());
string(getdate());
delay_ms(500);
//while(1);
}
}
void RTC_init(void)
{

s8 time[9]="12:12:30",cal[15]="THU/13/06/2019";

	LCD_str("setting RTC time :");
	string("setting RTC time  ");
	
	LCD_cmd(0xc0);
	delay_ms(2000);
	LCD_str(time);
	settime(time);
	delay_ms(2000);

	LCD_cmd(0x01);
	LCD_str("setting RTC cal :");
	string("setting RTC cal  ");
	LCD_cmd(0xc0);
	delay_ms(1000);
	LCD_str(cal);
	setdate(cal);
	delay_ms(1000);

	LCD_cmd(0x01);
	LCD_str("reading RTC ");
	string("readingRTC ");
	delay_ms(500);
	LCD_cmd(0x01);
}

