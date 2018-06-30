#include <stdio.h>
#include "BinTree.h"
#define SeqQueueMaxSize 1000
typedef TreeNode* SeqQueueType;

typedef struct SeqQueue
{
        SeqQueueType arr[SeqQueueMaxSize];
            SeqQueueType* head;
                SeqQueueType* tail;
                    size_t size;            //有效数组元素个数

}SeqQueue;

void SeqQueueInit(SeqQueue* s);
void SeqQueuePush(SeqQueue* s, SeqQueueType value);
void SeqQueuePop(SeqQueue* s);
int SeqQueueFront(SeqQueue* s, SeqQueueType* value);
void SeqQueueDestroy(SeqQueue* s);

void SeqQueueInit(SeqQueue* s)
{
        if (s == NULL)
                    return;
            s->head = NULL;
                s->tail = NULL;
                    s->size = 0;

}
void SeqQueuePush(SeqQueue* s, SeqQueueType value)
{
        if (s == NULL)
                    return;
            if (s->size > SeqQueueMaxSize)
                        return;
                if (s->size == 0)                  //入空队列
                {
                            s->arr[0] = value;
                                    s->head = &s->arr[0];
                                            s->tail = &s->arr[1];
                                                    s->size++;
                                                            return;
                                                                
                }
                    if (s->tail >= &s->arr[SeqQueueMaxSize])     //当队列尾部到了数组的尾部
                    {
                                s->arr[0] = value;
                                        s->tail = s->arr;
                                            
                    }
                        else
                        {
                                    *(s->tail) = value;
                                            s->tail++;
                                                
                        }
                            s->size++;

}

void SeqQueuePop(SeqQueue* s)
{
        if (s == NULL)
                    return;
            s->head++;
                if (s->head > &s->arr[SeqQueueMaxSize - 1])
                            s->head = s->arr;
                    --s->size;

}

//void Print(SeqQueue* s, const char* msg)
//{
//        if (s == NULL)
//                    return;
//            printf("%s\n", msg);
//                SeqQueueType* tmp = s->head;
//                    for (size_t i = 0; i < s->size; i++)
//                    {
//                                if (tmp>&s->arr[SeqQueueMaxSize - 1])
//                                                tmp = s->arr;
//                                        printf("%c ", *tmp);
//                                                tmp++;
//                                                    
//                    }
//                        printf("\n");
//
//}
//
int SeqQueueFront(SeqQueue* s, SeqQueueType* value)  //取队列首元素
{
        if (s == 0||value==NULL)
                    return 0;
            if (s->size == 0)
                        return 0;
                *value = *(s->head);
                    return 1;

}
void SeqQueueDestroy(SeqQueue* s)
{
        if (s == NULL)
                    return;
            s->head = NULL;
                s->size = 0;
                    s->tail = NULL;

}
