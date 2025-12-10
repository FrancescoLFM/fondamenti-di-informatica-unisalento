/*
    * double_linked_list.c
    * Implementazione delle double linked list in C
    * Lettura da entrambi i versi
*/
#include <stdio.h>
#include <stdlib.h>

struct double_node {
    int data;
    struct double_node *next;
    struct double_node *prev;
};

struct double_lista {
    struct double_node *head;
    struct double_node *tail;
};

struct double_node *crea_double_nodo(int value) {
    struct double_node *new_node = (struct double_node *)malloc(sizeof(struct double_node));
    if (new_node == NULL) {
        printf("Errore di allocazione del nodo\n");
        return NULL;
    }
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void distruggi_double_nodo(struct double_node *node) {
    if (node != NULL) {
        free(node);
    }
}

struct double_lista *crea_double_lista() {
    struct double_lista *new_list = (struct double_lista *)malloc(sizeof(struct double_lista));
    if (new_list == NULL) {
        printf("Errore di allocazione della lista\n");
        return NULL;
    }
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

void distruggi_double_lista(struct double_lista *lista) {
    if (lista != NULL) {
        struct double_node *current = lista->head;
        struct double_node *next_node;
        while (current != NULL) {
            next_node = current->next;
            distruggi_double_nodo(current);
            current = next_node;
        }
        free(lista);
    }
}

int append(struct double_lista *lista, int value) {
    struct double_node *new_node = crea_double_nodo(value);
    if (new_node == NULL) {
        return 1;
    }

    if (lista->head == NULL) {
        lista->head = new_node;
        lista->tail = new_node;
    } else {
        lista->tail->next = new_node;
        new_node->prev = lista->tail;
        lista->tail = new_node;
    }

    return 0;
}

int insert(struct double_lista *lista, int value, int index) {
    if (lista->head == NULL && index != 0) {
        printf("Non puoi inserire un elemento con index diverso da 0 in una lista vuota\n");
        return 1;
    }
    if (lista->head == NULL) {
        return append(lista, value);
    }

    struct double_node *new_node = crea_double_nodo(value);
    if (new_node == NULL) {
        return 1;
    }
    struct double_node *head = lista->head;

    for (int i = 0; i < index; i++) {
        head = head->next;
    }

    if (head == NULL) {
        printf("Index fuori dai limiti della lista\n");
        distruggi_double_nodo(new_node);
        return 1;
    }
    if (head->next == NULL) {
        lista->tail = new_node;
    }

    new_node->next = head->next;
    new_node->prev = head;
    if (head->next != NULL) {
        head->next->prev = new_node;
    }
    head->next = new_node;

    return 0;
}

int delete(struct double_lista *lista, int index) {
    if (lista->head == NULL) {
        return 1;
    }

    struct double_node *current = lista->head;

    for (int i = 0; i < index; i++) {
        if (current == NULL) {
            return 1;
        }
        current = current->next;
    }

    if (current == NULL) {
        return 1;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        lista->head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        lista->tail = current->prev;
    }

    distruggi_double_nodo(current);
    return 0;
}