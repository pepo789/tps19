#include "s19headers.h"

unsigned int linecounter=0,copiedline=0;

unsigned int IncrementCounter(void)
{
    linecounter++;
            return linecounter;
}

unsigned int ReadLineCounter(void)
{
    return linecounter;
}

unsigned int IncrementCopiedCounter(void)
{
    copiedline++;
            return copiedline;
}

unsigned int ReadCopiedLineCounter(void)
{
    return copiedline;
}

void ReportOperation(void)
{
    linecounter--;
    
    printf("\nTotal de lineas leidas:\t\t%d\n\n",linecounter);
    printf("total de lineas copiadas a memoria: %d\n\n",copiedline);
}