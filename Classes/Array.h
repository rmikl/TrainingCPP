using namespace std;


class Array
{
	private:
		int * array;
		int arraySize;
		int numberOfElements;
	public:
		Array();
		~Array();
		void ExpandArray();
		void AddElement(int newElement);
		int GetNumberOfElements();
		int GetElementWithIndex(int index);
		void InitializeArray(int from);
		void ShowArray();
		void BubleSort();
		void MergeWithArray(int * array);
};

Array::Array(){
	arraySize=5;
	numberOfElements=0;
	array = new int[arraySize];
};

Array::~Array(){
	delete [] array;
}

void Array::ExpandArray(){
	arraySize = arraySize *2;
	int * tmpArray = new int [arraySize];
	
	for (int i = 0 ; i < numberOfElements; i++ )
	{
		tmpArray[i]=array[i];
	}
	delete array;
	array = tmpArray;
	delete tmpArray;
	InitializeArray(numberOfElements);
}


void Array::InitializeArray(int from )
{
	for(int i = from ; i< arraySize ; i++)
	{
		array[i] = 0;
	}
}

void Array::AddElement(int newElement){
	if (arraySize == numberOfElements )
	{
		ExpandArray();
	}
	array[numberOfElements]=newElement;
	numberOfElements++;
}

int Array::GetNumberOfElements()
{
	return numberOfElements;
}

int Array::GetElementWithIndex(int index)
{
	return array[index];
}

void Array::ShowArray(){
	for (int i = 0 ; i < numberOfElements ; i++)
	{
		cout << array[i] << endl;
	}
}

void Array::BubleSort()
{
	int tmp;
	for (int i = 0 ; i < numberOfElements - 1 ; i++)
	{
		for (int j = 0 ; j < numberOfElements - i - 1 ; j ++)
		{
			if (array[j] > array[j+1]) 
			{
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}
	}
}