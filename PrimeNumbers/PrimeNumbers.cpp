#include<iostream>
#include "Array.h"
using namespace std;

int main()
{	
	int maxNumberToCheck;
	int counter=0;
	
	cout<<"Please give me number to which i'll check prime numbers"<<endl;
	cin>>maxNumberToCheck;

	Array arrayWithPrimeNumbers;
	cout<<"Size before: "; cout<<arrayWithPrimeNumbers.GetNumberOfElements()<<endl;
	
	
	for (int i = 2 ; i < maxNumberToCheck+1 ; i++)
	{
		if(i == 2){
			arrayWithPrimeNumbers.AddElement(i);
		}
		else{
			for (int j = 0 ; j < arrayWithPrimeNumbers.GetNumberOfElements() ; j++)
			{
				cout << "number before if i: "<< i << endl;
				cout << "number before if array[j]: " << arrayWithPrimeNumbers.GetElementWithIndex(j) << endl;
				int modulo = i % arrayWithPrimeNumbers.GetElementWithIndex(j);
				cout << "value of modulo: " << modulo << endl;

				if(modulo == 1){
					counter++;											
				}else if(modulo == 0){
					i++;
				}

				if(counter > 0){
					cout << "counter: " << counter << endl;
					arrayWithPrimeNumbers.AddElement(i);
					counter = 0;
					break;
				}

			}
		}
	}
	cout<<"Size After: "<<arrayWithPrimeNumbers.GetNumberOfElements()<<endl;

	for (int i = 0 ; i < arrayWithPrimeNumbers.GetNumberOfElements(); i++)
	{
		cout<<"array["<<i<<"] : "<<arrayWithPrimeNumbers.GetElementWithIndex(i)<<endl;
	}

	return 0;
}
