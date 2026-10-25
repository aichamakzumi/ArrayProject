#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
	Array<int> arr;
	cout << "IsEmpty: " << arr.IsEmpty() << endl;

	arr.SetSize(5, 5);
	cout << "Initial size (allocated): " << arr.GetSize() << endl;

	for (int i = 1; i <= 4; i++)
	{
		arr.Add(i * 10);
	}

	cout << "Array elements: ";
	arr.Print();
	cout << "Upper bound: " << arr.GetUpperBound() << endl;
	cout << "GetSize: " << arr.GetSize() << endl;

	cout << "\nAdding 5th and 6th elements (test grow):" << endl;
	arr.Add(50);
	arr.Add(60);
	cout << "Array elements: ";
	arr.Print();
	cout << "Upper bound: " << arr.GetUpperBound() << endl;
	cout << "GetSize (increased by grow): " << arr.GetSize() << endl;

	cout << "\nGetAt(2): " << arr.GetAt(2) << endl;
	arr.SetAt(2, 99);
	cout << "After SetAt(2, 99): ";
	arr.Print();

	cout << "arr[1]: " << arr[1] << endl;
	arr[1] = 77;
	cout << "After arr[1] = 77: ";
	arr.Print();

	cout << "\nInsertAt(1, 111):" << endl;
	arr.InsertAt(1, 111);
	arr.Print();

	cout << "\nRemoveAt(1):" << endl;
	arr.RemoveAt(1);
	arr.Print();

	cout << "\nFreeExtra (current size = " << arr.GetSize() << "):" << endl;
	arr.FreeExtra();
	cout << "Size after FreeExtra: " << arr.GetSize() << endl;

	cout << "\nTesting Append:" << endl;
	Array<int> arr2;
	arr2.Add(1000);
	arr2.Add(2000);
	arr.Append(arr2);
	cout << "arr after Append: ";
	arr.Print();

	cout << "\nTesting GetData:" << endl;
	int* rawPtr = arr.GetData();
	cout << "First element via GetData(): " << *rawPtr << endl;

	cout << "\nTesting RemoveAll:" << endl;
	arr.RemoveAll();
	cout << "IsEmpty after RemoveAll: " << arr.IsEmpty() << endl;

	system("pause");
	return 0;
}
