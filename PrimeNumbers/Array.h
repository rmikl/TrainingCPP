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
