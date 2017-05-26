#include <iostream>

#include "include/dscvt.h"
#include "include/dsque.h"
#include "include/dsstk.h"
#include "include/dstree.h"

using namespace std;

Status print(char *c)
{
    cout << *c;
    return OK;
}

int main()
{
//    Begin Queue Test
    cout << "Begin Queue Test." << endl;
    SqQueue<int> Q(100);
    cout << "EnQueue: ";
    for(int i = 0; i < 5; i++)
    {
        Q.enQueue(i);
        cout << i << " ";
    }
    cout << endl;
    cout << "Current queue length: ";
    cout << Q.getLength() << endl;
    int e;
    cout << "DeQueue: ";
    for(int i = 0; i < 5; i++)
    {
        Q.deQueue(e);
        cout << e << " ";
    }
    cout << endl;
    cout << "Current queue length: ";
    cout << Q.getLength() << endl;
//    End Queue Test
    cout << endl;

//    Begin Stack Test
    cout << "Begin Stack Test." << endl;
    SqStack<int> S(100);
    cout << "push: ";
    for(int i = 0; i < 5; i++)
    {
        S.push(i);
        cout << i << " ";
    }
    cout << endl;
    cout << "Current stack length: ";
    cout << S.getLength() << endl;
    cout << "The element on the top of stack: " << *(S.getTop()) << endl;
    cout << "pop: ";
    for(int i = 0; i < 5; i++)
    {
        S.pop(e);
        cout << e << " ";
    }
    cout << endl;
    cout << "Current stack length: ";
    cout << S.getLength() << endl;
//    End Stack Test
    cout << endl;

//    Begin Tree Test
    cout << "Begin Tree Test." << endl;
    string str = "ABC##DE#F###G#HIJ##K###";
    cout << "Initialize tree with a preorder traverse sequence: " << str << endl;
    char **nodeList = new char*[str.length()];
    for(int i = 0; i < str.length(); i++)
    {
        nodeList[i] = (str[i] == '#') ? NULL : &str[i];
    }
    BiTree<char> T(nodeList);
    cout << "Preorder traverse sequence: ";
    T.preOrderTraverseRec(print);
    cout << endl;
    cout << "Inorder traverse sequence: ";
    T.inOrderTraverseRec(print);
    cout << endl;
    cout << "Postorder traverse sequence: ";
    T.postOrderTraverseRec(print);
    cout << endl;
//    End Tree Test
    return 0;
}
