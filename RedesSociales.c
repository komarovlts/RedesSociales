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
   for(i = 0;i < cantidadVertices ; i++){
      for(j = 0 ; j < cantidadVertices; j++){
         printf("[ %d ]", matrizAdyacencia[i][j] );
      }
   printf("\n");
   }
   return;
}

int main(int argc, char const *argv[]) {
   int cantidadVertices,vertice,conexion;
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
   printf("\nLa matriz de adyacencia vacía es: \n");
   mostrarMatriz(cantidadVertices,matrizAdyacencia);
   //Recorrer el archivo imprimiendo cada uno de los números hasta el final del archivo.
   while(!feof(archivoObjetivo)){
         fscanf(archivoObjetivo,"%d%d",&vertice,&conexion);
         if(vertice > cantidadVertices  ||  vertice < 0){
            printf("ERROR DE FORMATO EN EL ARCHIVO DE TEXTO (VERTICES ADYACENTES)\n" );
            return 0;
         }
         if(vertice != 0  && conexion != 0  &&  !feof(archivoObjetivo)){
            //Parte superior de la matriz.
            matrizAdyacencia[vertice-1][conexion-1] = 1;
            //Parte inferior de la matriz.
            matrizAdyacencia[conexion-1][vertice-1] = 1;
         }
   }
   //Imprimir la matriz de adyacencia.
   printf("\nLa matriz de adyacencia es: \n");
   mostrarMatriz(cantidadVertices,matrizAdyacencia);
   //Cerrar el archivo -> buenas prácticas y evita errores.
   fclose(archivoObjetivo);
   return 0;
}
