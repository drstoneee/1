#include <iostream>
#include <bits/stdc++.h>

using namespace std;



class Record 
{
    public:
        int roll, div;
        string name, address;

    Record (int roll,int div,string name,string address)

    {
        this->roll=roll;
        this->div=div;
        this->name=name;
        this->address=address;
    }

    friend class File;
};

class File 
{

    public:
        string fileName;
        fstream input;
        fstream output;

    File(string title)
    {
        this -> fileName = title;
    }

    void writeRecord(Record *r,int num)
    {
        output.open(fileName, ios::out);

        
            for (int i = 0; i < num; i++)
            {
                output<<r[i].roll<<","<<r[i].name<<",SE-"<<r[i].div<<","<<r[i].address<<endl;
            }
       

        output.close();
    }


    void printRecord()
    {
        input.open(fileName, ios::in);
        while (!input.eof())
        {
            string record;
            input >> record;
            cout << record << endl;
       }
        input.close();
    }

    void searchRecord(int r)
    {
        input.open(fileName, ios::in);
        bool isFound = false;
        while (!input.eof())
        {
            string record;
            input >> record;
            if(int(record[0]-48)==r)
            {
                cout << "Record found" << endl;
                cout << record << endl;
                cout << endl;
                isFound = true;
                break;
            }
        }
        input.close();
        if(!isFound)
        {
            cout << "Record not found...." << endl;
        }
    }


    void deleteRecord(int r)
    {
        input.open(fileName , ios::in);
        vector <string> lines;

        while(!input.eof())
        {
            string record;  
            input >> record;
            if((int(record[0])- 48) != r)
            {
                lines.push_back(record);
            }
        }

        input.close();

        output.open(fileName,ios::out);

        for (int i=0;i<lines.size();i++)
        {
            output << lines[i] << endl;
        }

        output.close();
    }

};


int main ()
{   
File f("anu.txt");
    Record r[3] = {
    Record(1,4,"Advait","Kothrud"),
    Record(2,5,"Shubham","Thane"),
    Record(3,6,"Kaustubh","Jalgaon")
    };
    int num = 3;


    

    f.writeRecord(r,num);
    f.printRecord();
    f.searchRecord(1);
    cout<<endl;
    f.deleteRecord(1);
    f.printRecord();

    return 0;
}