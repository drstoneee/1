#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node {

    public:

    int key;
    string value;
    Node* next;


    Node() {
        this->key = -1;
        this->value = "";
        this->next = NULL;
    }

    Node(int key, string value) {

        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};


class HashTable {   


    public:
        Node arr[10];

        int hashFunction (int key){

        return key % 10;
        }


        void insert (int key ,string value)
        {

            int index = hashFunction(key);
            Node *n = new Node(key,value);

            if (arr[index].key==-1)
            {
                arr[index] = *n;
            }
            else{

                Node *head = &arr[index];

                while (head->next!=NULL)
                {
                    head = head->next;
                }
                head->next = n;


            }

           

        }


        void display ()
        {
            for (int i = 0; i < 10; i++)
            {
                Node *head = &arr[i];

                while (head!=NULL)
                {
                    cout<<head->key<<"-"<<head->value<<"     ";
                    head = head->next;
                }
                cout << endl;
            }
        }


        void search (int key)
        {

            int index = hashFunction(key);

            Node *head = &arr[index];
            while (head!=NULL)
            {
                if (head->key==key)
                {
                    cout<<head->value<<endl;
                    cout << "KEY FOUND"<< endl;
                    return;

                }
                head = head->next;
            }
            cout<<"key not found"<<endl;
        }


        void H_delete (int key)
        {
            int index = hashFunction(key);

            Node *head = &arr[index];

            while (head->next!=NULL)
            {
                if (head->key==key)
                {
                    head->key = -1;
                    head->value = "DELETED";

                    break;


                }
                head = head->next;
            }

          
            
            
           
        }


};

int main ()
{

    HashTable t;
    t.insert(10, "10");
    t.insert(20, "20");
    t.insert(30, "30");
    t.insert(41, "41");

    t.search(20);

    t.display();

    t.H_delete(10);

    cout << endl
         << endl;

    t.display();

    return 0;
}