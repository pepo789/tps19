#include "s19headers.h"
/* El analisis de checksum se divide en dos partes, una que analiza el checksum de la linea procesada, y otra que realiza la suma para su validez.*/


int CheckSum(char * ptr2line) //funcion que evalua el checksum de la linea. es el primero en realizarse porque si el checksum no corresponde, no se procesa la linea
{ 
    int cantidadbytes,bytescontados,validation;
    BYTE total=0;
    
    cantidadbytes = 2*Ascii2Int(ptr2line[HIGHLARGO],ptr2line[LOWLARGO]); //busco la cantidad de bytes para hacer el checksum en la linea procesada
    
    for(bytescontados=0 ; bytescontados < cantidadbytes; bytescontados=bytescontados+2)
    {
        total= total + Ascii2Int(ptr2line[2 + bytescontados],ptr2line[2 + bytescontados + 1]); //voy sumando uno a uno los bytes para verificar el checksum
    }
    total=~total; //hago el complemento a uno para hacer la comparacion
     
            if ( total == GetCheckNumber(ptr2line) )  { //si el valor al que llegue coincide con el de la linea, entro acá
                validation = CORRECT_CHECKSUM; //hago n define en vez de un 1 porque queda lindo
                printf("CheckNum....Success! :D\n"); 
                } 
    
            else    {
                validation = ERROR_CHECKSUM;
                printf("Bad checknum :C Error in line: %d \n", ReadLineCounter() );
                } 
    
    return validation;
}

// --------------------------BARRA SEPARADORA DE FUNCIONES DE BAJO PRESUPUESTO--------------

BYTE GetCheckNumber(char * ptr2line)
{
    int offset=0; //esta variable tendra adentro el lugar que ocupa el numero checksum, que esta al final de la linea, respecto del inicio.
    BYTE CheckNumber;
    
    offset =  2 + 2*Ascii2Int(ptr2line[HIGHLARGO],ptr2line[LOWLARGO]); //leo el checksum de la linea para compararlo con el que llegue yo

    CheckNumber = Ascii2Int(ptr2line[offset],ptr2line[offset+1]);
   
    return CheckNumber;
}
