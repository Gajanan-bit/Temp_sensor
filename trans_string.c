#include<reg51.h> 
#include<string.h>
//#include"lcd.h"
//#include"lcd1.c"
void uart_init()
{
SCON=0x50;
TMOD=0x20;
TH1=253;
TR1=1;
}
void tx_char(char c)
{
SBUF=c;
while(TI==0);
TI=0;
}                                                                                                                                           
char rx_char(void)
{
while(RI==0);
RI=0;
return(SBUF);
}
void string(char *str)
{
int i;
for(i=0;str[i];i++)
{
tx_char(str[i]);
}
}

void uart_int(int i)
{
	char s[10];
	int j;
	if(i<10)
	{
		tx_char('-');
		i*=-1;
	}
	for(j=0;i;i/=10,j++)
		s[j]=(i%10)+48;
	s[j]=0;
	for(j=strlen(s)-1;j>=0;j--)
	{	
		tx_char(s[j]);
	}
}


