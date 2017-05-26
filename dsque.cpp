#ifdef _DSQUE_H_
#include <iostream>
#include <stdlib.h>

#include "include/dscvt.h"

using namespace std;

template <class ElemType>
SqQueue<ElemType>::SqQueue()
{
    queueSize = 0;
    base = NULL;
}

template <class ElemType>
SqQueue<ElemType>::SqQueue(int queueSize)
{
    this->queueSize = 0;
    base = NULL;
    init(queueSize);
}

template <class ElemType>
Status SqQueue<ElemType>::init(int queueSize)
{
    if(base)
    {
        cerr << "ERROR: Queue@" << base << ": already initialized." << endl;
        return ERROR;
    }
//    Q.base = (ElemType *)malloc(__MAX_QUEUE_SIZE__*sizeof(ElemType));
    base = new ElemType[queueSize];
    if(!base)
    {
        cerr << "FATAL ERROR: Queue@" << base << ": size too large." << endl;
        exit(OVERFLOW);
    }
    front = rear = 0;
    this->queueSize = queueSize;
    return OK;
}

template <class ElemType>
int SqQueue<ElemType>::getLength()
{
    if(!base)
    {
        cerr << "ERROR: Queue@" << base << ": not initialized." << endl;
        return 0;
    }
    return (rear - front + queueSize) % queueSize;
}

template <class ElemType>
Status SqQueue<ElemType>::enQueue(ElemType e)
{
    if(!base)
    {
        cerr << "ERROR: Queue@" << base << ": not initialized." << endl;
        return 0;
    }
    if((rear + 1) % queueSize == front) // QF
    {
        cerr << "ERROR: Queue@" << base << ": queue full." << endl;
        return ERROR;
    }
    base[rear] = e;
    rear = (rear + 1) % queueSize;
    return OK;
}

template <class ElemType>
Status SqQueue<ElemType>::deQueue(ElemType &e)
{
    if(!base)
    {
        cerr << "ERROR: Queue@" << base << ": not initialized." << endl;
        return 0;
    }
    if(front == rear) return ERROR; //QE
    e = base[front];
    front = (front + 1) % queueSize;
    return OK;
}

template <class ElemType>
SqQueue<ElemType>::~SqQueue()
{
    delete []base;
    base = NULL;
}
#endif // _DSQUE_H_
