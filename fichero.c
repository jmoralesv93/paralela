#include <stdio.h>
#include <stdlib.h>

#define NOM_ARCHIVO "utem.csv"

int main(void)
{
   FILE *entrada;
   int ch, num_lineas,num_lineas2;

   if ((entrada = fopen(NOM_ARCHIVO, "r")) == NULL){
      perror(NOM_ARCHIVO);
      return EXIT_FAILURE;
   }

   num_lineas = 0;
   while ((ch = fgetc(entrada)) != EOF)
      if (ch == '\n')
         num_lineas++;

   fclose(entrada);
   num_lineas2=num_lineas-1;
   printf("Numero de lineas: %d\n", num_lineas2);

   return EXIT_SUCCESS;
 }
