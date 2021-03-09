#ifndef _LCD_H_
#define _LCD_H_
#include"types.h"
extern void LCD_init(void);
extern void LCD_cmd(char);
extern void LCD_char(char);
extern void LCD_disp_write(char);
extern void LCD_str(char *);
extern void LCD_int(u16);
#endif
