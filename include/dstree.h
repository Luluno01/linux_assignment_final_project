/** data structure tree
 *  usage:
 *  class : BiTNode, BiTree
 *  function prototypes:
 *  BiTree();
 *  BiTree(ElemType **initializer);
 *  Status init(ElemType **initializer);
 *  Status preOrderTraverseRec(Status(* visit)(ElemType *e));
 *  Status inOrderTraverseRec(Status(* visit)(ElemType *e));
 *  Status postOrderTraverseRec(Status (*visit)(ElemType *e));
 *
 */

using namespace std;

#include "dscvt.h"

#ifndef _DSTREE_H_
#define _DSTREE_H_

#define __MAX_TREE_SIZE__ 100

template <class ElemType>
class BiTNode
{
public:
    ElemType *data;
    BiTNode *lchild, *rchild;
};

template <class ElemType>
class BiTree
{
private:
    int cur;
    BiTNode<ElemType> *root;
    Status createBiTree(BiTNode<ElemType> *&N);
    ElemType **initializer; // An pointer array of ElemType
    Status preOrderTraverseRec(BiTNode<ElemType> *N, Status(* visit)(ElemType *e));
    Status inOrderTraverseRec(BiTNode<ElemType> *N, Status(* visit)(ElemType *e));
    Status postOrderTraverseRec(BiTNode<ElemType> *N, Status(* visit)(ElemType *e));
    Status nodeDestroyer(BiTNode<ElemType> *N);
public:
    BiTree();
    BiTree(ElemType **initializer);
    Status init(ElemType **initializer);
    Status preOrderTraverseRec(Status(* visit)(ElemType *e));
    Status inOrderTraverseRec(Status(* visit)(ElemType *e));
    Status postOrderTraverseRec(Status (*visit)(ElemType *e));
    ~BiTree();
};

#include "../dstree.cpp"

#endif // _DSTREE_H_
