#include"types.h"
void delay_ms(u16 dlyms)
{
u16 i;
for(;dlyms>0;dlyms--)
for(i=122;i>0;i--);
}
