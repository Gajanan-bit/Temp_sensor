#include<reg51.h>
#include"types.h"
#include"mcp3204_defines.h"
#include"spi.h"

float read1_adc_mcp3204(u8 channel_no)
{
u16 adc_val=0;
float temp;
bit d0,d1;
s8 i;
d0=channel_no&1;
d1=(channel_no>>1)&1;
cs=clk=din=dout=1;
cs=0;
//7 clock pulses to sample analog signal and issue null bit
clk=0;clk=1;
clk=0;clk=1;
clk=0;clk=1;
din=d1;
clk=0;clk=1;
din=d0;
clk=0;clk=1;
clk=0;clk=1;
clk=0;clk=1;
//READ 12 BII CONVERTED VALUE MSB FIRST
for(i=11;i>=0;i--)
{
clk=0;
if(dout)
adc_val|=(1<<i);
clk=1;
}
cs=1;
temp=((adc_val*5.0)/4096);
return temp;
}

/*float read2_adc_mcp3204(u8 channel_no)
{
u8 Hbyte,Lbyte;
u16 adc_val=0;
float temp;
cs=clk=dout=din=1;
cs=0;
spi(0x06);
Hbyte=spi(channel_no<<6);
Lbyte=spi(0x00);
cs=1;
adc_val=((Hbyte&0x0f)<<8)|Lbyte;
temp=((adc_val*5.0)/4096);
return temp;}*/
