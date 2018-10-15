#include<iostream>
//
#include "../Classes/Array.h"


using namespace std;

int main()
{	
	int maxNumberToCheck;
	
	cout<<"Please give me number to which i'll check prime numbers"<<endl;
	cin>>maxNumberToCheck;

	Array arrayWithPrimeNumbers;
//	cout<<"Size before: "; cout<<arrayWithPrimeNumbers.GetNumberOfElements()<<endl;
	
	
	for (int i = 2 ; i < maxNumberToCheck+1 ; i++)
	{
		if(i == 2){
			arrayWithPrimeNumbers.AddElement(i);
		}
		else
		{
			int counter ;
			counter =0 ;
			for (int j  = 0 ; j < arrayWithPrimeNumbers.GetNumberOfElements() ; j++)
			{
		//		cout << "number before if i: "<< i << endl;
		//		cout << "number before if array[j]: " << arrayWithPrimeNumbers.GetElementWithIndex(j) << endl;
				int modulo = i % arrayWithPrimeNumbers.GetElementWithIndex(j);
		//		cout << "value of modulo: " << modulo << endl;

				if(modulo == 1)
				{
					continue;
				}else if(modulo == 0)
				{
					counter++;
					break;
				}

			}
			if(counter == 0)
			{
		//		cout << "counter: " << counter << endl;
				arrayWithPrimeNumbers.AddElement(i);
				counter = 0;
			}
		}
	}
	
//	cout<<"Size After: "<<arrayWithPrimeNumbers.GetNumberOfElements()<<endl;
	cout << "list of prime numbers: "<< endl;
	for (int i = 0 ; i < arrayWithPrimeNumbers.GetNumberOfElements(); i++)
	{
		cout<<arrayWithPrimeNumbers.GetElementWithIndex(i)<<endl;
	}

	return 0;
}
