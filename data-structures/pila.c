/*
    * pila.c
    * Implementazione staica e dinamica delle pile in C
    * Struttura di tipo LIFO (Last In First Out)
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZZE 100

struct pila_statica {
    int array[MAXSIZZE];
    int top;
};

struct pila_dinamica {
    int *array;
    int size;
    int top;
};

/* 
   *  Le seguenti funzioni valgono anche per la pila statica.
*/

struct pila_dinamica *crea_pila(int size) {
    // Alloco dinamicamente la pila con malloc
    struct pila_dinamica *pila = (struct pila_dinamica *) malloc(sizeof(struct pila_dinamica));
    if (pila == NULL) {
        printf("Errore di allocazione della pila dinamica\n");
        return NULL;
    }
    pila->array = (int *)malloc(size * sizeof(int));
    if (pila->array == NULL) {
        printf("Errore di allocazione dell'array della pila dinamica\n");
        free(pila);
        return NULL;
    }
    pila->top = size - 1;
    pila->size = size;
    return pila;
}

void distruggi_pila(struct pila_dinamica *pila) {
    // Libero la memoria allocata per la pila dinamica
    if (pila != NULL) {
        free(pila->array);
        free(pila);
    }
}

int is_full(struct pila_dinamica *pila) {
    return pila->top == -1;
}

int pila_push(struct pila_dinamica *pila, int value) {
    if (is_full(pila)) {
        printf("Pila piena, impossibile inserire l'elemento %d\n", value);
        return 1;
    }
    pila->array[pila->top] = value;
    pila->top--;
    return 0;
}

int is_empty(struct pila_dinamica *pila) {
    return pila->top == pila->size - 1;
}

int pila_pop(struct pila_dinamica *pila, int *value) {
    if (is_empty(pila)) {
        printf("Pila vuota, impossibile estrarre un elemento\n");
        return 1;
    }
    pila->top++;
    *value = pila->array[pila->top];
    return 0;
}
