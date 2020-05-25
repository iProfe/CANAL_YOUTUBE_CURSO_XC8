


#include <xc.h>
#include "config.h"
#include "deco_catodo.h"

int contador=0;

void secuencia_1(){
    char aux = 0b000000001, i;
    PORTB=0;
    for(i=0; i<8; i++){
        PORTB= PORTB|(aux<<i); 
        __delay_ms(20);
    }
    aux=0b01111111;
    for(i=0;i<8; i++){
        PORTB = PORTB & (aux>>i);
        __delay_ms(20);
    }
}

void secuencia_2(){
    char aux = 0b000110000, i;
    PORTB=0;
    for(i=0; i<8; i++){
        PORTB= PORTB|(aux<<i);
        PORTB= PORTB|(aux>>i);
        __delay_ms(20);
    }
    aux = 0b01111111;
    for(i=0; i<8; i++){
        PORTB= PORTB&(aux>>i);
        __delay_ms(20);
    }
    aux = 0b000110000;
    for(i=0; i<8; i++){
        PORTB= PORTB|(aux<<i);
        PORTB= PORTB|(aux>>i);
        __delay_ms(20);
    }
    aux = 0b11111110;
    for(i=0; i<8; i++){
        PORTB= PORTB&(aux<<i);
        __delay_ms(20);
    }
    PORTB =0x00;
    __delay_ms(20);
}

void secuencia_3(){
    char i;
    PORTB = 0b01010101;
    PORTB = ~PORTB;
     __delay_ms(100);
    PORTB = ~PORTB;
     __delay_ms(100);
     
    
}


void main(void) {
    ADCON1=0x0F;
    TRISA = 0x01;
    TRISE = 0x04;
    TRISB = 0x00;
    TRISD = 0x00;
    
    
    while(1){
        if(PORTAbits.RA0 == 1){
            while(PORTAbits.RA0==1);
            contador++;
            if(contador>3)
                contador=1;
        }
        
        if(PORTEbits.RE3 == 0){
            while(!PORTEbits.RE3);
            contador--;
            if(contador<1)
                contador=3;
        }
        
        PORTD=deco_cc(contador);
        switch(contador){
            case 1: secuencia_1(); break;
            case 2: secuencia_2(); break;
            case 3: secuencia_3(); break;
        }
        
    }
    return;
}
