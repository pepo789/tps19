#include "s19headers.h"
/* ++++++++++++++++++++++++++++++++++++ 
   En esta hoja de funciones levanto el archivo pedido y linea por linea.*/


FILE * ReadFile(char * filename) //ordeno el main haciendo funciones chiquitas que separen el trabajo
{
    FILE * ptr2file=NULL;
    
    if (  (ptr2file = fopen(filename,"rb")) == NULL ) //si el archivo no existe o no se puede abrir, devuelvo error
        printf("el archivo no existe o no se puede abrir.");
       
    else
      printf("Archivo cargado con éxito.\n");//en caso contrario devuelvo el puntero al archivo
            
        
    return ptr2file;
}



char * LoadLine(FILE * ptr2file) // con esta funcion levanto linea a linea
{
    
    char * ptr2line = NULL;
    
    if ( (ptr2line = calloc(MAXLINE,sizeof(char))) == NULL ) //devuelvo error si no me dejan alocar memoria
        printf("Error. No hay suficiente memoria para cargar una linea.");
        
    else{
     
            do{ //loopeo las lineas hasta que encuentro el S1.
                
                IncrementCounter(); //cuento las lineas leidas a partir de 1.
                printf("Reading line.....%d\n", ReadLineCounter() ); //imprimo el numero de linea que estoy leyendo.
                
               ptr2line = fgets(ptr2line,MAXLINE,ptr2file);}
            while( (ptr2line) && (ptr2line[1]!='1')  ); //esta condicion busca lineas hasta el final del archivo o hasta el S1.

    }
    return ptr2line;
}







