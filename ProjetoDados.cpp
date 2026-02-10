#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void imprimir(int A[], int n, int tempo);
void delay(int number_of_seconds);
int* criarArranjo(int n);
void troca(int *x, int *y);

void imprimir(int A[], int n, int tempo){
	for(int k=0; k < n; k++){
		printf("%d ", A[k]);
	}
	delay(tempo);
	printf("\n");
}

void delay(int number_of_seconds){
	int milli_seconds = 1000 * number_of_seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);
}

int* criarArranjo(int n){
	int* arrajo = (int*) malloc(n * sizeof(int));
	if (arrajo == NULL){
		printf("Problema na alocação Memohria!\n");
		exit(1);
	}
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		arrajo[i] = rand() % (n*2);
	}
	return arrajo;
}

void troca(int *x, int *y){
	int aux = *x;
	*x = *y;
	*y = aux;
}

int main(){
	clock_t t;
	int n = 100;
	t = clock();
	 int * A = criarArranjo(n);
	 t = clock() - t;
	 printf("\n\nTempo de execucao: %lf\n\n", ((double)t) / ((CLOCKS_PER_SEC/1000)));
	 return 0;
}
