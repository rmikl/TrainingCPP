#include<iostream>
#include "Array.h"
using namespace std;

int main()
{	
	int maxNumberToCheck;
	cout<<"Please give me number to which i'll check prime numbers"<<endl;
	cin>>maxNumberToCheck;

	Array arrayWithPrimeNumbers;
	cout<<"Size before: "; cout<<arrayWithPrimeNumbers.GetNumberOfElements()<<endl;
	arrayWithPrimeNumbers.AddElement(maxNumberToCheck);
	cout<<"Size after: "; cout<<arrayWithPrimeNumbers.GetNumberOfElements()<<endl;
//	for (int i=0;i<maxNumberToCheck;i++)
//	{
//		cout<<"inside first for"<<endl;
//		cout<<arrayWithPrimeNumbers.GetSize();
//		for (int j=0;j<arrayWithPrimeNumbers.GetSize(); j++)
//		{
//		cout<<"inside second for"<<endl;
//			if ( i % arrayWithPrimeNumbers.GetElement(j) != 0)
//			{
//				arrayWithPrimeNumbers.AddElement(i);				
//			}
//		} 		
//	}
//	for (int i=0 ; i < arrayWithPrimeNumbers.GetSize(); i++)
//	{	
//		cout<<arrayWithPrimeNumbers.GetElement(i)<<endl;
//	}
	return 0;
}
