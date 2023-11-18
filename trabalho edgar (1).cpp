#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int vetor[], int tam){
	
	int i, j;
	
	for (i = 0; i < tam - 1; i++){
		for( j = 0; j < tam - i - 1; j++){
			
			if(vetor[j] > vetor[j + 1]){
		
				int aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
			
		}
	}

	
	for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
	
//	printf("\nTempo gasto em Bubble Sort: %.3000f",bubbletemp );
	
	
}
void insertonsort(int vetor[], int tam){
	

	
	int i, j, tmp;
  
 	for(i = 1; i < tam; i++){
 		tmp = vetor[i];
 		for(j = i-1; j >= 0 && tmp < vetor[j]; j--){
   			vetor[j+1] = vetor[j];
  		}
  		vetor[j+1] = tmp;
 	}
 	
 	
 		for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
	
//	printf("\nTempo gasto em Insert On Sort: %.3000f",inserttemp );
	
	
	
}
void selectionsort(int vetor[], int tam){
	

	int j, i;
	
	for(i = 0; i < tam-1; i++){
		int min = i;
		for(j = i + 1; j < tam; j++){
			
			if(vetor[j] < vetor[min]){
				min = j;
			}
			
		}
		int aux = vetor[i];
		vetor[i] = vetor[min];
		vetor[min] = aux;
		
	}

	for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
//	printf("\nTempo gasto em Select on Sort: %.3000f",selecttemp );
	

	
}

int partition(int vetor[], int l, int h){
	int x = vetor[h];
	int i = (l - 1);
	int j;
	
	for (j = l; j <= h - 1; j++) {
		if (vetor[j] <= x) {
		i++;
		int temp = vetor[i];
		vetor[i]=vetor[j];
		vetor[j]=temp;
		}
	}

	int temp = vetor[i+1];
	vetor[i+1]=vetor[h];
	vetor[h]=temp;
	return (i + 1);
}
void quickSort(int vetor[], int l, int h){
	
	int i;
	if (l < h) {
		/* Partitioning index */
		int p = partition(vetor, l, h);
		quickSort(vetor, l, p - 1);
		quickSort(vetor, p + 1, h);
	}
	
}


int main(){
	clock_t start, end;
	int tam, i, op;
//	printf("Qual o tamanho da sequencia?\n");
	//scanf("%d", &tam);
	tam=30;
	
	long double bubble, insert, select, quick;
	int vetorbubble[tam], vetorinset[tam], vetorselect[tam], vetorquick[tam], vetor[tam];
	
	for(i = 0; i < tam; i++){	
		vetorbubble[i]  = rand() % 1000;	
	}
	for(i = 0; i < tam; i++){	
		vetorinset[i]  = vetorbubble[i];	
	}	
	for(i = 0; i < tam; i++){	
		vetorselect[i]  = vetorbubble[i];	
	}	
	for(i = 0; i < tam; i++){	
		vetorquick[i]  = vetorbubble[i];	
	}
	
//	printf("\nDigite a sequencia do Vetor:\n");
//	for(i = 0; i < tam; i++){
//		scanf("%d", &vetor[i]);
//	}
	
	printf("\nVetor sem ordenar: ");
	
	for(i = 0; i < tam; i++){
		printf("%d ", vetorbubble[i]);
	}
	
	
	printf("\n");
	printf("\n");
	
	
//	printf("Com qual algoritimo deseja ordenar a sequencia?\n");
//	printf("1. Insert on sort\n2. selection sort\n3. Bubble sort\n4.QuickSort\n9. Sair\n");
//	scanf("%d", &op);
	
//	switch (op){
	
	//	case 1:
			printf("Inser on Sort:\n");
			start = clock();
			insertonsort(vetorinset, tam);
			end = clock();
			insert = ((long double) (end - start)) / CLOCKS_PER_SEC;
			printf("\nTempo gasto em Insert On Sort: %Lf",insert);
	//	break;
		
	//	case 2:
			printf("\n\nSelect on Sort:\n");
			start = clock();
			selectionsort(vetorselect, tam);
			end = clock();
			select = ((long double) (end - start)) / CLOCKS_PER_SEC;
			printf("\nTempo gasto em Select on Sort: %Lf",select);
	//	break;
		
	//	case 3:
			 printf("\n\nBubble Sort:\n");
			 start = clock();
			 bubblesort(vetorbubble, tam);
			 end = clock();
		     bubble = ((long double) (end - start)) / CLOCKS_PER_SEC;
			 printf("\nTempo gasto em Bubble Sort: %Lf", bubble);
	//	break;
		
	//	case 4:
			printf("\n\nQuick Sort:\n");
			
			start = clock();
			quickSort(vetorquick, 0, tam-1);
			end = clock();
		    quick = ((long double) (end - start)) / CLOCKS_PER_SEC;
		
			for(i = 0; i < tam; i++){
				printf("%d ", vetorquick[i]);
			}
			
			printf("\nTempo gasto em Quicksort: %Lf",quick );
			
			if(insert < select && insert < bubble && insert < quick){
				printf("\nInsert on sort tem o melhor tempo.");
			}
			else if(select < insert && select < bubble && select < quick){
				printf("\nSelect on Sort tem o melhor tempo.");
			}
			else if(bubble < insert && bubble < select && bubble < quick){
				printf("\nBubble sort tem o melhor tempo");
			}
			else if(quick < insert && quick < select && quick < bubble){
				printf("\nQuick sort tem o melhor tempo");
			}
}
			
	
			
		
			
			
	//	break;
		
	//	case 9:
			
	
		
			
	//}

	
//}
