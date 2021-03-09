#ifndef _I2C_H_
#define _I2C_H_
#include"types.h"
//prototypes for bus events
void I2Cstart(void);
void I2Cstop(void);
void I2Cwrite(u8);
u8 I2Cread(void);
void I2Cack(void);
void I2Cnoack(void);
void I2Cmasterack(void);
void I2Crestart(void);

//prototypes for communication algorithm
void I2C_Dev_Write(u8,u8,u8);
u8 I2C_Dev_Read(u8,u8);

//void I2C_Dev_Pagewrite(u8,u8,u8*,u8);
//void I2C_Dev_Seq_Read(u8,u8,u8*,u8);

#endif
