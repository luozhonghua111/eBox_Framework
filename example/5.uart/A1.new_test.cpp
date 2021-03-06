#include "ebox.h"
#include "bsp_ebox.h"
#include "ebox_mem.h"


/**
	*	1	此例程演示了UartStream操作
	*	2	UartStream是串口集成了stream的类。支持了stream的所有功能
	*		包括读取一个String，查找一个关键字，关键词等
	*   	但是这个类中都是阻塞性的读取，
  *       如果开始读取，就会等到读取结束后还会延时设定的超时时间。用户需注意使用
	*/
	

/* 定义例程名和例程发布日期 */
#define EXAMPLE_NAME	"UartStream example"
#define EXAMPLE_DATE	"2018-08-13"

int x,y;

Timer timer1(TIM3);
const char *buf = "1234567890\r\n";
size_t len;
void t2it()
{
        x = UART.availableForWrite();
        UART.write("12345678\r\n");
        y = UART.availableForWrite();;
        UART.println(x);
        UART.println(y);
//        UART.flush();
}
void rx()
{
     PB9.toggle();
}
void tx()
{
//    len = sizeof("1234567890\r\n");
//    UART.write(buf,12);
//    UART.write(buf,12);
 PB8.toggle();
}
void setup()
{
	ebox_init();
    UART.begin(115200);
//    no_interrupts();
    print_log(EXAMPLE_NAME,EXAMPLE_DATE);
//    LED1.mode(OUTPUT_PP);
    UART.attach(rx,RxIrq);
    UART.attach(tx,TxIrq);
    UART.interrupt(RxIrq,ENABLE);
    UART.nvic(ENABLE,1,0);

//    PB8.mode(OUTPUT_PP);
//    PB9.mode(OUTPUT_PP);
    timer1.begin(2);
    //timer1.nvic(ENABLE,0,0);
		
    timer1.attach(t2it);
    timer1.interrupt(ENABLE);
//    timer1.start();
//    UART.printf("\r\ntimer clock       = %dMhz", timer1.get_timer_source_clock()/1000000);
//    UART.printf("\r\nmax interrupt frq = %dKhz", timer1.get_max_frq()/1000);
   

}
int main(void)
{
	setup();
//        UART.write("12345678901234567890123456789012345678901234567890\r\n");
//        delay_ms(100);
//    interrupts();
	while (1)
	{
        len = UART.available();
        for(int i = 0; i < len; i++ )
        {
            UART.write(UART.read());
        }
				if(len)
				{
					UART.printf("free mem %f.02 \r\n",ebox_mem_used()/100);
				}
				
//        uart1.write('3');
//        uart1.write('4');
//        uart1.write('5');
//        uart1.write('6');
//        uart1.write('7');
//        uart1.write('8');
//        uart1.write('9');
//        uart1.write('a');
//        uart1.write('b');
//        uart1.write('c');
//        uart1.write('d');
//        uart1.write('\r');
//        uart1.write('\n');  
//        delay_ms(1000);


	}
}