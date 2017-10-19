#include <stdio.h>

int main(){

   int n,i,j,k,l,ady;
	char c;
	FILE *fp=fopen("Entrada.in","r");

	//OBTIENE LA CANTIDAD DE VERTICES//
	fscanf(fp,"%d",&n);
	if(n < 0){
		printf("ERROR DE FORMATO EN EL ARCHIVO DE TEXTO (CANTIDAD DE VERTICES)\n");
		return 0;
	}
	if(n == 0){
		printf("EL GRAFO NO POSEE VERTICES (GRAFO NULO)\n");
		return 0;
	}
   printf("Número de vertices: %d\n", n);
   for (l = 1; l < n+1 ; l++)	{
		do{
			fscanf(fp,"%d%c",&ady,&c);
			if (ady>n||ady<0){
				printf("ERROR DE FORMATO EN EL ARCHIVO DE TEXTO (VERTICES ADYACENTES)\n" );
				return 1;
			}
			if(ady!=0){
				printf("Prueba: %d,%d\n", l,ady);
			}
		}while(c ==' '&& !feof(fp));
	}
   fclose(fp);
   return 0;
   /*
   char buff[255];

   fscanf(fp, "%s", buff);
   printf("1 : %s\n", buff );

   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );

   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);*/


}
