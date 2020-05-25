
#ifndef deco_catodo_H
#define	deco_catodo_H

#include <xc.h> // include processor files - each processor file is guarded.  


char deco_cc(char numero){
    char myDeco=0;
    
    switch(numero){
        case 0: myDeco=64; break;
        case 1: myDeco=121; break;
        case 2: myDeco=36; break;
        case 3: myDeco=48; break;
        case 4: myDeco=25; break;
        case 5: myDeco=18; break;
        case 6: myDeco=2; break;
        case 7: myDeco=120; break;
        case 8: myDeco=0; break;
        case 9: myDeco=16; break; 
    }
    return (127-myDeco);  
}


#endif	/* XC_HEADER_TEMPLATE_H */

