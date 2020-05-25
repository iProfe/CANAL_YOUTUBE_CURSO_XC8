/*
 * File:   main.c
 * Author: Usuario
 *
 * Created on 19 de mayo de 2020, 12:06 AM
 */


#include <xc.h>
#include "config.h"
#include "deco_catodo.h"



char contador=3;

void secuencia_1(){
    char aux=0b00000001;
    PORTB=0;
    for(int i=0; i<=8; i++){
        PORTB=PORTB |(aux<<i);
        __delay_ms(20);
    }
    aux=0b01111111;
    for(int i=0; i<=8; i++){
        PORTB=PORTB &(aux>>i);
        __delay_ms(20);
    }
}

void secuencia_2(){
    char aux = 0b01010101;
    PORTB=aux;
    __delay_ms(100);
    PORTB=~PORTB;                    
    __delay_ms(100); 
}

void secuencia_3(){
    char aux = 0b00011000;
    PORTB=0;
    for(int i=0; i<4; i++){
        PORTB = PORTB | (aux<<i);
        PORTB = PORTB | (aux>>i);
        __delay_ms(100);
    }
    aux=0b01111111;
    for(int i=0; i<4; i++){
        PORTB = PORTB & (aux>>i);
        __delay_ms(100);
    }
     aux=0b11111110;
    for(int i=0; i<4; i++){
        PORTB = PORTB & (aux<<i);
        __delay_ms(100);
    }
}

void main(void) {
    ADCON1 = 15;  // 0x0F;
    TRISAbits.RA0 = 1;
    TRISD = 0x00;
    TRISB = 0x00;
    
    while(1){
        
        if(PORTAbits.RA0==1){
            while(PORTAbits.RA0==1); // __delay_ms(200);
            contador++;
            if(contador>3){
                contador=1;
            }
        }
        if(PORTEbits.RE3==0){
            while(PORTEbits.RE3==0);
            contador--;
            if(contador<1){
                contador=3;
            }   
        }
        PORTD = deco_cc(contador);
        
        switch(contador){
            case 1: secuencia_1(); break;
            case 2: secuencia_2(); break;
            case 3: secuencia_3(); break;
        }
        
    }
    return;
}


