#include"types.h"
#include"i2c.h"
#include"i2c_defines.h"
#include"delay.h"

void I2Cstart(void)
{

sdapin=1;
sclpin=1;

sdapin=0;
}
void I2Cstop(void)
{
sclpin=0;
sdapin=0;
sclpin=1;
sdapin=1;
}
void I2Cwrite(u8 dat)
{
u8 i;
for(i=0;i<8;i++)
{
sclpin=0;
sdapin=((dat>>(7-i))&1);
sclpin=1;
}
}
u8 I2Cread(void)
{
u8 i,buf=0;
for(i=0;i<8;i++)
{
sclpin=0;
sclpin=1;
if(sdapin)
buf=buf|0x80>>i;
}
return buf;
}
void I2Cack(void)
{
sclpin=0;
sdapin=1;
sclpin=1;
while(sdapin);
}
void I2Cnoack(void)
{
sclpin=0;
sdapin=1;
sclpin=1;
}
/*void I2Cmasterack(void)
{
sclpin=0;
sdapin=0;
sclpin=1;
sclpin=0;
sdapin=1;
}*/
void I2Crestart(void)
{
sclpin=0;
sdapin=1;
sclpin=1;
sdapin=0;
}
void I2C_Dev_Write(u8 slave_addr,u8 buffer_addr,u8 dat)
{
I2Cstart();
I2Cwrite(slave_addr);
I2Cack();
I2Cwrite(buffer_addr);
I2Cack();
I2Cwrite(dat);
I2Cack();
I2Cstop();
delay_ms(10);
}

u8 I2C_Dev_Read(u8 slave_addr,u8 buffer_addr)
{
u8 buf=0;
I2Cstart();
I2Cwrite(slave_addr);
I2Cack();
I2Cwrite(buffer_addr);
I2Cack();
I2Crestart();
I2Cwrite(slave_addr|1);
I2Cack();
buf=I2Cread();
I2Cnoack();
I2Cstop();
return buf;
}

//pagewrite//
/*void I2C_Dev_Pagewrite(u8 slave_addr,u8 buf_start_addr,u8 *arr,u8 size)
{
u8 i;
I2Cstart();
I2Cwrite(slave_addr);
I2Cack();
I2Cwrite(buf_start_addr);
I2Cack();
for(i=0;i<size;i++)
{
I2Cwrite(arr[i]);
I2Cack();
}
I2Cstop();
}

//sequential raed
void I2C_Dev_Seq_Read(u8 slave_addr,u8 buf_addr,u8 *arr,u8 size)
{
u8 i;
I2Cstart();
I2Cwrite(slave_addr);
I2Cack();
I2Cwrite(buf_addr);
I2Cack();
I2Crestart();
I2Cwrite(slave_addr);
I2Cack();
for(i=0;i<size-1;i++)
{
arr[i]=I2Cread();
I2Cmasterack();
}
arr[i++]='\0';
I2Cnoack();
I2Cstop();
}*/




























