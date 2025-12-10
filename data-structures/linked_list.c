/*
    * linked_list.c
    * Implementazione delle linked list in C
    * Lettura solo "da destra a sinistra"
*/

#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo *next;
};

struct lista {
    struct nodo *head;
    struct nodo *tail;
};

struct nodo *crea_nodo(int value) {
    struct nodo *new_node = (struct nodo *)malloc(sizeof(struct nodo));
    if (new_node == NULL) {
        printf("Errore di allocazione del nodo\n");
        return NULL;
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void distruggi_nodo(struct nodo *node) {
    if (node != NULL) {
        free(node);
    }
}

struct lista *crea_lista() {
    struct lista *new_list = (struct lista *)malloc(sizeof(struct lista));
    if (new_list == NULL) {
        printf("Errore di allocazione della lista\n");
        return NULL;
    }
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

void distruggi_lista(struct lista *lista) {
    if (lista != NULL) {
        struct nodo *current = lista->head;
        struct nodo *next_node;
        while (current != NULL) {
            next_node = current->next;
            distruggi_nodo(current);
            current = next_node;
        }
        free(lista);
    }
}

// Aggiunge un nuovo nodo alla fine della lista
int append(struct lista *lista, int value) {
    struct nodo *new_node = crea_nodo(value);
    if (new_node == NULL) {
        return 1;
    }
    
    if (lista->tail == NULL && lista->head == NULL) {
        lista->tail = new_node;
        lista->head = lista->tail;
        return 0;
    }

    lista->tail->next = new_node;
    lista->tail = new_node;
    return 0;
}

// Aggiunge un nuovo nodo nella lista in posizione index
//! Da capire se funziona per tutti i casi
int insert(struct lista *lista, int value, int index) {
    if (lista->head == NULL && index != 0) {
        printf("Non puoi inserire un elemento con index diverso da 0 in una lista vuota\n");
        return 1;
    }
    if (lista->head == NULL) {
        return append(lista, value);
    }

    struct nodo *new_node = crea_nodo(value);
    if (new_node == NULL) {
        return 1;
    }
    struct nodo *head = lista->head;

    for (int i = 0; i < index; i++) {
        head = head->next;
    }

    if (head == NULL) {
        printf("Index fuori dai limiti della lista\n");
        distruggi_nodo(new_node);
        return 1;
    }
    if (head->next == NULL) {
        lista->tail = new_node;
    }

    new_node->next = head->next;
    head->next = new_node;

    return 0;
}

int delete(struct lista *lista, int index) {
    if (lista->head == NULL) {
        return 1;
    }

    struct nodo *current = lista->head;
    struct nodo *previous = NULL;

    for (int i = 0; i < index; i++) {
        if (current == NULL) {
            return 1;
        }
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        lista->head = current->next;
    } else {
        previous->next = current->next;
    }

    if (current == lista->tail) {
        lista->tail = previous;
    }

    distruggi_nodo(current);
    return 0;
}