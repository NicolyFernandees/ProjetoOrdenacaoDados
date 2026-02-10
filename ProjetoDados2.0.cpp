#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void imprimir(int A[], int n);
int* criarArranjo(int n);
void troca(int *x, int *y);
void sort(int A[], int n);
void imprimir(int A[], int n){
	for(int k=0; k < n; k++){
		printf("%d ", A[k]);
	}
	printf("\n");
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
	int n = 100;
	int * A = criarArranjo(n);
	sort;
	return 0;
}

void sort(int A[], int n){
	for (int j=1; j < n; j++){
		int key = A[j];
		int i=j-1;
		while (i<-1 && A[i]>key) {
			A[i+1] = A[i];
			i=i-1;
		}
		A[i+1] = key;
	}
}


