/*
 * File:   main.c
 * Author: Usuario
 *
 * Created on 24 de mayo de 2020, 10:39 AM
 */


#include <xc.h>
#include "config.h"

void main(void) {
    TRISC= 0x00;
    TRISD = 0x00;
    ADCON1 = 14;
    ADCON0bits.CHS=0; // seleccionamos el canal cero
    ADCON2bits.ACQT = 2;
    ADCON2bits.ADCS = 4;
    ADCON2bits.ADFM = 1; // justificamos a la derecha
    ADCON0bits.ADON = 1; // habilitamos el modulo ADC
    
    while(1){
        ADCON0bits.CHS=10;
        ADCON0bits.GO_nDONE = 1;
        while( ADCON0bits.GO_nDONE==1);
        
        LATD = ADRESL;
        LATC = ADRESH;
        
        __delay_ms(5);
    }
    
    
    return;
}
