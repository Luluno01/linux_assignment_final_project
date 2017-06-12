/** data structure stack
 *  usage:
 *  class : SqStack
 *  function prototypes:
 *  SqStack();
 *  SqStack(int stackSize);
 *  Status init(int stackSize);
 *  int getLength();
 *  ElemType* getTop(ElemType *&e);
 *  Status push(ElemType e);
 *  Status pop(ElemType &e);
 *  bool isEmpty();
 */

using namespace std;

#include "dscvt.h"

#ifndef _DSSTK_H_
#define _DSSTK_H_

#define __INIT_STACK_SIZE__ 100
#define __STACK_INCREMENT__ 50
//#define int ElemType

template <class ElemType>
class SqStack
{
private:
    ElemType *base;
    ElemType *top;
    int stackSize;
public:
    SqStack();
    SqStack(int stackSize);
    Status init(int stackSize);
    int getLength();
    ElemType* getTop();
    Status push(ElemType e);
    Status pop(ElemType &e);
    bool isEmpty();
    ~SqStack();
};

#include "../dsstk.cpp"

#endif // _DSSTK_H_
