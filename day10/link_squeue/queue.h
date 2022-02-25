#ifndef queue_h__
#define queue_h__
#include"dllist.h"
typedef LLIST Queue;

Queue *queue_create(int);
int queue_enqueue(Queue*,const void*);
int queue_dequeue(Queue*,void*);
void queue_destory(Queue*);


#endif // !queue_h__
