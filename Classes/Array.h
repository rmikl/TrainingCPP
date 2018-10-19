using namespace std;


class Array
{
	private:
		int * array;
		int arraySize;
		int numberOfElements;
		Array mergeArrayForMergeSort(Array left , Array right , Array mergedArray);
		Array splitArrayForMergeSort(Array splitedArray);
		Array quickSort(Array array, int beginIndex,int endIndex);
		int partitionIndex(Array array, int beginIndex, int endIndex);

	public:
		Array();
		~Array();
		void ExpandArray();
		void AddElement(int newElement);
		int GetNumberOfElements();
		int GetElementWithIndex(int index);
		void SetElementWithIndex(int index, int value);
		void InitializeArray(int from);
		void ShowArray();
		void BubleSort();
		int MaxValue();
		int MinValue();
		double Median();
		int operator[](int i)
		{
			if(i > numberOfElements){
				cout << "Index out of Bound"<<endl;
				return array[0];
			}
			return array[i];
		}


		void MergeSort();
		void QuickSort();


	
		
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


void Array::SetElementWithIndex(int index, int value)
{
//	cout<< "SetElementWithIndex exec"<<endl;
	while(index > arraySize)
	{
	//	cout << "expand array" << endl;
		ExpandArray();
	}
	array[index]=value;
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

int Array::MaxValue()
{
	int max;
	max = 0;
	for (int i = 0 ; i < numberOfElements ; i++){
		if(array[i] > max){
			max = array[i];
		}
	}
	return max;
}

int Array::MinValue()
{
	int min;
	min =0;
	for (int i = 0 ; i < numberOfElements ; i++){
		if(array[i] < min){
			min = array[i];
		}
	}
	return min;
}

double Array::Median()
{
	BubleSort();
	if(numberOfElements % 2 == 0){
		return (array[numberOfElements/2] + array[(numberOfElements/2)-1]) / 2 ;
	}
	else if (numberOfElements %2 == 1)
	{
		return array[(numberOfElements-1)/2];
	}
	return 0;
}


Array Array::mergeArrayForMergeSort(Array left, Array right, Array mergedArray)
{	
//	cout << "merge exec" << endl;
	int i,j,k,nL,nR;
	i=j=k=0;
	nL = left.GetNumberOfElements();
	nR = right.GetNumberOfElements();
//	cout << "nL : " << nL << endl;;
//	cout << "nR : " << nR << endl;
	while(i < nL && j < nR)
	{

//		cout << "inside 1 while!!!!! " <<endl;
//		cout << "left[i] : " << left.GetElementWithIndex(i) << endl; 
//		cout << "right[j] : "<< right.GetElementWithIndex(j)<<endl;
//		cout << " i : " << i <<endl;
//		cout << " j : " << j<< endl;
//		cout << " k : " << k<< endl;
//		cout << " nL : " << nL<<endl;
//		cout << " nR : " << nR<<endl;



		if (left.GetElementWithIndex(i) <= right.GetElementWithIndex(j))
		{	
//			cout << "inside if!!!!! " <<endl;
			mergedArray.SetElementWithIndex(k, left.GetElementWithIndex(i));
//			cout << "left [i] : " << left.GetElementWithIndex(i) <<endl ;
//			cout << "mergedArray[k] : " << mergedArray.GetElementWithIndex(k)<<endl;
			i++;
			k++;
		}else 
		{
//			cout << "inside else!!!!! " <<endl;
			mergedArray.SetElementWithIndex(k, right.GetElementWithIndex(j));
//			cout << "right [j] : " << right.GetElementWithIndex(j) <<endl ;
//			cout << "mergedArray[k] : " << mergedArray.GetElementWithIndex(k)<<endl;
			k++;
			j++;
		}		
	}
	while (i < nL){
//		cout << "inside 2 while!!!!! " <<endl;
//		cout << "left[i] : " << left.GetElementWithIndex(i) << endl; 
		mergedArray.SetElementWithIndex(k,left.GetElementWithIndex(i));
//					cout << "mergedArray[k] : " << mergedArray.GetElementWithIndex(k)<<endl;

		i++;
		k++;
	}
	while (j < nR){
//		cout << "inside 3 while!!!!! " <<endl;
//		cout << "right[j] : "<< right.GetElementWithIndex(j)<<endl;
		mergedArray.SetElementWithIndex(k, right.GetElementWithIndex(j));
//					cout << "mergedArray[k] : " << mergedArray.GetElementWithIndex(k)<<endl;

		j++;
		k++;
	}
	return mergedArray;
}

Array Array::splitArrayForMergeSort(Array splitedArray)
{
//	cout << "splitArrayForMergeSort exec" << endl;
	int length;
	length = splitedArray.GetNumberOfElements();
//	cout << "length : " << length << endl;
	if(length < 2) return splitedArray;

	int middle;


	if(length %2 == 1) middle = (length-1)/2;
	else middle = length/2;

//	cout << "middle : " << middle << endl;

	Array left;
	Array right;

	for (int i = 0 ; i < middle ; i++){
		left.AddElement(splitedArray[i]);
	}
	for (int i = middle ; i < length ; i++){
		right.AddElement(splitedArray[i]);
	}

//	cout << "left :";
	splitArrayForMergeSort(left);
//	cout << "right : ";
	splitArrayForMergeSort(right);
	mergeArrayForMergeSort(left, right, splitedArray);
	return splitedArray;
}

void Array::MergeSort()
{
	Array arr;
	for (int i = 0 ; i < numberOfElements ; i++){
		arr.AddElement(array[i]);
	}	
	arr = splitArrayForMergeSort(arr);

	for(int i = 0 ; i < numberOfElements ; i ++)
	{
		array[i] = arr.GetElementWithIndex(i);
	}
}

Array Array::quickSort(Array array, int beginIndex, int endIndex)
{
//	cout << "inside quicksort method"<<endl;
	if(beginIndex < endIndex)
	{
		int pIndex;
		pIndex = partitionIndex(array, beginIndex, endIndex);
		array.quickSort(array,beginIndex, pIndex - 1);
		array.quickSort(array, pIndex + 1  , endIndex);
	}
	return array;
}

int Array::partitionIndex(Array array , int beginIndex, int endIndex)
{
//	cout << "inside partition idex"<<endl;
	int pivot = array.GetElementWithIndex(endIndex);
	int partitionIndex = beginIndex;

	for (int i = beginIndex ; i < endIndex ; i++)
	{
//		cout << "inside partition idex inside for"<<endl;
		if(array[i]<= pivot)
		{
			int tmp;
			tmp = array.GetElementWithIndex(i);
			array.SetElementWithIndex(i,array.GetElementWithIndex(partitionIndex));
			array.SetElementWithIndex(partitionIndex,tmp);
			partitionIndex++;
		}
	}
	int tmp;
	tmp = array.GetElementWithIndex(partitionIndex);
	array.SetElementWithIndex(partitionIndex,array.GetElementWithIndex(endIndex));
	array.SetElementWithIndex(endIndex,tmp);
	return partitionIndex;
}

void Array::QuickSort()
{
	Array arr;
	for (int i = 0 ; i < numberOfElements ; i++){
		arr.AddElement(array[i]);
	}	
	arr = arr.quickSort(arr,0,numberOfElements-1);

	for(int i = 0 ; i < numberOfElements ; i ++)
	{
		array[i] = arr.GetElementWithIndex(i);
	}
}


