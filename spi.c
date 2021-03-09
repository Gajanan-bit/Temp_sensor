#include<reg51.h>
#include"types.h"
#include"mcp3204_defines.h"

//bitbanging/sw spi
/*
u8 spi(u8 dat)
{
u8 i,val=0;
for(i=0;i<8;i++)
{
clk=0;
din=(dat&(0x80>>i))?1:0;
clk=1;
if(dout)
val=val|(0x80>>i);
}
return val;
}*/
