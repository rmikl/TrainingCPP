class Array
{
	private:
		int* array=NULL;
		int arraySize;
	public:
		
		Array();
		int GetSize(){return arraySize;};
		int GetElement(int index)
		{
			return array[index-1];
		};
		void AddElement(int newElement)
		{
			if (array==NULL)
			{
				arraySize=1;
				array = new int[arraySize];
				array[0] = newElement;
			}
			else
			{
				
				int* newArray = new int [arraySize];
				for (int i = 0 ; i < arraySize-1;i++)
				{
					newArray[i]=array[i];
				}
				delete array;
				newArray[arraySize-1]=newElement;
				array = new int[arraySize];
				for (int i = 0; i< arraySize-1 ; i++)
				{
					array[i]=newArray[i];
				}
 				delete newArray;
			};

		};
};


Array::Array()
{
	array = new int[0];
	arraySize=0;	
};


