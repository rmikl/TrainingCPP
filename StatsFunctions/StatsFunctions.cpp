#include<iostream>
#include "../Classes/Array.h"
using namespace std;

int main()
{
    Array array;
    int numberToAdd;
    int amount;

    cout << "How much numbers you want to add to array ? " << endl;
    cin >> amount;

    for (int i = 0 ; i < amount; i++)
    {
        cin >> numberToAdd;
        array.AddElement(numberToAdd);
    }

    cout << "Content of an array: " << endl;
    array.ShowArray();

    cout << "Stats:" << endl;
    cout << array.MinValue() << " : MIN"<<endl;
    cout << array.MaxValue() << " : MAX"<<endl;
    cout << array.Median() << " : MEDIAN" << endl;


    

    return 0;
}


