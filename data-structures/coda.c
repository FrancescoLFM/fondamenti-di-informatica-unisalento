/*
    * coda.c
    * Implementazione staica e dinamica delle code in C
    * Struttura di tipo FIFO (First In First Out)
*/

#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>

struct coda_statica {
    int array[MAXSIZE];
    int head;
    int tail;
};

struct coda_dinamica {
    int *array;
    int size;
    int head;
    int tail;
};

struct coda_dinamica *crea_coda(int size) {
    // Alloco dinamicamente la coda con malloc
    struct coda_dinamica *coda = (struct coda_dinamica *) malloc(sizeof(struct coda_dinamica));
    if (coda == NULL) {
        printf("Errore di allocazione della coda dinamica\n");
        return NULL;
    }
    coda->array = (int *)malloc(size * sizeof(int));
    if (coda->array == NULL) {
        printf("Errore di allocazione dell'array della coda dinamica\n");
        free(coda);
        return NULL;
    }
    coda->head = 0;
    coda->tail = 0;
    return coda;
}

void distruggi_coda(struct coda_dinamica *coda) {
    // Libero la memoria allocata per la coda dinamica
    if (coda != NULL) {
        free(coda->array);
        free(coda);
    }
}

int is_full(struct coda_dinamica *coda) {
    return coda->tail == (coda->head - 1) % coda->size;
}

/* 
   *  Le seguenti funzioni valgono anche per la coda statica.
*/

int coda_enqueue(struct coda_dinamica *coda, int value) {
    if (is_full(coda)) {
        printf("Coda piena, impossibile inserire l'elemento %d\n", value);
        return 1;
    }
    coda->array[coda->tail] = value;
    //* L'aggiornamento dell'indice è in modo circolare
    coda->tail = (coda->tail + 1) % coda->size;

    return 0;
}

int coda_dequeue(struct coda_dinamica *coda, int *value) {
    if (coda->head == coda->tail) {
        printf("Coda vuota, impossibile rimuovere un elemento\n");
        return 1;
    }
    *value = coda->array[coda->head];
    //* L'aggiornamento dell'indice è in modo circolare
    coda->head = (coda->head + 1) % coda->size;

    return 0;
}

int get_size(struct coda_dinamica *coda) {
    int len = (coda->tail - coda->head + coda->size) % coda->size;
    return len;
}