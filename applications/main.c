/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-12-18     zylx         first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

#define	LED0_PIN_NUM	GET_PIN(G, 7)//(G-1)*16 + 7
#define	LED1_PIN_NUM	GET_PIN(D, 12)

int main(void)
{
    int count = 1;
	
	rt_pin_mode(LED0_PIN_NUM, PIN_MODE_OUTPUT);
	rt_pin_mode(LED1_PIN_NUM, PIN_MODE_OUTPUT);

    while (count++)
    {
		rt_pin_write(LED0_PIN_NUM, PIN_LOW);
		rt_pin_write(LED1_PIN_NUM, PIN_HIGH);
		rt_thread_mdelay(200);
			
		rt_pin_write(LED0_PIN_NUM, PIN_HIGH);
		rt_pin_write(LED1_PIN_NUM, PIN_LOW);
		rt_thread_mdelay(200);
    }
    
    return RT_EOK;
}

