/*
 * File:   main.c
 * Author: Usuario
 *
 * Created on 8 de mayo de 2020, 04:06 AM
 */
#include <xc.h>
#include "config.h"

int contador=0;
void main(void) {
    
    ADCON1=0x0F;
   // TRISAbits.RA0 = 0;
    
    TRISA = 0x00;
    TRISBbits.RB0=1;
    
    while(1){
      if(PORTBbits.RB0==1){
          __delay_ms(500);
          contador++;
          if(contador>7){
              contador=0;
          }
      }
      PORTA=contador;
      
    }
    
    return;
}
