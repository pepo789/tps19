#include "s19headers.h"
/*EL trabajo de transformar un ASCII a un entero consta de 2 partes; una que lee el ASCII y otra que lo transforma a BYTE*/

BYTE Ascii2Int(char a,char b)
{
	BYTE byte; //variable a devolver transformada
	
	byte = checkAscii(a)*16 + checkAscii(b); //al nibble mas significativo lo multiplico por 16, asi represento correctamente el BYTE

	return byte;

}

// --------------------------BARRA SEPARADORA DE FUNCIONES DE BAJO PRESUPUESTO--------------
BYTE checkAscii(char c) //funcion que se fija si el char es una letra minuscula, una letra mayuscula o un numero
{
	BYTE transformed;

	if(c<'A') { //SI el ASCII coincide con un numero, entro en esta condicion
		transformed = c-'0';
		return transformed; }		
		
	else if(c<'a') { //SI el ASCII coincide con una letra mayuscula, entra en esta condicion
		transformed = c-'A' + 10;
		return transformed; }

	else	{ // si es una letra minuscula, entrara en este caso.
		transformed = c - 'a' + 10;
		return transformed; }
	
}
