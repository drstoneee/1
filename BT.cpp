#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    
        int data;
        Node *left;
        Node *right;

        Node(int data)
        {
            this->data=data;
            this->left = NULL;
            this->right = NULL;
        }

        friend class BT;
};


class BT
{   public:
    Node *root;
    public:

    void rinorder(Node *root)
    {
        if(root == NULL)
            return;
        rinorder(root->left);
        cout<<root->data<<" ";
        rinorder(root->right);
    }

    vector <int> iinorder(Node *root)
    {   
        stack <Node*> s;
        vector <int> ans;
        Node *curr = root;
        while(!s.empty() || curr != NULL)
        {
            while(curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        return ans;

    }



    void rpreorder (Node* root)
    {
        if (root==NULL)
        {
            return;
        }
        cout << root->data << " ";
        rpreorder(root->left);
        rpreorder(root->right);

    }

    

    vector<int> ipreorder (Node* root)
    {
        if (root==NULL)
        {
            return {};
        }
        vector<int> ans;
        stack<Node*> Stack;
        Stack.push(root);
        while(!Stack.empty())
        {
            Node* curr = Stack.top();
            Stack.pop();
            ans.push_back(curr->data);
            if(curr->right)
                Stack.push(curr->right);
            if(curr->left)
                Stack.push(curr->left);
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        return ans;
    }

    void rpostorder(Node* root)
    {
        if (root==NULL)
        {
            return;
        }
        rpostorder(root->left);
        rpostorder(root->right);
        cout << root->data << " ";
    }


    vector<int> ipostorder(Node* root)

{
    if (root==NULL)
    {
        return {};
    }
    vector<int> ans;
    stack<Node*> Stack;
    Node* curr = root;
    while(!Stack.empty() || curr != NULL)
    {
        while(curr != NULL)
        {
            ans.push_back(curr->data);
            Stack.push(curr);
            curr = curr->right;
        }
        curr = Stack.top();
        Stack.pop();
        curr = curr->left;
    }
    reverse(ans.begin(), ans.end());



    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return ans;
}

    

    Node* buildTree(Node* &root) {
    cout << "\nData (-1 for Null): ";
    int d;
    cin >> d;

    // If the input is -1, return nullptr indicating a null node
    if (d == -1)
        return nullptr;

    // Create a new node with the input data
    root = new Node(d);

    cout << "Enter data for left of " << d << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right of " << d << endl;
    root->right = buildTree(root->right);

    // Return the pointer to the root of the subtree
    return root;
}


void mirror (Node* root)
{
    if (root==NULL)
    {
        return;
    }
    else {
        mirror(root->right);
        mirror(root->left);

        Node* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
    

    int internal(Node *root)
    {
        if (root==NULL || (root->left==NULL && root->right==NULL))
        {
            return 0;
        }
        else {
            int left = internal(root->left);
            int right = internal(root->right);

            return left+right+1;
        }
    }

    int leaf (Node *root)
    {
        if (root==NULL)
        {
            return 0;
        }
        else if (root->left==NULL && root->right==NULL)
        {
            return 1;
        }
        else
        {
            return leaf(root->left) + leaf(root->right);
        }
    }

    int height (Node *root)
    {
        if (root==NULL)
        {
            return 0;
        }
        else
        {
            int left = height(root->left);
            int right = height(root->right);
            if (left>right)
            {
                return left+1;
            }
            else
            {
                return right+1;
            }
        }


         
    }

    vector <int> levelOrder(Node* root)
    {
        if (root==NULL)
        {
            return {};
        }
        vector <int> ans;
        queue <Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            ans.push_back(curr->data);
            if(curr->left) 
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return ans;
    }



};

int main ()
{
    BT Tree;
    Tree.buildTree(Tree.root);
    Tree.iinorder(Tree.root);
    // cout << endl;
    // Tree.ipreorder(Tree.root);
    // cout << endl;
    // Tree.ipostorder(Tree.root);

    // Tree.mirror(Tree.root);
    Tree.iinorder(Tree.root);

    cout << "\n\nNumber of internal nodes: " << Tree.internal(Tree.root);

    cout << "\n\nNumber of leaves: " << Tree.leaf(Tree.root);
    
    cout << "\n\nHeight of the tree: " << Tree.height(Tree.root);

    vector <int> ans = Tree.levelOrder(Tree.root);
    cout << "\n\nLevel order traversal: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}