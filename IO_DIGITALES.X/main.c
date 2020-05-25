/*
 * File:   main.c
 * Author: Usuario
 *
 * Created on 9 de mayo de 2020, 03:04 AM
 */


#include <xc.h>
#include "config.h"
int num=0;

void main(void) {
    //CONFIGRUAR LOS PUERTOS TRISX
    TRISB=7;
 /*   TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    TRISBbits.RB2 = 1;*/
    TRISD = 0;
    TRISA = 0;
   
    // manipular los puertos
    
    for(;;){
        
        switch(num){
            case 0: PORTA = 63;  break;  
            case 1: PORTA = 6;   break;  
            case 2: PORTA = 91;  break;  
            case 3: PORTA = 79;  break;  
            case 4: PORTA = 102; break; 
            case 5: PORTA = 109; break; 
            case 6: PORTA = 125; break; 
            case 7: PORTA = 7;   break;
            case 8: PORTA = 127; break; 
            case 9: PORTA = 111;  break;  
        }
        num=num+1;
        if(num==10){
            num=0;
        }
        if(PORTBbits.RB0==1){
            PORTD=0x0F;
        }
        if(PORTBbits.RB1==1){
             PORTD=0xF0;
        }
        
        if(PORTBbits.RB2==1){
             PORTD=0x3F;
        }
      
    /*   
        if(PORTB==1){
            PORTD=0x0F;
        }
        if(PORTB==2){
            PORTD=0xF0;
        }
        if(PORTB==4){
            PORTD=0x3F;
        }*/
        __delay_ms(200);

    }
    return;
}
