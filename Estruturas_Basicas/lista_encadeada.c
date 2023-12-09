#include <stdio.h>
#include <stdlib.h>

//defini o nó da lista
struct Node {
    int data;
    struct Node* next;
};

//Inserção no início
void push(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

//Inserção no final (Append)
void append(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

//percorre do início até o final, para encontrar o que aponta para NULL
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

//remoção no início
void pop(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

//remoção no final
void removeLast(struct Node** head) {
    if (*head == NULL) {
        return; //sai da função
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* second_last = *head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
}

//Busca
struct Node* search(struct Node* head, int target) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return current;  // Encontrou o nó com o valor desejado
        }
        current = current->next;
    }
    return NULL;  // Valor não encontrado na lista
}

//Liberação de Memória
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
