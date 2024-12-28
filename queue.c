#include "queue.h"


void queue_put(Queue *queue, int inf) {
    Elem *new = (Elem *) malloc(sizeof(Elem));
    new->inf = inf;
    new->link = NULL;
    if (!queue->BegQ) {//�����
        queue->BegQ = new;
        queue->EndQ = new;
    }
    else {//�� �����
        queue->EndQ->link = new;
        queue->EndQ = new;
    }

}

void queue_delete(Queue *queue) {
    Elem *current = queue->BegQ;
    while (current) {
        Elem *prev = current;
        current = current->link;
        free(prev);
    }
    free(queue);
}

void queue_print(const Queue *queue) {
    Elem *current = queue->BegQ;
    while (current) {
        printf("%d ", current->inf);
        current = current->link;
    }
    printf("\n");
}
void queue_fprint(const Queue *queue,FILE  *file) {
    Elem *current = queue->BegQ;
    while (current) {
        fprintf(file,"%d ", current->inf);
        current = current->link;
    }
    fprintf(file,"\n");
}


void queue_sort(Queue *queue) {
    if (queue->BegQ == NULL) {
        return;
    }

    Elem *current = queue->BegQ;

    while (current != NULL) {

        Elem *max  = current;
        Elem *link = current->link;

        while (link != NULL) {
            if (link->inf > max->inf) {                                                                                                                              //link->inf (������� �������), max->inf -����
                max = link;
            }
            link = link->link;
        }


        if (max != current) {/*
            int temp = current->inf;
            current->inf = max->inf;
            max->inf = temp;*/
            swap(current,max );
        }

        current = current->link;
    }
}
void swap(Elem *a, Elem *b) {
    int temp = a->inf;
    a->inf = b->inf;
    b->inf = temp;
}

// ���������� ������� ��� ������� ����������
Elem* partition(Elem *first, Elem *last) {
    int pivot = first->inf;  //������� ��
    Elem *i = first; //<=pivot
    Elem *j = first->link;

    while (j != last->link) {
        if (j->inf < pivot) {
            i = i->link;
            swap(i, j);
        }
        j = j->link;
    }
    swap(i, first);  // ����� � low �� �������
    return i;
}


void quick_sort_recursive(Elem *first, Elem *last) {
    if (first != last && first != NULL && last != NULL) {//first==last ������� �� 1 �� �����
        Elem *pivot = partition(first, last);
        if (pivot != first) {
            Elem *temp = first;
            while (temp->link != pivot) {
                temp = temp->link;
            }
            quick_sort_recursive(first, temp);
        }
        if (pivot != last) {
            quick_sort_recursive(pivot->link, last);
        }
    }
}


void queue_quick_sort(Queue *queue) {
    if (queue == NULL || queue->BegQ == NULL) {//���� ������� �� �������
        return;
    }
    quick_sort_recursive(queue->BegQ, queue->EndQ);
    /*if (queue->BegQ != queue->EndQ && queue->BegQ != NULL && queue->EndQ != NULL) {
        Elem *pivot = partition(queue->BegQ, queue->EndQ);
        if (pivot != queue->BegQ) {
            Elem *temp = queue->BegQ;
            while (temp->link != pivot) {
                temp = temp->link;
            }
            quick_sort_recursive(queue->BegQ, temp);
        }
        if (pivot != queue->EndQ) {
            quick_sort_recursive(pivot->link, queue->EndQ);
        }
    }*/
}
