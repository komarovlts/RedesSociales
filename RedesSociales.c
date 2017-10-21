#include <stdio.h>
#include <stdlib.h>

//Declaración de estructuras para la lista de adyacencia.
typedef struct verticeAdyacente{
   int verticeConectado;
   struct verticeAdyacente *siguiente;
}VA;

typedef struct Vertice{
   int numeroVertice;
   int longitud;
   VA *inicio;
   struct Vertice *siguiente;
}Vertice;

typedef struct listaAdyacencia{
   Vertice *inicio;
}LA;

//Declaración de variables globables.
LA listaAdyacencia;
int longitudLA;
int longitudVA;

void inicializarListaAdyacencia(){
   listaAdyacencia.inicio = NULL;
   longitudLA = 0;
   return;
}

void vaciarMatriz(int cantidadVertices, int matrizAdyacencia[cantidadVertices][cantidadVertices]){ // Matriz rellena con ceros (0).
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

Vertice* crearVertice(int numeroVertice){
   Vertice* vertice = (Vertice*)malloc(sizeof(Vertice));
   vertice->numeroVertice = numeroVertice;
   vertice->longitud = 0;
   vertice->inicio = NULL;
   vertice->siguiente = NULL;
   return vertice;
}

VA* crearVerticeAdyacente(int verticeConectado){
   VA* verticeAdyacente = (VA*)malloc(sizeof(VA));
   verticeAdyacente->verticeConectado = verticeConectado;
   verticeAdyacente->siguiente = NULL;
   return verticeAdyacente;
}

void agregarVertice(Vertice* vertice){
   int i;
	if(listaAdyacencia.inicio == NULL){
		listaAdyacencia.inicio = vertice;
		longitudLA = 1;
		return;
	}
	else{
		Vertice * verticeAux = listaAdyacencia.inicio;
		for (i = 0; i < longitudLA-1; i++){
			verticeAux = verticeAux -> siguiente;
		}
		verticeAux -> siguiente = vertice;
		longitudLA++;
		return;
		}
}

void agregarVerticeAdyacente(Vertice* verticeObjetivo, VA* verticeAdyacente){
   int i;
   Vertice* verticeAux = verticeObjetivo;
	if(verticeAux->inicio == NULL){
		verticeAux->inicio = verticeAdyacente;
		verticeAux->longitud = 1;
		return;
	}
	else{
		VA* verticeAdyacenteAux = verticeAux->inicio;
		for (i = 0; i < verticeAux->longitud-1; i++){
			verticeAdyacenteAux = verticeAdyacenteAux -> siguiente;
		}
		verticeAdyacenteAux -> siguiente = verticeAdyacente;
		verticeAux->longitud++;
		return;
		}
}

void crearListaAdyacencia(int cantidadVertices, int matrizAdyacencia[cantidadVertices][cantidadVertices]){
   int i;
   for (i = 0; i < cantidadVertices; i++){
      Vertice* vertice = crearVertice(i+1);
      agregarVertice(vertice);
   }
}

void rellenarListaAdyacencia(int cantidadVertices, int matrizAdyacencia[cantidadVertices][cantidadVertices]){
   int i,j;
   for (i = 0; i < cantidadVertices; i++){
      for (j = 0; j < cantidadVertices; j++){
         if (matrizAdyacencia[i][j] == 1) {
            Vertice * verticeAux = listaAdyacencia.inicio;
         	while(verticeAux->numeroVertice != i+1   ){
         		verticeAux = verticeAux -> siguiente;
         	}
            VA* verticeAdyacente = crearVerticeAdyacente(j);
            verticeAdyacente -> verticeConectado = j+1;
            agregarVerticeAdyacente(verticeAux,verticeAdyacente);
         }
      }
   }
   return;
}

void mostrarVerticeAdyacente(VA* verticeAdyacente) {
   printf("  %d  ", verticeAdyacente -> verticeConectado);
   return;
}

void mostrarVertice(Vertice* vertice){
	printf("Vertice: %d ->", vertice -> numeroVertice);
   VA* verticeAdyacenteAux = vertice->inicio;
	while(verticeAdyacenteAux-> siguiente != NULL){
		mostrarVerticeAdyacente(verticeAdyacenteAux);
		verticeAdyacenteAux = verticeAdyacenteAux -> siguiente;
	}
	mostrarVerticeAdyacente(verticeAdyacenteAux);
	printf("\n");
   return;
}

void mostrarListaAdyacencia(){ // Sólo para uso del Desarrollador.
   printf("\n");
   Vertice* verticeAux = listaAdyacencia.inicio;
	while(verticeAux -> siguiente != NULL){
		mostrarVertice(verticeAux);
		verticeAux = verticeAux -> siguiente;
	}
	mostrarVertice(verticeAux);
	printf("\n");
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
   vaciarMatriz(cantidadVertices,matrizAdyacencia);
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
   //Fin de lectura del archivo.
   //Creación de lista de adyacencia.
   inicializarListaAdyacencia();
   crearListaAdyacencia(cantidadVertices,matrizAdyacencia);
   rellenarListaAdyacencia(cantidadVertices,matrizAdyacencia);
   mostrarListaAdyacencia();



   return 0;
}
