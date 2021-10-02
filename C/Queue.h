// a queue header for C language
#ifndef __QUEUE_LINKEDLIST__
#define __QUEUE_LINKEDLIST__ 1

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue // struct to use as external structure of Queue
{
    int length; // instead of using a function, let's just store the length in a variable

    struct Internal
    { // struct to use as internal structure of Queue
        int data;
        struct Internal *next;
    } * front, *rear, *temp;

} Queue;


typedef enum printThe { data = 1, length, both} printThe;
// enum to use to choose what to print


Queue *getNewQueue(void);
// fuction to allocate required memory for one queue
// takes nothing
// returns a pointer to it

Queue *enqueue(Queue* que, const int value);
// function to add an element into given queue
// takes a pointer to queue, and a value of type int
//returns the updated pointer to queue

Queue *dequeue(Queue *que);
// function to remove an element from given queue
// takes a pointer to queue
// returns the updated pointer to queue

void printQueue(Queue *que, const printThe type);
// function to print the queue data and it's lenght
// takes a pointer to queue, and a 'type' what to print
// retunrs nothing


Queue *getNewQueue() // fuction to allocate required memory for one queue and returns a pointer to it
{
    Queue *tempQueue = (Queue *)malloc(sizeof(Queue));
    tempQueue->rear = tempQueue->front = tempQueue->temp = NULL;
    return tempQueue;

    // first external stuct is allocated, then one of three internal pointers are allocated
    //    so that we get an entire Queue in just one pointer (external struct) using nested structs
    //    it seems a bit messy at first but comes in handy if we fuck around a few time
}

Queue *enqueue(Queue *que, const int value) // function to add a element into given queue
{
    if (que == NULL)
    {
        printf("Error : Given queue does not exist!\n");
        return que;
    }

    que->temp = (struct Internal *)malloc(sizeof(struct Internal)); // allocate a fresh memory
    que->temp->next = NULL;                                         // nullify the pointer
    que->temp->data = value;                                        // put the value in new memory

    if (que->front == NULL)                 // if no element exist
        que->front = que->rear = que->temp; // first and last node are same

    else // if one or more element exist
    {
        que->rear->next = que->temp; // last->next points to new node
        que->rear = que->temp;       // new node becomes last node
    }

    ++que->length; // incrase the length by one

    return que;
}

Queue *dequeue(Queue *que) // function to remove an element
{
    if (que == NULL)
    {
        printf("Queue empty!\n");
        printf("Nothing to remove!\n");
        return que;
    }

    que->temp = que->front;
    que->front = que->front->next;
    free(que->temp);
    --que->length;

    return que;
}

void printQueue(Queue *que, const printThe type) // function to print a queue
{
    if (que == NULL)
    {
        printf("Queue empty or does not exist!\n");
        return;
    }

    if (type & 1)   // condition to print all elements of queue
    {
        for (Queue *temp = que; temp->front != NULL; temp->front = temp->front->next)
            printf("%d --> ", temp->front->data);
        printf("NULL\n");
    }

    if (type & 2)   // condition to print only the length 
        printf("Length : %d\n", que->length);
}

#endif
