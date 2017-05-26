#ifdef _DSSTK_H_
#include <iostream>
#include <stdlib.h>

#include "include/dscvt.h"

using namespace std;

template <class ElemType>
SqStack<ElemType>::SqStack()
{
    stackSize = 0;
    base = top = NULL;
}

template <class ElemType>
SqStack<ElemType>::SqStack(int stackSize)
{
    this->stackSize = 0;
    base = top = NULL;
    init(stackSize);
}

template <class ElemType>
Status SqStack<ElemType>::init(int stackSize)
{
    if(base)
    {
        cerr << "ERROR: Stack@" << base << ": already initialized." << endl;
        return ERROR;
    }
//    base = (ElemType *)malloc(__INIT_STACK_SIZE__*sizeof(ElemType));
    base = new ElemType[stackSize];
    if(!base)
    {
        cerr << "FATAL ERROR: Stack@" << base << ": size too large." << endl;
        exit(OVERFLOW);
    }
    top = base;
    this->stackSize = stackSize;
    return OK;
}

template <class ElemType>
Status SqStack<ElemType>::getLength()
{
    return top - base;
}

template <class ElemType>
ElemType* SqStack<ElemType>::getTop()
{
    if(top == base)
    {
        cerr << "ERROR: Stack@" << base << ": stack empty." << endl;
        return 0;
    }
    return top - 1;
}

template <class ElemType>
Status SqStack<ElemType>::push(ElemType e)
{
    if(top - base >= stackSize) // SF
    {
        cerr << "ERROR: Stack@" << base << ": stack full." << endl;
        return ERROR;
    }
    *(top++) = e;
    return OK;
}

template <class ElemType>
Status SqStack<ElemType>::pop(ElemType &e)
{
    if(top == base) // SE
    {
        cerr << "ERROR: Stack@" << base << ": stack empty" << endl;
        return ERROR;
    }
    e = *(--top);
    return OK;
}

template <class ElemType>
bool SqStack<ElemType>::isEmpty()
{
    return top == base;
}

template <class ElemType>
SqStack<ElemType>::~SqStack()
{
    delete []base;
    base = NULL;
}
#endif // _DSSTK_H_
