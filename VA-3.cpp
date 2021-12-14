#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void gerarVetor(int vet[], int num);
void imprimirVetor(int vetor[], int num);
void bubbleSort(int vet[], int num);
int  select(int vet[], int num);
void selectionSort(int vet[], int num);
void insert(int x, int vet[], int num);
void insertionSort(int vet[], int num);

#define tamanho 10
int main() {

	setlocale(LC_ALL, "Portuguese");

	/*int tamanho;
	printf("insira a quantidade de numeros a serem trabalhados: \n");
	scanf("%d", tamanho);*/
	
	int vetor[tamanho];
	char op;
	
	gerarVetor(vetor, tamanho);
	
	printf("b para BubbleSort, s para SelectionSort ou i para InsertionSort \n");
	scanf("%c", &op);
	clock_t t; 
 	
 	int p, r;
 	p = 0;
	r = tamanho;
	
	
	switch (op) {
		case 'b' :
			t = clock(); 
			bubbleSort(vetor, tamanho);
			imprimirVetor(vetor, tamanho);
			t = clock() - t; 
		break;	
		case 's' :
			t = clock();
			selectionSort(vetor, tamanho);
			imprimirVetor(vetor, tamanho);
			t = clock() - t;
		break;	
		case 'i' :
			t = clock();
			insertionSort(vetor, tamanho);
			imprimirVetor(vetor, tamanho);
			t = clock() - t;
		break;	
	}	
	
	printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC)));	
	
	return 0;
	 
}
void gerarVetor(int vet[], int num) {
 
 srand(time(NULL));
	
	for (int i = 0; i < num; i++) {
		vet[i] = rand() % 100 + 1;
	}
}



void imprimirVetor(int vet[], int num) {
	
		for (int i = 0; i < num; i++) {
			printf("%5d ", vet[i]);
	}
		printf("\n");
	
}

void bubbleSort(int vet[], int num) {
	
	int aux, trocar = 0;
	
	for (int i = 1; i <= num - 1; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (vet[j] > vet[j + 1]) {
				printf("Trocar %d por -> %d\n", vet[j], vet[j + 1]);
				aux = vet[j + 1];
				vet[j+1] = vet[j];
				vet[j] = aux;	
				trocar++;
			}
			
		}
		imprimirVetor(vet, num);
	}
	printf("Numero de trocas: %d\n", trocar);
}

int select(int vet[], int num) {
	int i = 0;
	for (int j = 1; j < num; j++) {
		if (vet[i] < vet[j]) {
			i = j;
		}
	}
	
	return i;
}

void selectionSort(int vet[], int num) {
	int aux;
	while (num > 1) {		
		int k = select(vet, num);
		printf("Indice: %d \t Maior valor: %d\n ", select(vet, num), vet[select(vet, num)]);
		
		aux = vet[num - 1];
		vet[num - 1] = vet[select(vet, num)];
		vet[select(vet, num)] = aux; 
		
		printf("Trocar %d -> por %d\n", vet[k], vet[num - 1]);
		imprimirVetor(vet, num);

		num--;
	}
}

void insert(int x, int vet[], int num) {
	while (num > 0 && x < vet[num - 1]) {
		vet[num] = vet[num - 1];
		num--;
	}
	vet[num] = x;
}

void insertionSort(int vet[], int num) {	
	
	for(int i = 0; i < num; i++) {
		insert(vet[i], vet, i);
		imprimirVetor(vet,num);
	}
}







