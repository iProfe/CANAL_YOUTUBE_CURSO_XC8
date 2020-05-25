/*
 * File:   main.c
 * Author: Usuario
 *
 * Created on 18 de mayo de 2020, 08:18 PM
 */


#include <xc.h>
#include "config.h"
#include "deco_catodo.h"
int i;
char num1, num2, result, unidad, decena;
void main(void) {
    TRISA = 0x00;
    TRISB = 0xFF;
    TRISD = 0x00;
    while(1){
        num1 = PORTB & 0b00001111;       
        num2 = (PORTB & 0b11110000)>>4;
        result=num1+num2;
        decena = result / 10;
        unidad = result % 10;
        PORTA = deco_cc(decena);
        PORTD = deco_cc(unidad);
    }
    return;
}
