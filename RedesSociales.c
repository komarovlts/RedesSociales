#include <stdio.h>
#include <stdlib.h>

int vertices = 5;
int matriz[5][5];

void crearMatrizVacia(){ // Matriz rellena con ceros (0).
   int i, j;
   for (i = 0; i < vertices; i++){
      for (j = 0; j < vertices; j++){
         matriz[i][j] = 0;
      }
   }
   return;
}

void mostrarMatriz(){
   int i,j;
   for(i = 0;i < vertices ; i++){
      for(j = 0 ; j < vertices; j++){
         printf("[ %d ]", matriz[i][j] );
      }
   printf("\n");
   }
   return;
}

int main(int argc, char const *argv[]) {
   crearMatrizVacia();
   mostrarMatriz();
   return 0;
}
