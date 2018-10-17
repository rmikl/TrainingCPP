#include<iostream>
#include "../Classes/Array.h"
using namespace std;

int main()
{
    Array array;
    int amount;
    int numberToAdd;

    cout << "How much numbers you want to add to array ? " << endl;
    cin >> amount;

    for (int i = 0 ; i < amount; i++)
    {
        cin >> numberToAdd;
        array.AddElement(numberToAdd);
    }
    
    cout << "Array Before Sort: " << endl;
    array.ShowArray();

    array.QuickSort();
    cout << "Array After Sort: " << endl;
    array.ShowArray();
    return 0;
}