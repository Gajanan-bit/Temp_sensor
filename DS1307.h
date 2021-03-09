#ifndef _DS1307_H_
#define _DS1307_H_

#include "types.h"
void setSecs(u8);
void setMins(u8);
void setHrs(u8);
void setTime(u8*);
void setCalendar(u8*);  

u8 getSecs(void);
u8 getMins(void);
u8 getHrs(void);
u8* getTime (void);
u8* getCalnder(void);
#endif
