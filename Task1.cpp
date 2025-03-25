#include<iostream>
using namespace std;

template<class type>
class List
{
private:
	type* arr;
	int currentSize;
	int maxSize;
public:
	~List()
	{
		delete[] arr;
	}
	List(const int& maxSize_ = 0)
	{
		currentSize = 0;
		maxSize = maxSize_;
		arr = new type[maxSize];
	}
	List(const List<type>& l)
	{
		currentSize = l.currentSize;
		maxSize = l.maxSize;
		arr = new type[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
			arr[i] = l.arr[i];
		}
	}
	void addElementAtFirstIndex(type element)
	{
		if (currentSize <= maxSize)
		{
			for (int i = 0; i < currentSize; i++)
			{
				arr[i + 1] = arr[i];
			}
			arr[0] = element;
		}
		else
		{
			cout << "Array is Full" << endl;
		}
	}
	void addElementAtLastIndex(type element)
	{
		arr[currentSize++];
		arr[currentSize] = element;
	}
	type removeElementFromEnd()
	{
		return arr[--currentSize];
	}
	void removeElementFromStart()
	{
		for (int i = 0; i < currentSize; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
};


int main()
{

	List<int> intList(5);
	intList.addElementAtLastIndex(20);
	intList.addElementAtFirstIndex(5);
	intList.removeElementFromStart();
	intList.removeElementFromEnd();

	return 0;
}