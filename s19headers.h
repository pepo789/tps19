/* 
 * File:   s19headers.h
 * Author: pedro
 *
 * Created on December 24, 2014, 2:36 PM
 */

#ifndef S19HEADERS_H
#define	S19HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definiendo máximos----------------
#define MAXLINE 530 //máximo que puede tener una linea del S19
#define PAGE 65536//memoria total del hc11
#define TOPFILA 16//máximo que puedo imprimir por linea en el parse
#define NAMESIZE 50 //número de chars alojados para guardar el nombre del output

//defino offsets--------------
#define DIROFFSET 4 //offset que me da la direccion de inicio del segmento de codigo (ocupa 4 caracteres)
#define HIGHLARGO 2 //lugar que ocupa el nibble menos significativo del largo en las lineas a procesar
#define LOWLARGO 3 //lugar que ocupa el nibble mas significativo del largo en las lineas a procesar
#define S1 2 //cantidad de chars que ocupa al principio de cada linea el "S1"
#define SEGMENTLENGTH 2 //cantidad de chars que ocupa el largo en cada linea a procesar

//validación
#define CORRECT_CHECKSUM 1
#define ERROR_CHECKSUM 0

//extensión
#define EXTENTION "parse"
typedef unsigned char BYTE;



//----------------_.:PROTOTIPOS:._----------------------

//levantando el archivo y las lineas --openfile.c
FILE * ReadFile(char * filename);
char * LoadLine(FILE * ptr2file);

//checksum 
int CheckSum(char * ptr2line);
BYTE GetCheckNumber(char * ptr2line);

//procesando el archivo de texto a memoria --file2memory.c
BYTE * CreateMemorySpace(void);
int ProcessFile(FILE * ptr2file,char * Currentline, BYTE * ptr2space);
void CopySegment(char * ptr2line,BYTE * ptr2space);

//parseando a un archivo de texto --parse.c
void ParseCode(BYTE * ptr2space,char * filename);
char * NameOutput(char * filename);

//transformando ASCII a BYTES -- ASCII2BYTE.c
BYTE Ascii2Int(char a,char b);
BYTE checkAscii(char c);

//contadores -- esta sección de funciones es para ayudar al usuario a encontrar el error en su archivo. --linecounter.c
//contadores de lineas leidas
unsigned int IncrementCounter(void);
unsigned int ReadLineCounter(void);

//contadores de lineas copiadas a memoria
unsigned int IncrementCopiedCounter(void);
unsigned int ReadCopiedLineCounter(void);

void ReportOperation(void);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* S19HEADERS_H */

