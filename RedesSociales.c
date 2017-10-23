#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
   printf("[ %d ]", verticeAdyacente -> verticeConectado);
   return;
}

void mostrarVertice(Vertice* vertice){
	printf("Vertice: %d -> ", vertice -> numeroVertice);
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
   Vertice* verticeAux = listaAdyacencia.inicio;
	while(verticeAux -> siguiente != NULL){
		mostrarVertice(verticeAux);
		verticeAux = verticeAux -> siguiente;
	}
	mostrarVertice(verticeAux);
	printf("\n");
}

void mostrarCliques(int cantidadVertices, int matrizAdyacencia[cantidadVertices][cantidadVertices]){
   //Inicializador de parametros para toma de tiempo.
   clock_t tiempoInicial, tiempoFinal;
   double tiempoTotal;
   int m;
   //Fin de inicialización.
   //Toma de tiempo.
   tiempoInicial = clock();
   //Inicio del algoritmo.
   int i,u,v,w,x,contador;
   int clique[4];
   clique[1] = 0; clique[2] = 0; clique[3] = 0; clique[4] = 0;
   for (u = 0; u < cantidadVertices; u++){
      for (v = 0; v < cantidadVertices; v++){
         for (w = 0; w < cantidadVertices; w++){
            for (x = 0; x < cantidadVertices; x++){
               if(u != v  &&  matrizAdyacencia[u][v] == 1 &&
                  u != w  &&  matrizAdyacencia[u][w] == 1 &&
                  u != x  &&  matrizAdyacencia[u][x] == 1 &&
                  v != w  &&  matrizAdyacencia[v][w] == 1 &&
                  v != x  &&  matrizAdyacencia[v][x] == 1 &&
                  w != x  &&  matrizAdyacencia[w][x] == 1){
                     contador = 0;
                     if(clique[1] == 0 && clique[2] == 0 && clique[3] == 0 && clique[4] == 0){
                        clique[1] = u; clique[2] = v; clique[3] = w; clique[4] = x;
                        printf("%d ,%d ,%d, %d conforman un grupo de mejores amigos.\n",u+1 ,v+1 ,w+1 ,x+1 );
                     }
                     else{
                        for (i = 0; i < 4; i++) {
                           if(clique[i] == u){
                              contador++;
                           }
                        }
                        for (i = 0; i < 4; i++) {
                           if(clique[i] == v){
                              contador++;
                           }
                        }
                        for (i = 0; i < 4; i++) {
                           if(clique[i] == w){
                              contador++;
                           }
                        }
                        for (i = 0; i < 4; i++) {
                           if(clique[i] == x){
                              contador++;
                           }
                        }
                        if(contador != 3){
                           clique[1] = u; clique[2] = v; clique[3] = w; clique[4] = x;
                           printf("%d ,%d ,%d, %d conforman un grupo de mejores amigos.\n",u+1 ,v+1 ,w+1 ,x+1 );
                           contador = 0;
                        }
                     }
               }
            }
         }
      }
   }
   //Fin del algoritmo.
   //Calculo de tiempo.
   tiempoFinal = clock();
   tiempoTotal = (double)(tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC;
   printf("[Tiempo total tomado por la CPU para conseguir los grupos de mejores amigos es: %.16g milisegundos]\n\n", tiempoTotal* 1000.0);
   return;
}

int buscarVerticeInicial(int cantidadVertices, int matrizAdyacencia[cantidadVertices][cantidadVertices]){
	int i;
	for(i = 0; i < cantidadVertices; i++){
		if(matrizAdyacencia[0][i] == 1){
			return 0;
		}
	}
	return 1;
}

int nuevoVerticeInicial(int marcados[], int recorridos[], int cantidadVertices){
	int i;
	for (i = 0; i < cantidadVertices; i++){
		if (marcados[i] != recorridos[i] && recorridos[i] == 0){
			return i;
		}
	}
	return -1;
}

int agenteVinculo(int cantidadVertices, int copiaMatrizAdyacencia[cantidadVertices][cantidadVertices], int verticeInicial){
   int i,j,k,verificador;
   int marcados[cantidadVertices];
	int recorridos[cantidadVertices];
	for (i = 0; i < cantidadVertices ; i++){
		marcados[i] = 0;
      recorridos[i] = 0;
	}
	while(verticeInicial != -1){
		marcados[verticeInicial] = 1;
		for(j = 0; j < cantidadVertices; j++){
			if(copiaMatrizAdyacencia[verticeInicial][j] == 1){
				marcados[j] = 1;
			}
		}
		recorridos[verticeInicial] = 1;
		verticeInicial = nuevoVerticeInicial(marcados, recorridos, cantidadVertices);
	}
	verificador = 0;
	for(k = 0; k < cantidadVertices; k++){
		if(marcados[k] == 1){
			verificador++;
		}
	}
	if(verificador < cantidadVertices-1){
		return 1;
	}
   else{
		return 0;
	}
}

void buscarArticulacion(int cantidadVertices, int matrizAdyacencia[cantidadVertices][cantidadVertices]){
   //Inicializador de parametros para toma de tiempo.
   clock_t tiempoInicial, tiempoFinal;
   double tiempoTotal;
   int m;
   //Fin de inicialización.
   //Toma de tiempo.
   tiempoInicial = clock();
   //Inicio del algoritmo.
	int i,j,k,h,vertice,verticeInicial,articulacion;
   int copiaMatrizAdyacencia[cantidadVertices][cantidadVertices];
	for(i = 0; i < cantidadVertices; i++){
		vertice = 0;
      //Copiar Matriz.
   	for (k = 0; k < cantidadVertices; k++){
   	    for (h = 0; h < cantidadVertices; h++){
   	    	copiaMatrizAdyacencia[k][h] = matrizAdyacencia[k][h];
   		}
   	}
      //Fin copia de Matriz.
		for(j = 0; j < cantidadVertices; j++){
			copiaMatrizAdyacencia[i][j] = 0;
			copiaMatrizAdyacencia[j][i] = 0;
		}
		verticeInicial = buscarVerticeInicial(cantidadVertices, copiaMatrizAdyacencia);
		articulacion = agenteVinculo(cantidadVertices, copiaMatrizAdyacencia, verticeInicial);
		if(articulacion == 1){
			printf("%d es un agente de vinculo\n", i+1);
		}
	}
   //Fin del algoritmo.
   //Calculo de tiempo.
   tiempoFinal = clock();
   tiempoTotal = (double)(tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC;
   printf("[Tiempo total tomado por la CPU para conseguir los agentes de vinculo es: %.16g milisegundos]\n\n", tiempoTotal* 1000.0);
   return;
}

int main(int argc, char const *argv[]) {
   /*//Inicializador de parametros para toma de tiempo.
   clock_t tiempoInicial, tiempoFinal;
   double tiempoTotal;
   int m;
   //Fin de inicialización.
   //Toma de tiempo.
   tiempoInicial = clock();
   //Inicio del programa.*/
   int i,j,cantidadVertices,vertice,conexion;
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
   //Información.
   printf("\n******************************************************************************************\n");
   printf("*******************************Informacion Adicional**************************************\n");
   //Imprimir la cantidad de vertices (primer número del archivo).
   printf("Numero de vertices: %d\n", cantidadVertices);
   //Creación de la matriz vacía.
   vaciarMatriz(cantidadVertices,matrizAdyacencia);
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
   printf("\nLa lista de adyacencia es:\n");
   mostrarListaAdyacencia();
   printf("***************************Fin Informacion Adicional**************************************\n\n");
   printf("*****************************Informacion Solicitada***************************************\n\n");
   buscarArticulacion(cantidadVertices, matrizAdyacencia);
   printf("------------------------------------------------------------------------------------------\n\n");
   mostrarCliques(cantidadVertices,matrizAdyacencia);
   /*printf("------------------------------------------------------------------------------------------\n\n");
   //Fin del programa.
   //Calculo de tiempo.
   tiempoFinal = clock();
   tiempoTotal = (double)(tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC;
   printf("[Tiempo total tomado por la CPU para la ejecución del programa es: %.16g milisegundos]\n\n", tiempoTotal* 1000.0);*/
   printf("*******************************Fin del Programa*******************************************\n");
   return 0;
}
