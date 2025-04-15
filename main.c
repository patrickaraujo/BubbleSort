#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *v, int N) {
    int i, continua, aux, fim = N;
    do {
        continua = 0;
        for (i = 0; i < fim - 1; i++) {
            if (v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);
}

void imprimirVetor(int *v, int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    
    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    // Preenche o vetor com valores aleatórios
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; // Números entre 0 e 99
    }
    
    printf("Vetor antes da ordenacao:\n");
    imprimirVetor(vetor, tamanho);
    
    bubbleSort(vetor, tamanho);
    
    printf("Vetor depois da ordenacao:\n");
    imprimirVetor(vetor, tamanho);
    
    free(vetor);
    
    return 0;
}
