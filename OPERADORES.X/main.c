
#include <xc.h>
#include "configuraciones.h"

int palabra=0b10011001, rotador=0;
int numero = 1219;

void main(void) {
    TRISD = 0x00;
    TRISC = 0x00;
    while(1){
       
        PORTC= numero>>8;
        PORTD= numero;
       
    }
    return;
}
