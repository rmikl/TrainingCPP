using namespace std;


class Array
{
	private:
		int * array;
		int arraySize;
		int numberOfElements;
		Array mergeArrayForMergeSort(Array& left , Array& right , Array& mergedArray);
		Array splitArrayForMergeSort(Array& splitedArray);
		Array quickSort(Array, int beginIndex,int endIndex);
		int partitionIndex(Array& array, int beginIndex, int endIndex);
		
	public:
		Array(Array&);
		Array();
		~Array();
		Array& operator=(const Array&);
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
		int& operator[](int);
		int * GetAddr(int);
		void MergeSort();
		void QuickSort();
		Array Swap(int,int);
};

int * Array::GetAddr(int index)
{
	return &array[index];
}

Array::Array( Array& src)
{
	arraySize = src.arraySize;
	numberOfElements = src.numberOfElements;
	array = new int[src.arraySize];
	copy(src.array,src.array+numberOfElements,array);
}

Array::Array(){
	arraySize=5;
	numberOfElements=0;
	array = new int[arraySize];
}
//Array::Array(Array arr)
//{
//	arraySize = arr.GetNumberOfElements()+1;
//	numberOfElements=0;
//	array = new int[arraySize];
//
//	for (int i = 0 ; i < numberOfElements; i++)
//	{
//		array[i] = arr.GetElementWithIndex(i);
//	}
//	
//}


Array::~Array(){
	delete [] array;
}

Array& Array::operator=(const Array& src)
{
	if(this!=&src)
	{
		arraySize = src.arraySize;
		numberOfElements = src.numberOfElements;
		array = new int[src.arraySize];
		copy(src.array,src.array+numberOfElements,array);
		return *this;
	}
	else
	{
		return *this;
	}
}

void Array::ExpandArray(){
	arraySize = arraySize * 2;
	int * tmpArray = new int [arraySize];
	
	for (int i = 0 ; i < numberOfElements; i++ )
	{
		tmpArray[i]=array[i];
	}
	delete array;
	array = new int[arraySize];
	for (int i = 0 ; i < numberOfElements ; i++)
	{
		array[i]=tmpArray[i];
	}
	delete tmpArray;
	InitializeArray(numberOfElements);
}

int& Array::operator[](int i)			
{
	return array[i];
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
	{//	cout << "w expland array"<< endl;
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
	if(index >= numberOfElements || index < 0)
	{
		cout << "wanted element is out of index" << endl;
		return -1;
	}
	
return array[index];
}


void Array::SetElementWithIndex(int index, int value)
{
//	cout<< "SetElementWithIndex exec"<<endl;
	while(index >= arraySize)
	{
	//	cout << "expand array" << endl;
		ExpandArray();
	}
	array[index]=value;
}

void Array::ShowArray(){
	for (int i = 0 ; i < numberOfElements ; i++)
	{
	//	cout << GetAddr(i)<< " : address of arra[]"<< endl;
		cout << array[i] << " | adres : " << GetAddr(i) << endl;
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


Array Array::mergeArrayForMergeSort(Array& left, Array& right, Array& mergedArray)
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

Array Array::splitArrayForMergeSort(Array& splitedArray)
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
	
//	cout << "jak wyglada tablica przekazana to qiockSort" << endl;
//	array.ShowArray();
//	cout << beginIndex << " : beginIndex"<<endl;
//	cout << endIndex << " : endIndex " << endl;
//	cout << "inside quicksort method"<<endl;
	if(beginIndex <endIndex)
	{
		int pIndex;
		pIndex = partitionIndex(array, beginIndex, endIndex);
//		cout << "left" << endl;
		array=array.quickSort(array,beginIndex, pIndex - 1);
//		cout <<"right" << endl;
		array=array.quickSort(array,  pIndex +1, endIndex);
	}
//	cout << "jak wyglada tablica wychodzaca z qiockSort" << endl;
//	array.ShowArray();
	return array;
}

int Array::partitionIndex(Array& ar , int beginIndex, int endIndex)
{
//	cout << "inside partition idex"<<endl;
	int pivot = ar.GetElementWithIndex(endIndex);
//	cout << pivot << " : pivot"<< endl;
	int partitionIndex = beginIndex;
//	cout << "jak wyglada tablica przekazana to partition index" << endl;
//	ar.ShowArray();
//	cout << beginIndex << " : beginIndex" << endl;
//	cout << endIndex << " : endIndex" <<  endl;
	for (int i = beginIndex ; i < endIndex  ; i++)
	{
//		cout << partitionIndex << " : partiotionIndex !!!!!!!!!!"<< endl;
//		cout << i << " : i !!!!!!!!!!"<< endl;
//		cout << ar.GetElementWithIndex(i) << " : array[i]" << endl;
//		cout << "w partitionIndex w for"<<endl;
		if(ar.GetElementWithIndex(i)<= pivot)
		{
//			cout << i << " : i" << endl;
//			cout << ar.GetElementWithIndex(i) << " : array[i]" << endl;
//			cout << ar.GetElementWithIndex(partitionIndex) << " : array[pI]" << endl;
			int tmp;
			tmp = ar.GetElementWithIndex(i);
			ar.SetElementWithIndex(i,ar.GetElementWithIndex(partitionIndex));
			ar.SetElementWithIndex(partitionIndex,tmp);
			partitionIndex++;
//			cout << "swap" << endl;
			
//			cout << ar.GetElementWithIndex(i) << " : array[i]" << endl;
//			cout << ar.GetElementWithIndex(partitionIndex) << " : array[pI]" << endl;
//			ar.ShowArray();
		}
	}
//	cout << "w partitionIndex po for"<<endl;
	int tmp;
	tmp = ar.GetElementWithIndex(partitionIndex);
	ar.SetElementWithIndex(partitionIndex,ar.GetElementWithIndex(endIndex));
	ar.SetElementWithIndex(endIndex,tmp);
//	cout << partitionIndex<< " : partition Index"<<endl;
//	cout << "jak wyglada tablica na na koniec partiotionIndex ktora zostanie przekazana do quick sort"<< endl;
//	ar.ShowArray();
//	cout << partitionIndex << " : wynik partiotionIndex" << endl;
	return partitionIndex;
}

void Array::QuickSort()
{
	Array arr;
	for (int i = 0 ; i < numberOfElements ; i++){
		arr.AddElement(array[i]);
	}
//	arr.ShowArray();	
//	cout << "ilosc el w tablicy " << arr.GetNumberOfElements() << endl;
	arr=arr.quickSort(arr,0,numberOfElements-1);

	for(int i = 0 ; i < numberOfElements ; i ++)
	{
		array[i] = arr.GetElementWithIndex(i);
	}
	
}



Array Array::Swap(int first, int second)
{

	int tmp;
	int * b = &array[first];
	int * c = &array[second];
	
	tmp = * b;
	* b = * c;
	* c = tmp;
	
//	cout << "inside swap"  << endl;
//	cout << first << " : first"<<endl;
//	cout << second << " : second" << endl;
//	if (first >= numberOfElements || second >= numberOfElements || first < 0 || second < 0)
//	{cout << "inside if" << endl;
//		return;
//	}
//	else 
//	{
//		for (int i = first ; i < second;i++)
//		{
//			cout << first << " : arr[]++ "<<endl;
//			i++;
//		
//		}
//		cout << *(array+first) << " : arr[1] "<< endl;
//		cout << *(array+second) << " : arr[2] "<< endl;
//		//std::swap(arr[first],arr[second]);
		//tmp =arr[first];	
		//arr[first]=arr[second];
		//arr[second]=tmp;
	//}
}
