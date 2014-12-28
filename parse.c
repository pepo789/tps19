#include "s19headers.h"

/*EL parse consta de dos partes, una que le asigna el nombre correspondiente al archivo de salida y una que lo rellena con el contenido correspondiente.*/

void ParseCode(BYTE * ptr2space,char * filename)
{
    FILE * ptr2parse;
    int fila,bytes;
    
    ptr2parse = fopen( NameOutput(filename) ,"wb+"); //creo el archivo para imprimir el parseo
    
    fprintf(ptr2parse,"\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\tA\tB\tC\tD\tE\tF\n0\t"); //hago el header del parseo para ayudar a guiarse
    
  for(bytes=0,fila=0  ;  bytes<=PAGE  ;  bytes++,fila++) //imprimo el mapa de memoria entero
    {
                    if(fila == TOPFILA){ //pongo un enter cada 16 bytes, tambien imprimo la direccion en la que estoy imprimiendo en el momento
                    fprintf(ptr2parse,"\n%X\t",bytes);
                    fila=0; }
                  
        fprintf(ptr2parse,"%X\t",ptr2space[bytes]); //conesta linea imprimo el byte en hexadecimal mayúscula.
    }
}

char * NameOutput(char * filename)
{
    char * newname,* auxptr,extseek; //creo el puntero y el espacio para el nombre del archivo parseado 
    
    newname = calloc( NAMESIZE , sizeof(char) );
    
    strcpy(newname,filename); //en principio mantengo el nombre del archivo de input. Pero quiero cambiar la extención.
    
    for(extseek=0 ; extseek<= NAMESIZE ; extseek++)
    {
        if(newname[extseek] == 'S' && newname[extseek+1] == '1' && newname[extseek+2] == '9') //busco el lugar donde tengo la extensión
            break;
    }
    
        auxptr = &(newname[extseek]); //asigno un puntero auxiliar al lugar donde empieza la extension, para luego cambiarlo
        
        strcpy(auxptr,EXTENTION);
        
   return newname;
}
