#include<reg51.h>
#include"delay.h"
#include"lcd.h"
#include<string.h>
#define lcd P0
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
//code char cgram_lut[]={0x1f,0x11,0x11,0x11,0x11,0x11,0x1f,0x00};

void LCD_init(void)
{
delay_ms(20);
LCD_cmd(0x30);
delay_ms(8);
LCD_cmd(0x30);
delay_ms(2);
LCD_cmd(0x30);
delay_ms(2);
LCD_cmd(0x38);
LCD_cmd(0x10);
LCD_cmd(0x01);
LCD_cmd(0x06);
LCD_cmd(0x0e);
}
void LCD_cmd(char cmd)
{
rs=0;
LCD_disp_write(cmd);
}

void LCD_char(char ch)
{
rs=1;
LCD_disp_write(ch);
}

void LCD_disp_write(char ch)
{
rw=0;
lcd=ch;
en=1;
delay_ms(2);
en=0;
}
void LCD_str(char *p)
{
int i=0;
for(i=0;p[i];i++)
{
LCD_char(p[i]);
}
}
void LCD_int(u16 n)
{
u16 rev=0;
while(n)
{
rev=rev*10+n%10;
n=n/10;
}
while(rev)
{
LCD_char(rev%10+48);
rev=rev/10;
}
}
