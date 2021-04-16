//Domingos Soares do Carmo Neto - TIA: 32032889
//Cássio Luis Junqueira Mellem Filho - TIA: 32089694
#ifndef __STATTC_DEQUE_H__
#define __STATIC_DEQUE_H__

const int STATIC_DEQUE_CAPACITY = 8;

struct StaticDeque
{
    int front;
    int rear;
    int count;
    int values[STATIC_DEQUE_CAPACITY];
};

StaticDeque Create();

void InsertFront(StaticDeque& deque, int elem);

void InsertBack(StaticDeque& deque, int elem);

int RemoveFront(StaticDeque& deque);

int RemoveBack(StaticDeque& deque);

int Front(StaticDeque& deque);

int Back(const StaticDeque& deque);

int Size(const StaticDeque& deque);

int Count(const StaticDeque& deque);

bool IsEmpty(const StaticDeque& deque);

bool IsFull(const StaticDeque& deque);

bool Clear(StaticDeque& deque);

#endif  __STATIC_DEQUE_H__