#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stack>
using namespace std;

template <typename T>
class BNode
{
public:
    T data;
    BNode *lc, *rc;

    BNode()
    {
        lc = NULL;
        rc = NULL;
    }

    BNode(T data, BNode *lc = NULL, BNode *rc = NULL)
    {
        this->data = data;
        this->lc = lc;
        this->rc = rc;
    }
};

void visit(BNode<int> *p)
{
    cout << p->data << " ";
}

void PreOrder(BNode<int> *p)
{
    if(!p) return ;

    visit(p);
    PreOrder(p->lc);
    PreOrder(p->rc);
}

void SPreOrder1(BNode<int> *p)
{
    if(!p) return ;
    
    BNode<int> *q = p;

    stack<BNode<int> *> S;
    S.push(q);

    while(!S.empty())
    {
        q = S.top();
        S.pop();
        visit(q);

        if(q->rc) S.push(q->rc);
        if(q->lc) S.push(q->lc);
    }
}

void SPreOrder2(BNode<int> *p)
{
    if(!p) return ;

    BNode<int> *q = p;
    stack<BNode<int> *> S;

    while(true)
    {
        while(q)
        {
            visit(q);
            
            if(q->rc) S.push(q->rc);
            q = q->lc;
        }

        if(S.empty()) return ;

        q = S.top(), S.pop();
    }
}

void InOrder(BNode<int> *p)
{
    if(!p) return ;

    InOrder(p->lc);
    visit(p);
    InOrder(p->rc);
}

void SInOrder1(BNode<int> *p)
{
    if(!p) return ;

    BNode<int> *q = p;
    stack<BNode<int> *> S;

    while(true)
    {
        while(q)
        {
            S.push(q);
            q = q->lc;
        }

        if(S.empty()) return ;

        q = S.top(), S.pop();
        visit(q);
        q = q->rc;
    }

}

void SInOrder2(BNode<int> *p)
{
    if(!p) return ;

    BNode<int> *q = p;
    stack<BNode<int> *> S;

    while(true)
    {
        if(q)
        {
            S.push(q);
            q = q->lc;
        }else if(!S.empty()) {
            q = S.top(), S.pop();
            visit(q);
            q = q->rc;
        } else break;
    }
}

void PostOrder(BNode<int> *p)
{
    if(!p) return ;

    PostOrder(p->lc);
    PostOrder(p->rc);
    visit(p);
}

void SPostOrder(BNode<int> *p)
{
    if(!p) return ;

    
    
}

void init(BNode<int> *root)
{
    root->lc = new BNode<int>(2);
    root->rc = new BNode<int>(3);

    root->lc->rc = new BNode<int>(4);
    root->lc->rc->lc = new BNode<int>(6);

    root->rc->rc = new BNode<int>(5);
}

int main()
{
    BNode<int> *root = new BNode<int>(1);
    init(root);
    
    cout << "preOrder" << endl;
    PreOrder(root);
    cout << endl;
    SPreOrder1(root);
    cout << endl;
    SPreOrder2(root);
    cout << endl;

    cout << "inOrder" << endl;
    InOrder(root);
    cout << endl;
    SInOrder1(root);
    cout << endl;
    SInOrder2(root);
    cout << endl;

    cout << "postOrder" << endl;
    PostOrder(root);
    cout << endl;
    SPostOrder(root);
    cout << endl;

    system("pause");
}