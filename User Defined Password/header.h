#define PORT0 0
#define PORT1 1
#define PORT2 2
#define PORT3 3
#define LED_PIN 0
typedef unsigned char u8;
typedef   signed char s8;
typedef unsigned int u16;
typedef   signed int s16;
typedef unsigned long int u32;
typedef   signed long int s32;


void io_bit_write(u8 port_num,u8 pin_num,bit val);
void delay_ms(u16 ms);
bit io_bit_read(u8 port_num,u8 pin_num);

extern void lcd_cmd(u8 cmd);
extern void lcd_data(u8 d);
extern void lcd_init(void);
extern void lcd_string(s8 *p);
extern void lcd_integer(s32 num);
extern void uart_tx_integer(u16 n);
extern void uart_tx_float(float n);
extern void lcd_Shift_Right(void);
extern void lcd_Shift_Left(void);
extern void lock(void);
extern void open(void);
extern void input(s8 arr[]);


extern u8 keyscan(void);

