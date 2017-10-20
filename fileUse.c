#include <stdio.h>

int main(){

   int cantidadVertices,vertice;
	char espacio;
	FILE *archivoObjetivo=fopen("Entrada.in","r");

	//Obtener la cantidad de vertices.
	fscanf(archivoObjetivo,"%d",&cantidadVertices);
   //Para números negativos o algo similar al inicio del texto.
	if(cantidadVertices < 0){
		printf("ERROR DE FORMATO EN EL ARCHIVO DE TEXTO (CANTIDAD DE VERTICES)\n");
		return 0;
	}
   //Si no existen vertices, grafo nulo.
	if(cantidadVertices == 0){
		printf("EL GRAFO NO POSEE VERTICES (GRAFO NULO)\n");
		return 0;
	}
   //Imprimir la cantidad de vertices (primer número del archivo).
   printf("Número de vertices: %d\n", cantidadVertices);
   //Recorrer el archivo imprimiendo cada uno de los números hasta el final del archivo.
   while(!feof(archivoObjetivo)){
			fscanf(archivoObjetivo,"%d%c",&vertice,&espacio);
			if(vertice > cantidadVertices  ||  vertice < 0){
				printf("ERROR DE FORMATO EN EL ARCHIVO DE TEXTO (VERTICES ADYACENTES)\n" );
				return 1;
			}
			if(vertice != 0  &&  !feof(archivoObjetivo)){
				printf("Vertice: %d\n",vertice);
			}
	}
   //Cerrar el archivo -> buenas prácticas y evita errores.
   fclose(archivoObjetivo);
   return 0;
}
