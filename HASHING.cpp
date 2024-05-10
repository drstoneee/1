#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Client {

    public:
        string name;
        long long phone;

    Client () {
        name = "";
        phone = 0;
    }

    Client (string n, long long p) {
        name = n;
        phone = p;
    }
};

class HashTable {

    Client *clients;
    int tableSize;

    public:

        HashTable (int n) {
            tableSize = n;
            clients = new Client [n];
        }

        int hashFunction(string name)
        {
            int index = 0;

            for (int i = 0; i < name.length(); i++)
                index += int(name[i]);

            index = index % tableSize;

            return index;
        }

        bool isFull ()
        {
            for (int i = 0; i < tableSize; i++)
                if (clients[i].name == "")
                    return false;
            return true;
        }


        void insert (string name, long long phone)
        {
            int index = hashFunction(name);
            clients[index] = Client(name, phone);

        }

        void insertWoReplacement (string name, long long phone)
        {

            if (isFull())
            {
                cout << "Full" << endl;
                return;
            }
           
           int index = hashFunction(name);

            while (clients[index].name != "")
                index = (index + 1) % tableSize;

            clients[index] = Client(name, phone);
            
            
        }

        void insertWReplacement (string name, long long phone)
        {
            if(isFull())
            {
                cout << "Full" << endl;
                return;
            }
            
            int index = hashFunction(name);
            
             if (clients[index].name == "")
             {
                 clients[index] = Client(name, phone);
             }

             else{
              if (hashFunction(clients[index].name)%10==index){

                while (clients[index].name != "")
                    index = (index + 1) % tableSize;

                clients[index] = Client(name, phone);
                return;
              }
              else{
                Client temp = clients[index];

                clients[index] = Client(name, phone);

                insertWReplacement(temp.name, temp.phone);
                return;
              }

              
              
             }
        }


        void search (string name)
        {
            int index = hashFunction(name);
            int x = index;
            if (clients[index].name == name){
                cout << "Client exists" << endl;
                return;
            }
            index++;
            while (index!=x)
            {
                if (clients[index].name == name)
                {
                cout << "Client exists" << endl;
                return;
                }
            index = (index + 1) % tableSize;

            }
            cout<<"Client does not exist"<<endl;

            // while (clients[index].name!="")
            // {
            // if (clients[index].name == name)
            //     cout << "Client exists" << endl;
            // else if (clients[index].name=="")
            //     cout << "Client does not exist" << endl;
            // }
        }


        void display ()
        {
            for (int i = 0; i < tableSize; i++)
                cout << i<<"-->" <<clients[i].name << " " << clients[i].phone << endl;
        }

};

int main ()
{

    int n;
    cout << "Enter number of clients : ";
    cin >> n;
    HashTable t(n);
    string name;
    long long phone;
    

    // t.insertWoReplacement("Nilay", 1234567890);
    // t.insertWReplacement("Nilay", 6666666);
    t.insertWReplacement("Akahs", 1234567890);
    t.insertWReplacement("Akash", 1234567890); 
    t.insertWReplacement("Nilay", 1234567890);
    // t.insertWReplacement("Anubhav", 1234567890);
    t.display();
    t.search("hh");

    return 0;
}
