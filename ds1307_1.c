#include"types.h"
#include"i2c.h"
#include<string.h>
code u8 daymap[7][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
void settime(s8 *time)
{
u8 hrs,min,sec;
hrs=((time[0]&0x0f)<<4)|(time[1]&0x0f);
min=((time[3]&0x0f)<<4)|(time[4]&0x0f);
sec=((time[6]&0x0f)<<4)|(time[7]&0x0f);
I2C_Dev_Write(0xd0,0x02,hrs);
I2C_Dev_Write(0xd0,0x01,min);
I2C_Dev_Write(0xd0,0x00,sec);
}

s8*gettime(void)
{
static s8 time[9]="00:00:00";
u8 hrs,sec,min;
hrs=I2C_Dev_Read(0xd0,0x02);
min=I2C_Dev_Read(0xd0,0x01);
sec=I2C_Dev_Read(0xd0,0x00);
time[0]=(hrs>>4)+48;
time[1]=(hrs&0x0f)+48;
time[3]=(min>>4)+48;
time[4]=(min&0x0f)+48;
time[6]=(sec>>4)+48;
time[7]=(sec&0x0f)+48;
return time;
}
void setdate(s8 *cal)
{
u8 day,date,month,year,i;
s8 temp[4]=" ";
strncpy(temp,cal,3);
for(i=0;i<8;i++)
{
if(strstr(daymap[i],temp))
break;
}
day=++i;
date=((cal[4]&0x0f)<<4)|(cal[5]&0x0f);
month=((cal[7]&0x0f)<<4)|(cal[8]&0x0f);
year=((cal[12]&0x0f)<<4)|(cal[13]&0x0f);
I2C_Dev_Write(0xd0,0x03,day);
I2C_Dev_Write(0xd0,0x04,date);
I2C_Dev_Write(0xd0,0x05,month);
I2C_Dev_Write(0xd0,0x06,year);
}

s8 *getdate(void)
{
static s8 calender[15]="DAY/00/00/2000";
u8 day,date,month,year;
day=I2C_Dev_Read(0xd0,0x03);
date=I2C_Dev_Read(0xd0,0x04);
month=I2C_Dev_Read(0xd0,0x05);
year=I2C_Dev_Read(0xd0,0x06);

calender[0]=daymap[day-1][0];
calender[1]=daymap[day-1][1];
calender[2]=daymap[day-1][2];

calender[4]=(date>>4)+48;
calender[5]=(date&0x0f)+48;
calender[7]=(month>>4)+48;
calender[8]=(month&0x0f)+48;
calender[12]=(year>>4)+48;
calender[13]=(year&0x0f)+48;

return calender;
}
