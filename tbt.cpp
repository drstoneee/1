#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    int l;
    int r;

    Node()
    {
        data = 0;
        l = 0;
        r = 0;
        right = NULL;
        left = NULL;
    }

    Node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
        l = 0;
        r = 0;
    }
};

class tree
{
public:
    Node *root;

    tree()
    {
        root = NULL;
    }

    void create()
    {
        char c = 'y';
        while (c == 'y')
        {
            cout << "Enter data : ";
            int x;
            cin >> x;
            Node *temp = new Node(x);
            if (root == NULL)
            {
                root = temp;
            }
            else
            {
                insert(root, temp);
            }
            cout << "Do you want to insert another data(y/n)";
            cin >> c;
        }
    }

    void insert(Node *root, Node *temp)
    {
        if (temp->data < root->data)
        {
            if (root->l == 0)
            {
                temp->left = root->left;
                temp->right = root;
                root->left = temp;
                root->l = 1;
            }
            else
            {
                insert(root->left, temp);
            }
        }
        else
        {
            if (root->r == 0)
            {
                temp->right = root->right;
                temp->left = root;
                root->right = temp;
                root->r = 1;
            }
            else
            {
                insert(root->right, temp);
            }
        }
    }

    void inorder()
    {
        if (root == NULL)
        {
            cout << "Empty." << endl;
            return;
        }
        Node *temp = root;

        while (temp->l == 1)
        {
            temp = temp->left;
        }
        while (temp != NULL)
        {
            cout << " " << temp->data << " ";
            temp = inorder_successor(temp);
        }
    }
    Node *inorder_successor(Node *temp)
    {
        if (temp->r == 0)
        {
            return temp->right;
        }
        temp = temp->right;
        while (temp->l == 1)
        {
            temp = temp->left;
        }
        return temp;
    }
    void preorder()
    {
        if (root == NULL)
        {
            cout << "Empty." << endl;
            return;
        }
        Node *temp = root;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            if (temp->l == 1)
            {
                temp = temp->left;
            }
            else if (temp->r == 1)
            {
                temp = temp->right;
            }
            else
            {
                while (temp != NULL && temp->r == 0)
                {
                    temp = inorder_successor(temp);
                }
                if (temp != NULL)
                {
                    temp = temp->right;
                }
            }
        }
    }
    Node *deletion(Node *root, int key)
    {
        Node *temp = root;
        Node *parent = NULL;
        int ans = 0;
        while (temp != NULL)
        {
            if (key == temp->data)
            {
                ans = 1;
                break;
            }
            parent = temp;
            if (key < temp->data)
            {
                if (temp->l == 1)
                    temp = temp->left;
                else
                    break;
            }
            else
            {
                if (temp->r == 1)
                    temp = temp->right;
                else
                    break;
            }
        }
        if (ans == 0)
        {
            cout << "key is not present." << endl;
        }
        else if (temp->l == 1 && temp->r == 1)
        {
            root = caseC(root, parent, temp);
        }
        else if (temp->l == 1)
        {
            root = caseB(root, parent, temp);
        }
        else if (temp->r == 1)
        {
            root = caseB(root, parent, temp);
        }
        else
        {
            root = caseA(root, parent, temp);
        }
        return root;
    }
    Node *caseA(Node *root, Node *parent, Node *temp)
    {
        if (parent == NULL)
        {
            root = NULL;
        }
        else if (temp == parent->left)
        {
            parent->l = 0;
            parent->left = temp->left;
        }
        else
        {
            parent->r = 0;
            parent->right = temp->right;
        }
        delete temp;
        return root;
    }
    Node *caseB(Node *root, Node *parent, Node *temp)
    {
        Node *child;
        if (temp->l == 1)
        {
            child = temp->left;
        }
        else
        {
            child = temp->right;
        }
        if (parent == NULL)
        {
            root = child;
        }
        else if (temp == parent->left)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        Node *s = inorder_successor(temp);
        Node *p = inorder_predecer(temp);
        if (temp->l == 1)
        {
            p->right = s;
        }
        else
        {
            if (temp->r == 1)

            {
                s->left = p;
            }
        }
        delete temp;
        return root;
    }
    Node *inorder_predecer(Node *temp)
    {
        if (temp->l == 0)
        {
            return temp->left;
        }
        temp = temp->left;
        while (temp->r == 1)
        {
            temp = temp->right;
        }
        return temp;
    }
    Node *caseC(Node *root, Node *parent, Node *temp)
    {
        Node *parsucc = temp;
        Node *succ = temp->right;
        while (succ->left != NULL)
        {
            parsucc = succ;
            succ = succ->left;
        }
        temp->data = succ->data;
        if (succ->l == 0 && succ->r == 0)
        {
            root = caseA(root, parent, temp);
        }
        else
        {
            root = caseB(root, parent, temp);
        }
        return root;
    }
};

int main()
{
    tree ob;

    ob.create();
    ob.inorder();
    cout << endl;
    ob.preorder();
    //  ob.deletion(ob.root, 20);
    cout << endl;
    ob.inorder();

    return 0;
}