/**
 *  wangdao, P78 1.
 *  2018.10.20
 *
 **/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int MaxSize = 10;

template <typename T>
class Queue
{
public:
    T data[MaxSize];
    int tag;
    int front, rear;

    Queue()
    {
        front = rear = 0;
        tag = 0;
        memset(data, 0, sizeof(data));
    }

    bool enQueue(T x)
    {
        if (rear == front && tag)
        {
            cout << "Flooding" << endl;
            return false;
        }

        data[rear] = x;
        tag = 1;
        rear = (rear + 1) % MaxSize;
        return true;
    }

    bool deQueue(T &x)
    {
        if(rear == front && !tag)
        {
            cout << "Null" << endl;
            return false;
        }

        tag = 0;
        x = data[front];
        front = (front + 1) % MaxSize;

        return true;
    }

    int len()
    {
        if(rear == front && tag) return MaxSize;
        return (rear - front + MaxSize) % MaxSize;
    }

    void print()
    {
        for (int r = 0; r < MaxSize; r++)
            cout << data[r] << " ";
        cout << endl;
   }
};

int main()
{
    Queue<int> Q;
    int de;

    for (int i = 1; i <= 7; i++)
        Q.enQueue(i);
    Q.print();

    for (int i = 1; i < 3; i++)
        Q.deQueue(de);
    Q.print();

    for (int i = 1; i < 12; i++)
        Q.deQueue(de);
    Q.print();

    for (int i = 1; i <= 12; i++)
        Q.enQueue(i);
    Q.print();

    system("pause");
}


/*
operator:
    Push(S, x);
    Pop(S, x);
    StackEmpty(S);
    StackOverflow(S);

//S1, queue
//S2, tempe

void Enqueue(x)
{
    Push(S1, x)
}

void Dequeue(&x)
{
    S1->S2
    Pop(S2, x)
    S2->S1
}

bool QueueEmpty()
{
    return StackEmpty(S1);
}



*/