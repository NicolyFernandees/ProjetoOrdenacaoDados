#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

void imprimir(int A[], int n, int tempo);
void delay(int tempo_seconds);
int* criarArranjo(int n);
void troca(int *x, int *y);
void ordenacao_por_insercao(int A[], int n); //Inserction-sort	
void ordenacao_por_selecao(int A[], int n); //Select-sort
void ordenacao_bubble(int A[], int n); //Bubble-sort

int main(){
	clock_t t;
	int n = 100000;
	printf("Inteiro: %zu bytes \n", sizeof (int));
	printf("Inteiro em bits: %zu\n", sizeof (int) * CHAR_BIT);
	int * A = criarArranjo(n);
	imprimir(A, n, 0);
	t = clock();
	ordenacao_por_insercao(A, n);
	t = clock() - t;
	imprimir(A, n, 0);
	printf("\n\nTempo de execucao: %lf\n\n", ((double)t) / ((CLOCKS_PER_SEC/1000)));
	
	return 0;
}

void ordenacao_por_selecao(int A[], int n){
	for(int i=0; i < (n-1); i++){
		int indice_menor = i;
		for(int j=(i+1); j < n; j++){
			if( A [indice_menor] > A[j] ) indice_menor = j;
		}
		if( indice_menor != i)	trocar(&A [indice_menor],&A[i]);
	}
}

void ordenacao_por_insercao(int A[], int n){
	int chave, i;
	for(int j=1; j < n; j++){
		chave = A [j];
		i = j - 1;
		while( i > -1 && A[i] > chave){
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = chave;
	}
	
}

void ordenacao_bubble (int A[], int n){
	for(int i=0; i < (n-1); i++){
		for(int j=1; j < (n - i); j++){
			if(A[i] > A[j]) trocar (&A[i], &A[j]);
		}
	}
}

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

void troca(int *x, int *y){
	int aux = *x;
	*x = *y;
	*y = aux;
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


