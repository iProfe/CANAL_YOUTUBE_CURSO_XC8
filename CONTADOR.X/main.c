/*
 * File:   main.c
 * Author: Usuario
 *
 * Created on 19 de mayo de 2020, 04:35 PM
 */
#define D1 PORTEbits.RE0
#define D2 PORTEbits.RE1

#include <xc.h>
#include "config.h"
#include "deco_catodo.h"

char  tiempo_m=14, unidad, decena;
int numero=98;
void v_display(){
        unidad=numero%10;
        decena=numero/10;
        D1=0;
        D2=1;
        PORTD = deco_cc(decena);
        __delay_ms(tiempo_m);
        D1=1;
        D2=0;
        PORTD = deco_cc(unidad);
         __delay_ms(tiempo_m);
}

void main(void) {

    ADCON1 = 0x0F;
    TRISD = 0x00;
    TRISEbits.RE0 = 0;
    TRISEbits.RE1 = 0;
    D1=1;
    D2=0;
    
    
    
    while(1){
        
        if(PORTAbits.RA0 == 1){
            while(PORTAbits.RA0 == 1){
                v_display();
            }
            numero++;
            if(numero>99)
                numero=0;
        }
        if(PORTAbits.RA1 == 1){
            while(PORTAbits.RA1 == 1){
                v_display();
            }
            numero--;
            if(numero<0)
                numero=99;
        }
        
        v_display();
    }
    return;
}
