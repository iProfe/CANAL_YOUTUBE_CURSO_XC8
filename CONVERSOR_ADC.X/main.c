/*
 * File:   main.c
 * Author: Usuario
 *
 * Created on 24 de mayo de 2020, 10:39 AM
 */


#include <xc.h>
#include "config.h"
#include "myADC.h"
int miValor;
void main(void) {
    TRISC= 0x00;
    TRISD = 0x00;
    ADCON1 = 13;
    LATC=0x00;
    
    ADC_Init(_TAD_4,_TOSC_4);
   
    while(1){
        
        
        miValor = ADC_Read(0);
        LATD = miValor;
        LATC = miValor>>8;
        LATC = (miValor>>8)|0b01000000;
        __delay_ms(800);
        
        miValor = ADC_Read(1);
        LATD = miValor;
        LATC = (miValor>>8)|0b10000000;
        __delay_ms(800);

    }
    
    
    return;
}
