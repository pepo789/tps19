#include "s19headers.h"

/*El trabajo de transferir el S19 a memoria consta de 3 partes; crear el espacio de memoria, procesar el archivo S19 linea a linea y copiar cada segmento*/


BYTE * CreateMemorySpace(void)
{
    BYTE * ptr2space;
    
    if( (ptr2space = calloc(PAGE,sizeof(BYTE)) ) == NULL )
        printf("Error. No hay suficiente memoria para crear el mapa del HC11");
      
  return ptr2space;
            
}

// --------------------------BARRA SEPARADORA DE FUNCIONES DE BAJO PRESUPUESTO--------------
int ProcessFile(FILE * ptr2file,char * Currentline, BYTE * ptr2space)
{
    int linecheck,linescounter;
    
        do {
            Currentline = LoadLine(ptr2file); //cargo la linea en memoria para procesar

                    if(Currentline) //proceso solamente si pude cargar la linea correctamente
                    {          
                        linecheck = CheckSum(Currentline); //compruebo que los datos de la linea no están corruptos
                        
                        if(linecheck) //si no estan corruptos, la paso a memoria.
                        CopySegment(Currentline,ptr2space);
                    }
            
            free(Currentline);
            
        }while(Currentline); //loopeo hasta el final del archivo
}

// --------------------------BARRA SEPARADORA DE FUNCIONES DE BAJO PRESUPUESTO--------------

void CopySegment(char * ptr2line,BYTE * ptr2space)
{
    int startdir,codelength,charcounter,bytecounter;
 
            printf("Copying line %d to memory.\n\n",ReadLineCounter() ); //reporto el numero de linea que estoy leyendo.
            IncrementCopiedCounter();
            
    startdir = Ascii2Int(ptr2line[4],ptr2line[5])*64 + Ascii2Int(ptr2line[6],ptr2line[7]); //cargo como direccion de inicio del segmento la que me indica la linea en el respectivo espacio
    codelength = Ascii2Int(ptr2line[HIGHLARGO],ptr2line[LOWLARGO])-4; //cargo el largo total del segmento, dato que saco de la linea
    
    for(charcounter=0 , bytecounter=0 ; bytecounter<=codelength; charcounter = charcounter + 2, bytecounter++ )
        ptr2space[startdir + bytecounter] = Ascii2Int(ptr2line[8+charcounter],ptr2line[8+charcounter+1]); //loopeo los datos que recibo de la linea en ASCII al mapa de memoria creado por el programa, a partir de la direccion correspondiente.
    
    
}
