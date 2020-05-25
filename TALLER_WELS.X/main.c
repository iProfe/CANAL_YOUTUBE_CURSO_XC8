/*
 * File:   main.c
 * Author: Usuario
 *
 * Created on 21 de mayo de 2020, 07:50 PM
 */

#define Boton1 PORTBbits.RB0
#define Boton2 PORTBbits.RB1
#define Boton3 PORTBbits.RB2
#define m1 PORTDbits.RD0
#define m2 PORTDbits.RD1
#define E PORTDbits.RD2

#include <xc.h>
#include "config.h"

void antiHorario(){
    m1=0;
    m2=1;
}

void Horario(){
    m1=1;
    m2=0;
}

void test_sentido(){
        if(Boton1==1 && Boton2==0){
            antiHorario();
        }
        if(Boton1==0 && Boton2==1 ){
            Horario();
        } 
        if(Boton1==0 && Boton2==0 ){
            m1=0;
            m2=0;
        }
         if(Boton1==1 && Boton2==1 ){
            m1=0;
            m2=0;
        }
        
}

void main(void) {
    
    ADCON1 = 0x0F;
    TRISB = 0xFF;
    TRISD = 0x00;
    
    while(1){
        
        if(Boton3==0){
            E=1;
        }
        else{
            E=0;
        }
        test_sentido();
        
        
    }
    
    return;
}
