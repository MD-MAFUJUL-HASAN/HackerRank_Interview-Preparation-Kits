#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 100000

typedef struct
{
    int size;
    int capa;
    int front;
    int rear;
    int *element;
} Queue;

Queue *createQueue(int capa)
{
    Queue *Q;
    Q = (Queue *)malloc(sizeof(Queue));
    Q->element = malloc(sizeof(int) * capa);
    Q->size = 0;
    Q->capa = capa;
    Q->front = 0;
    Q->rear = -1;
    return Q;
}

int printE(Queue *Q)
{
    if (Q->size == 0)
        exit(0);
    return Q->element[Q->front];
}

void Push(Queue *Q, int first)
{
    if (Q->size == Q->capa) // Queue is Full
        exit(0);
    Q->size++;
    Q->rear++;
    if (Q->rear == Q->capa)
        Q->rear = 0;
    Q->element[Q->rear] = first;
    return;
}

void Pop(Queue *Q)
{
    if (Q->size == 0)
        return;
    Q->size--;
    Q->front++;
    if (Q->front == Q->capa)
        Q->front = 0;
    return;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Queue *Q = createQueue(SIZE);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int c;
        scanf("%d", &c);
        int element;
        switch (c)
        {

        case 1:
            //  Enqueue element X into the end of the queue.
            scanf("%d", &element);
            Push(Q, element);
            break;
        case 2:
            // Dequeue the element at the front of the queue.
            Pop(Q);
            break;
        case 3:
            // Print the element at the front of the queue.
            printf("%d\n", printE(Q));
            break;
        default:
            break;
        }
    }    
    return 0;
}
