#ifdef _DSTREE_H_
#include <iostream>
#include <stdlib.h>

#include "include/dscvt.h"

using namespace std;

template <class ElemType>
BiTree<ElemType>::BiTree()
{
    initializer = NULL;
    cur = 0;
}

template <class ElemType>
BiTree<ElemType>::BiTree(ElemType **initializer)
{
    this->initializer = (ElemType **)NULL;
    cur = 0;
    init(initializer);
}

template <class ElemType>
Status BiTree<ElemType>::init(ElemType **initializer)
{
    this->initializer = initializer;
    createBiTree(root);
    return OK;
}

template <class ElemType>
Status BiTree<ElemType>::createBiTree(BiTNode<ElemType> *&N)
{
    ElemType *data;
    data = initializer[cur++];
    if(data)
    {
        N = new BiTNode<ElemType>;
        if(!N)
        {
            cerr << "FATAL ERROR: BiTree@" << root << ": stack overflow." << endl;
            exit(OVERFLOW);
        }
//        if(!(N = malloc(sizeof(BiTNode)))) exit(OVERFLOW);
        N->data = data;
        createBiTree(N->lchild);
        createBiTree(N->rchild);
    }
    else
    {
        N = NULL;
    }
    return OK;
}

template <class ElemType>
Status BiTree<ElemType>::preOrderTraverseRec(BiTNode<ElemType> *N, Status(* visit)(ElemType *e))
{
    if(N)
    {
        if(visit(N->data))
        {
            if(preOrderTraverseRec(N->lchild, visit))
            {
                if(preOrderTraverseRec(N->rchild, visit)) return OK;
            }
        }
        return ERROR;
    }
    else return OK;
}

template <class ElemType>
Status BiTree<ElemType>::preOrderTraverseRec(Status(* visit)(ElemType *e))
{
    cur = 0;
    preOrderTraverseRec(root, visit);
    return OK;
}

template <class ElemType>
Status BiTree<ElemType>::inOrderTraverseRec(BiTNode<ElemType> *N, Status(* visit)(ElemType *e))
{
    if(N)
    {
        if(inOrderTraverseRec(N->lchild, visit))
        {
            if(visit(N->data))
            {
                if(inOrderTraverseRec(N->rchild, visit)) return OK;
            }
        }
        return ERROR;
    }
    else return OK;
}

template <class ElemType>
Status BiTree<ElemType>::inOrderTraverseRec(Status(* visit)(ElemType *e))
{
    cur = 0;
    inOrderTraverseRec(root, visit);
    return OK;
}

template <class ElemType>
Status BiTree<ElemType>::postOrderTraverseRec(BiTNode<ElemType> *N, Status(* visit)(ElemType *e))
{
    if(N)
    {
        if(postOrderTraverseRec(N->lchild, visit))
        {
            if(postOrderTraverseRec(N->rchild, visit))
            {
                if(visit(N->data)) return OK;
            }
        }
        return ERROR;
    }
    else return OK;
}

template <class ElemType>
Status BiTree<ElemType>::postOrderTraverseRec(Status(* visit)(ElemType *e))
{
    cur = 0;
    postOrderTraverseRec(root, visit);
    return OK;
}

template <class ElemType>
Status BiTree<ElemType>::nodeDestroyer(BiTNode<ElemType> *N)
{
    if(N)
    {
        if(nodeDestroyer(N->lchild))
        {
            if(nodeDestroyer(N->rchild))
            {
                delete N;
                return OK;
            }
        }
        return ERROR;
    }
    else return OK;
}

template <class ElemType>
BiTree<ElemType>::~BiTree()
{
    nodeDestroyer(root);
}
#endif // _DSTREE_H_
