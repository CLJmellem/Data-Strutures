//Domingos Soares do Carmo Neto - TIA: 32032889
//Cássio Luis Junqueira Mellem Filho - TIA: 32089694
#include <iostream>
#include "deque.h";

using namespace std;

StaticDeque Create()
{
    StaticDeque deque =
    {
          0,
          0,
          0,
        { 0 }
    };

    return deque;
}


void InsertFront(StaticDeque& deque, int elem)
{
    int aux;
    if (deque.rear == 0)
    {
        deque.values[0] = elem;
        deque.rear++;
        deque.count++;
    }
    else
    {
        aux = deque.count;
        for (int i = 0; i < deque.count; i++)
        {
            deque.values[aux - i] = deque.values[aux - 1 - i];
        }
        deque.values[0] = elem;
        deque.rear++;
        deque.count++;
    }
}

void InsertBack(StaticDeque& deque, int elem)
{
    deque.values[deque.count] = elem;
    deque.count++;
    deque.rear++;
}

int RemoveFront(StaticDeque& deque)
{
    int removido;
    int removeF = 0;

    do
    {
        removido = deque.values[removeF];

        deque.values[removeF] = 0;
        removeF++;

    } while (deque.values[removeF] == 0);


    for (int i = 0; i < deque.rear; i++)
    {
        deque.values[i] = deque.values[i + 1];
    }

    deque.count--;

    return removido;
}

int RemoveBack(StaticDeque& deque)
{
    if (IsEmpty(deque))
    {
        return '\0';
    }
    if (!IsEmpty(deque))
    {
        int temp = deque.values[deque.count - 1];
        deque.values[deque.count - 1] = '\0';
        deque.count--;
        return temp;
    }
}

int Front(StaticDeque& deque)
{
    bool vazio = IsEmpty(deque);
    if (vazio == true)
    {
        return '\0';
    }
    else
        return deque.values[0];
}

int Back(const StaticDeque& deque)
{
    if (IsEmpty(deque))
    {
        return '\0';
    }
    if (!IsEmpty(deque))
    {
        int temp = deque.values[deque.count - 1];
        return temp;
    }
}

int Size(const StaticDeque& deque)
{
    return sizeof(deque.values) / sizeof(deque.values[0]);
}

int Count(const StaticDeque& deque)
{
    return (deque.count);
}

bool IsEmpty(const StaticDeque& deque)
{
    if (deque.count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsFull(const StaticDeque& deque)
{
    if (deque.count == STATIC_DEQUE_CAPACITY) { return true; }
}

bool Clear(StaticDeque& deque)
{
    while (!IsEmpty(deque))
    {
        RemoveBack(deque);
    }
    return (IsEmpty(deque));
}