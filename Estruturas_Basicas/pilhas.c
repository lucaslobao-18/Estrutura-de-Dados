#include <stdio.h>
#include <stdlib.h>

//Exemplo de implementação de uma pilha

#define MAX 5

struct Stack {
    int array[MAX];
    int top;
};

// Função para inicializar a pilha
void initialize(struct Stack *stack) {
    stack->top = -1;  // Inicializa o topo como -1, indicando que a pilha está vazia
}

// Função para verificar se a pilha está vazia
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
/*
o return está trabalhando com uma expressão booleana, por causa do "=="
então, ele retorna 1 se for verdade, ou 0 se não
*/

// Função para verificar se a pilha está cheia
int isFull(struct Stack *stack) {
    return stack->top == MAX - 1;
}

// Função para adicionar um elemento à pilha
void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Erro: A pilha está cheia. Não é possível adicionar mais elementos.\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("Elemento %d adicionado à pilha.\n", item);
}
/*
    O (++stack->top) é um incremento no valor da variável top. 
    Especificamente, é um operador de pré-incremento, 
    o que significa que o valor de top será incrementado antes 
    de ser utilizado na expressão.
*/

// Função para remover um elemento da pilha
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Erro: A pilha está vazia. Não é possível remover elementos.\n");
        return -1;  // Valor de retorno indicando erro
    }
    int item = stack->array[stack->top--];
    printf("Elemento %d removido da pilha.\n", item);
    return item;
}

// Função para obter o elemento no topo da pilha sem removê-lo
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Erro: A pilha está vazia. Não há elementos para visualizar.\n");
        return -1;  // Valor de retorno indicando erro
    }
    return stack->array[stack->top];
}

int main() {
    struct Stack minhaPilha;
    initialize(&minhaPilha);

    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);

    printf("Elemento no topo: %d\n", peek(&minhaPilha));

    pop(&minhaPilha);
    printf("Elemento no topo após remoção: %d\n", peek(&minhaPilha));

    return 0;
}
