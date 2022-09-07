// CreateBinaryTree.cpp 
//using queue stl

#include <iostream>
#include<queue>

using namespace std;


struct Node
{
    struct Node* lc;
    int data;
    struct Node* rc;

};



struct Node* creatNode(int);
void InoderTree(struct Node* );
void PreorderTree(struct Node* );
void PostOrder(struct Node* );





void PostOrder(struct Node* p)
{
    if (p)
    {
        PostOrder(p->lc);
        PostOrder(p->rc);
        cout << p->data << " ";
    }

}



void PreorderTree(struct Node* p)
{
    if (p)
    {
        cout << p->data << " ";
        PreorderTree(p->lc);
        PreorderTree(p->rc);
    }
 
}


void InoderTree(struct Node* p)
{
    if (p)
    {
        InoderTree(p->lc);
        cout << p->data << " ";
        InoderTree(p->rc);
    }

}



struct Node* creatNode(int x)
{
    struct Node* t = new Node;
    t->data = x;
    t->lc = t->rc = NULL;

    return t;
}

int main()
{
    queue<Node*> q;
    int x;

    cout << "Enter the root : " << endl;
    cin >> x;

    struct Node* root = creatNode(x);
    q.push(root);


    while (!q.empty())
    {
        struct Node* p= q.front();

        cout << "Enter left child -> "<<p->data<<" (-1 for no child) : " ;
        cin >> x;
        cout<< endl;
        if (x != -1)
        {
            p->lc = creatNode(x);
            q.push(p->lc);
        }

        cout << "Enter right child " << p->data << " (-1 for no child) : ";
        cin >> x;
        cout << endl;
        if (x != -1)
        {
            p->rc = creatNode(x);
            q.push(p->rc);

        }
        q.pop();

    }


    cout << " Inorder Traversal of root." << endl;
    InoderTree(root);
    cout << endl;
    cout << " Preorder Traversal of root." << endl;
    PreorderTree(root);
    cout << endl;
    cout << " Postorder Traversal of root." << endl;
    PostOrder(root);
    cout << endl;



    
}

