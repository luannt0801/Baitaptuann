#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node

{
    int sbd; // So bao danh
    string hoTen; // Ho ten sinh vien
    Node * left; // Con tro toi nut con trai
    Node * right; // Con tro toi nut con phai
// Ham tao.
    Node(int s, string h, Node * l, Node * r)
    {
        sbd = s;
        hoTen = h;
        left = l;
        right = right;
    }

};

// Lop cay nhi phan tim kiem.

class BSTree
{
    private:
        Node *root;
    public:
// Ham tao (ban dau cay rong).
    BSTree()
    {
        Node * root = NULL;
    }
    // Ham huy (xoa het cac nut tren cay).
    ~BSTree()
    {
        makeEmpty(root);
    }
    // Kiem tra cay co rong hay khong.
    bool isEmpty()
    {
        if (root == NULL) {return true;}
        if (root->left == NULL && root->right == NULL) {return true;}
        if (root->left != NULL & root->right != NULL) {return false;}
    }
    // Xoa het cac nut tren cay.
    void makeEmpty()
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left)
        {
            makeEmpty(root->left);
        }
        else if (root->right)
        {
            makeEmpty(root->right);
        }
        else delete root;
    }
    //void printTree(ostream& out = cout) const;
    // Chen mot nut val1 moi vao cay.
    void insert(Node *& t, int h, string g)
    {
        Node * p = new Node(h,g,NULL,NULL);
        if (t == NULL)
        {
            t = new Node(h,g,NULL,NULL);
        }
        else if (h < t->sbd)
        {
            t->left = p;
        }
        else if (h > t->sbd)
        {
            t->right = p;
        }
    }
    // Tim nut val2
    Node* search(int s, Node * t)
    {
        if (t == NULL)
            return NULL;
        else if (s < t->sbd)
        {
            search(s, t->left);
        }
        else if (s > t->sbd)
        {
            search(s, t->right);
        }
        else
        {
            return t;
        }
        return t;
    }
    //void printTree(Node* t, ostream& out) const;
    // Xoa rong cay (viet theo kieu de quy).
    void makeEmpty(Node*& t)

    {

        if (root == NULL)
        {
            return;
        }
        if (root->left)
        {
            makeEmpty(root->left);
        }
        else if (root->right)
        {
            makeEmpty(root->right);
        }
        else delete root;
        root = NULL;
    }

    // Chen mot nut val1 moi vao cay (viet theo kieu de quy).

    void insert(Node *& t, int h, string g)

    {
        Node * p = new Node(h,g,NULL,NULL);
        if (t == NULL)
        {
            t = new Node(h,g,NULL,NULL);
        }
        else if (h < t->sbd)
        {
            t->left = p;
        }
        else if (h > t->sbd)
        {
            t->right = p;
        }
    }

    // Tim nut co gia tri cho truoc (viet theo kieu de quy).

Node* search(int s, Node * t)
    {
        if (t == NULL)
            return NULL;
        else if (s < t->sbd)
        {
            search(s, t->left);
        }
        else if (s > t->sbd)
        {
            search(s, t->right);
        }
        else
        {
            return t;
        }
        return t;
    }

    //duyet in cay

    /*void printTree(ostream & out = cout) const

    {

    if (isEmpty())

    out << "Empty tree" << endl;

    else

    printTree(root, out);

    }*/

void printTree(Node* t, ostream& out) const
    {
        if (t != nullptr)
        {
            printTree(t->left, out);
            out << t->sbd << endl << t->hoTen << endl;
            printTree(t->right, out);
        }

    }

};

void PREORDER_travl(Node* t)
 {
    if (t != NULL)
    {
        cout << t->hoTen << endl << t->sbd;
        PREORDER_travl(t->left);
        PREORDER_travl(t->right);
    }
}

int main()

{
BSTree bst;
// Chen cac node co gia tri duoi day .
bst.insert(5,"Luan");
bst.insert(6,"Luan");
bst.insert(3,"Luan");
bst.insert(8,"Luan");
bst.insert(7,"Luan");
Node *root = bst.search(5);
cout << "duyet cay thu tu truoc" << endl;
PREORDER_travl(root);
cout << endl;
// Tim hai node co gia tri 4 va 9.
Node* n1 = bst.search(4);
Node* n2 = bst.search(3);
// In ket qua tim kiem
if (n1 != NULL)
cout << "Node có gia tri = 4 la " << n1->value << endl;
if (n2 == NULL)
cout << "Khong tim thay node co gia tri =9" << endl;
// Lam rong cay.
bst.makeEmpty();
if (bst.isEmpty())
cout << "Cay da bi xoa rong" << endl;
return 0;
}