/** data structure queue
 *  usage:
 *  class : SqQueue
 *  function prototypes:
 *  SqQueue<ElemType>::SqQueue();
 *  SqQueue<ElemType>::SqQueue(int queueSize);
 *  Status SqQueue<ElemType>::init(int queueSize);
 *  Status SqQueue<ElemType>::queueLength();
 *  Status SqQueue<ElemType>::enQueue(ElemType e);
 *  Status SqQueue<ElemType>::deQueue(ElemType &e);
 *
 */

using namespace std;

#include "dscvt.h"

#ifndef _DSQUE_H_
#define _DSQUE_H_
#endif // _DSQUE_H_

//#define __MAX_QUEUE_SIZE__ 100

template <class ElemType>
class SqQueue
{
private:
    ElemType *base;
    int queueSize;
    int front;
    int rear;
public:
    SqQueue();
    SqQueue(int queueSize);
    Status init(int queueSize);
    int getLength();
    Status enQueue(ElemType e);
    Status deQueue(ElemType &e);
    ~SqQueue();
};

#include "../dsque.cpp"
