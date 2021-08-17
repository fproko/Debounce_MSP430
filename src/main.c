/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Date: 2021/08/11
 * Version: v1.0
 *===========================================================================*/
#include <msp430.h>
#include "./inc/led.h"
#include "./inc/timer.h"
#include "./inc/teclas.h"
int timer=0;
int delayDB=0;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    __enable_interrupt();
    ledInit();
    timerInit();
    swDBInit();

    while(1)
    {
        swDBUpdate(SW2);
    }
}

//******************************************************************************
// Funcion: TimerA0_ISR_CCR0
// ISR de CCR0 del Timer A0
//******************************************************************************
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TimerA_ISR_CCR0(void)
  {
        timer++;       // por cada timerled son 10ms
        if(timer==delayDB)
        {
            TA0CCTL0 &=~ CCIE; //Deshabilita interrupción del Timer A0
        }
  }
