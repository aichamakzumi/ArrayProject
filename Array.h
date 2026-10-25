#pragma once
#include <iostream>

using namespace std;

template <class T>
class Array
{
	T* data;
	int size;
	int count;
	int grow;

public:
	Array();
	Array(int size, int grow = 1);
	Array(const Array<T>& other);
	~Array();

	int GetSize() const;
	void SetSize(int size, int grow = 1);
	int GetUpperBound() const;
	bool IsEmpty() const;
	void FreeExtra();
	void RemoveAll();

	T GetAt(int index) const;
	void SetAt(int index, const T& value);

	T& operator[](int index);
	const T& operator[](int index) const;

	void Add(const T& value);
	void Append(const Array<T>& other);
	Array<T>& operator=(const Array<T>& other);

	T* GetData();
	const T* GetData() const;

	void InsertAt(int index, const T& value);
	void RemoveAt(int index);

	void Print() const;
};

template <class T>
Array<T>::Array()
{
	this->data = nullptr;
	this->size = 0;
	this->count = 0;
	this->grow = 1;
}

template <class T>
Array<T>::Array(int size, int grow)
{
	this->data = nullptr;
	this->size = 0;
	this->count = 0;
	this->grow = (grow > 0 ? grow : 1);

	if (size > 0)
	{
		this->SetSize(size, this->grow);
	}
}

template <class T>
Array<T>::Array(const Array<T>& other)
{
	this->size = other.size;
	this->count = other.count;
	this->grow = other.grow;

	if (this->size > 0)
	{
		this->data = new T[this->size];
		for (int i = 0; i < this->count; i++)
		{
			this->data[i] = other.data[i];
		}
	}
	else
	{
		this->data = nullptr;
	}
}

template <class T>
Array<T>::~Array()
{
	delete[] this->data;
}

template <class T>
int Array<T>::GetSize() const
{
	return this->size;
}

template <class T>
void Array<T>::SetSize(int size, int grow)
{
	if (grow > 0)
	{
		this->grow = grow;
	}

	if (size < 0)
	{
		size = 0;
	}

	if (size == this->size)
	{
		return;
	}

	if (size == 0)
	{
		delete[] this->data;
		this->data = nullptr;
		this->size = 0;
		this->count = 0;
		return;
	}

	T* newData = new T[size];
	int copyCount = (this->count < size ? this->count : size);

	for (int i = 0; i < copyCount; i++)
	{
		newData[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newData;
	this->size = size;
	this->count = copyCount;
}

template <class T>
int Array<T>::GetUpperBound() const
{
	return this->count - 1;
}

template <class T>
bool Array<T>::IsEmpty() const
{
	return this->count == 0;
}

template <class T>
void Array<T>::FreeExtra()
{
	if (this->count < this->size)
	{
		if (this->count == 0)
		{
			delete[] this->data;
			this->data = nullptr;
			this->size = 0;
		}
		else
		{
			T* newData = new T[this->count];
			for (int i = 0; i < this->count; i++)
			{
				newData[i] = this->data[i];
			}
			delete[] this->data;
			this->data = newData;
			this->size = this->count;
		}
	}
}

template <class T>
void Array<T>::RemoveAll()
{
	delete[] this->data;
	this->data = nullptr;
	this->size = 0;
	this->count = 0;
}

template <class T>
T Array<T>::GetAt(int index) const
{
	return (*this)[index];
}

template <class T>
void Array<T>::SetAt(int index, const T& value)
{
	if (index >= 0 && index < this->size)
	{
		this->data[index] = value;
		if (index >= this->count)
		{
			this->count = index + 1;
		}
	}
}

template <class T>
T& Array<T>::operator[](int index)
{
	return this->data[index];
}

template <class T>
const T& Array<T>::operator[](int index) const
{
	return this->data[index];
}

template <class T>
void Array<T>::Add(const T& value)
{
	if (this->count >= this->size)
	{
		int newSize = this->size + (this->grow > 0 ? this->grow : 1);
		this->SetSize(newSize, this->grow);
	}

	this->data[this->count] = value;
	this->count++;
}

template <class T>
void Array<T>::Append(const Array<T>& other)
{
	for (int i = 0; i < other.count; i++)
	{
		this->Add(other.data[i]);
	}
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] this->data;
	this->size = other.size;
	this->count = other.count;
	this->grow = other.grow;

	if (this->size > 0)
	{
		this->data = new T[this->size];
		for (int i = 0; i < this->count; i++)
		{
			this->data[i] = other.data[i];
		}
	}
	else
	{
		this->data = nullptr;
	}

	return *this;
}

template <class T>
T* Array<T>::GetData()
{
	return this->data;
}

template <class T>
const T* Array<T>::GetData() const
{
	return this->data;
}

template <class T>
void Array<T>::InsertAt(int index, const T& value)
{
	if (index < 0 || index > this->count)
	{
		return;
	}

	if (this->count >= this->size)
	{
		int newSize = this->size + (this->grow > 0 ? this->grow : 1);
		this->SetSize(newSize, this->grow);
	}

	for (int i = this->count; i > index; i--)
	{
		this->data[i] = this->data[i - 1];
	}

	this->data[index] = value;
	this->count++;
}

template <class T>
void Array<T>::RemoveAt(int index)
{
	if (index < 0 || index >= this->count)
	{
		return;
	}

	for (int i = index; i < this->count - 1; i++)
	{
		this->data[i] = this->data[i + 1];
	}

	this->count--;
}

template <class T>
void Array<T>::Print() const
{
	if (this->IsEmpty())
	{
		cout << "Array is empty" << endl;
		return;
	}

	for (int i = 0; i < this->count; i++)
	{
		cout << this->data[i] << " ";
	}
	cout << endl;
}
