#include <stdio.h>
#include <stdlib.h>

void crearMatrizVacia(int cantidadVertices, int matrizAdyacencia[cantidadVertices][cantidadVertices]){ // Matriz rellena con ceros (0).
   int i, j;
   for (i = 0; i < cantidadVertices; i++){
      for (j = 0; j < cantidadVertices; j++){
         matrizAdyacencia[i][j] = 0;
      }
   }
   return;
}

void mostrarMatriz(int cantidadVertices, int matrizAdyacencia[cantidadVertices][cantidadVertices]){
   int i,j;
   printf("La matriz de adyacencia vacía es: \n");
   for(i = 0;i < cantidadVertices ; i++){
      for(j = 0 ; j < cantidadVertices; j++){
         printf("[ %d ]", matrizAdyacencia[i][j] );
      }
   printf("\n");
   }
   return;
}

int main(int argc, char const *argv[]) {
   int cantidadVertices,vertice;
   char espacio;
   FILE *archivoObjetivo=fopen("Entrada.in","r");

   //Obtener la cantidad de vertices y adecuar la matriz a esa cantidad.
   fscanf(archivoObjetivo,"%d",&cantidadVertices);
   int matrizAdyacencia[cantidadVertices][cantidadVertices];
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
   //Creación de la matriz vacía.
   crearMatrizVacia(cantidadVertices,matrizAdyacencia);
   //Imprimir la matriz vacía.
   mostrarMatriz(cantidadVertices,matrizAdyacencia);
   //Recorrer el archivo imprimiendo cada uno de los números hasta el final del archivo.
   while(!feof(archivoObjetivo)){
         fscanf(archivoObjetivo,"%d%c",&vertice,&espacio);
         if(vertice > cantidadVertices  ||  vertice < 0){
            printf("ERROR DE FORMATO EN EL ARCHIVO DE TEXTO (VERTICES ADYACENTES)\n" );
            return 0;
         }
         if(vertice != 0  &&  !feof(archivoObjetivo)){
            //printf("Vertice: %d\n",vertice);
         }
   }
   //Cerrar el archivo -> buenas prácticas y evita errores.
   fclose(archivoObjetivo);
   return 0;
}
