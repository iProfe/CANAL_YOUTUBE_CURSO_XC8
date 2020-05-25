/*
 * File:   main.c
 * Author: Usuario
 *
 * Created on 12 de mayo de 2020, 11:24 PM
 */


#include <xc.h>
#include "config.h"


int deco(int num){
    int myValue;
     switch(num){
            case 0: myValue = 63;  break;  
            case 1: myValue = 6;   break;  
            case 2: myValue = 91;  break;  
            case 3: myValue = 79;  break;  
            case 4: myValue = 102; break; 
            case 5: myValue = 109; break; 
            case 6: myValue = 125; break; 
            case 7: myValue = 7;   break;
            case 8: myValue = 127; break; 
            case 9: myValue = 111;  break;  
        }
     return myValue;
}
int prueba =0b00000101;
int prueba2=0b01000000;
void main(void){
    TRISA=0x00;
    TRISD=0x00;
    TRISB = 0xFF;
   
    while(1){
       PORTA = deco(PORTB & (0b00001111));
       PORTD = deco( (PORTB & (0b11110000))>>4 ); 
   
    }
    return;
}
