/* 
 * File:   main.c
 * Author: pedro
 *
 * Created on December 24, 2014, 2:13 PM
 */

#include "s19headers.h"

/*
 * 
 */
int main(int argc, char** argv) {
               
 FILE * ptr2file = NULL; //creo los punteros que voy a usar. al espacio a ocupar, al archivo S19
 BYTE * ptr2space = NULL; //y a la fila que en el momento esta procesandose.
 char * Currentline = NULL;
    
         ptr2space = CreateMemorySpace(); //creo el espacio a ocupar.
            if( !(ptr2space) ) //checkeo si pude armar la página que quize levantar
                return;
            
         ptr2file = ReadFile(argv[1]); //levanto el archivo pasado por linea de comando.
            if( !(ptr2file) ) //checkeo si pude levantar el archivo pedido.
                return;
    
    ProcessFile(ptr2file,Currentline,ptr2space); //en esta funcion levanto las lineas y copio a memoria.
    
    
    ParseCode(ptr2space,argv[1]); //escribo el mapa de memoria ordenadamente en un archivo de texto.
   
  ReportOperation(); //imprimo en terminal el total de lineas leidas y copiadas  
  fclose(ptr2file);
  free(ptr2space);
    
  return (EXIT_SUCCESS);
}

