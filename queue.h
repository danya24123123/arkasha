#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

typedef struct elem {
    int inf;
    struct elem *link;
} Elem;


typedef struct queue {
    Elem *BegQ;
    Elem *EndQ;
    Elem *p;
}Queue;


void queue_delete(Queue *queue);
void queue_put(Queue *queue, int inf);
void queue_sort(Queue *queue);
void queue_print(const Queue *queue);
void queue_fprint(const Queue *queue,FILE  *file);
void queue_quick_sort(Queue *queue);
void quick_sort_recursive(Elem *low, Elem *high);
Elem* partition(Elem *low, Elem *high);
void queue_quick_sort(Queue *queue);
void swap(Elem *a, Elem *b);
#endif // QUEUE_H_INCLUDED
