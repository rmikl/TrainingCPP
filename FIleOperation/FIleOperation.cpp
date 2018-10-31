#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include "../Classes/Array.h"

using namespace std;


bool isNumber(string str)
{
    for (int i = 0 ; i < str.length()-1; i++)
    {
        if(str.find_first_not_of("0123456789"))
        {
            return false;
        }
        else return true;
    }
}



bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
//program that is reading only number from given files and store it in Array object defined in ../Classes/Array.h
int main()
{

    string location_of_file;
    ifstream file;
    cout<<"Give me the name of the file that you store "<<endl;
    cin>> location_of_file;
    file.open(location_of_file.c_str());
    string content_of_file;
    
    if(file.is_open())
    {
        while(!file.eof()){
            string tmp;            
            file >> tmp;
            if(is_number(tmp)){   

                tmp += '\n';
                content_of_file += tmp;
            }
        }
    }
    file.close();
    Array arr;

    cout << content_of_file << endl;
    for (int i = 0; i < content_of_file.length()-2 ; i+=2){
        int n = atoi(&content_of_file[i]);
        arr.AddElement(n);
    }

    cout  << "Content of created array from elements given from file: " << endl;

    arr.ShowArray();

    return 0;
}
