#include <stdio.h>
#include <stdlib.h>

/*
    Front: O primeiro elemento da fila.
    Rear: O último elemento da fila.
*/

#define MAX_SIZE 10

struct Fila {
    int array[MAX_SIZE];
    int front;
    int rear;
};

void initialize(struct Fila *fila) {
    fila->front = -1;
    fila->rear = -1;
}

//verifica se a fila está vazia
int isEmpty(struct Fila *fila) {
    return (fila->front == -1 && fila->rear == -1);
}

//verifica se a fila está cheia
int isFull(struct Fila *fila) {
    return ((fila->rear + 1) % MAX_SIZE == fila->front);
}

void enfileirar(struct Fila *fila, int item) {
    if (isFull(fila)) {
        printf("Erro: A fila está cheia. Não é possível adicionar mais elementos.\n");
        return;
    }

    if (isEmpty(fila)) {
        fila->front = 0;
        fila->rear = 0;
    } else {
        fila->rear = (fila->rear + 1) % MAX_SIZE;
    }

    fila->array[fila->rear] = item;
}

int desenfileirar(struct Fila *fila) {
    if (isEmpty(fila)) {
        printf("Erro: A fila está vazia. Não é possível remover elementos.\n");
        return -1;  // Valor de retorno indicando erro
    }

    int item = fila->array[fila->front];

    if (fila->front == fila->rear) {
        // Último elemento na fila
        fila->front = -1;
        fila->rear = -1;
    } else {
        fila->front = (fila->front + 1) % MAX_SIZE;
    }

    return item;
}

void printFila(struct Fila *fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Frente da Fila: %d\n", fila->array[fila->front]);
    printf("Elementos da Fila: ");
    int i = fila->front;
    while (i != fila->rear) {
        printf("%d, ", fila->array[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", fila->array[fila->rear]);
}

int main() {
    struct Fila minhaFila;
    initialize(&minhaFila);

    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    enfileirar(&minhaFila, 30);

    printf("Fila após inserção:\n");
    printFila(&minhaFila);

    int removido = desenfileirar(&minhaFila);
    printf("Elemento removido da frente da fila: %d\n", removido);

    printf("Fila após remoção:\n");
    printFila(&minhaFila);

    return 0;
}
