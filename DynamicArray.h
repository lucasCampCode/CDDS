#pragma once
#include <iostream>
template<typename T>
class DynamicArray
{
public:
	DynamicArray<T>();
	~DynamicArray<T>();
	void push(T item);
	void sort();
	void print();
	bool remove(T item);
	bool getItem(int index, T* item);
	int getLength() { return m_length; }
	T pop();
	T get(int index) { return m_items[index]; }

private:
	T* m_items;
	int m_length;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_items = nullptr;
	m_length = 0;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] m_items;
}

template<typename T>
inline void DynamicArray<T>::push(T item)
{
	T* temp = new T[getLength() + 1];
	for (int i = 0; i < getLength(); i++)
	{
		temp[i] = m_items[i];
	}
	temp[getLength()] = item;
	m_items = temp;
	m_length++;
}

template<typename T>
inline bool DynamicArray<T>::remove(T item)
{

	//If the scene is null then return before running any other logic
	if (!item)
		return false;

	bool Removed = false;

	//Create a new temporary array that is one less than our original array
	T* tempArray = new T[getLength() - 1];

	//Copy all scenes except the scene we don't want into the new array
	int j = 0;
	for (int i = 0; i < getLength(); i++)
	{
		if (tempArray[i] != item)
		{
			tempArray[j] = m_items[i];
			j++;
		}
		else
		{
			Removed = true;
		}
	}
	if (Removed)
	{
		m_items = tempArray;
		m_length--;
	}

	return Removed;
}

template<typename T>
inline T DynamicArray<T>::pop()
{
	T item = m_items[getLength() - 1];
	remove(item);
	return item;
}

template<typename T>
inline void DynamicArray<T>::sort()
{
	for (int i = 0; i < getLength(); i++)
	{
		for (int j = getLength() - 1; j > i; j--)
		{
			if (m_items[j] < m_items[j - 1])
			{
				T temp = m_items[j];
				m_items[j] = m_items[j - 1];
				m_items[j - 1] = temp;
			}
		}
	}
}

template<typename T>
inline bool DynamicArray<T>::getItem(int index, T* item)
{
	if (index < 0 || index > getLength())
		return false;

	item = &m_items[index];
	return true;
}

template<typename T>
inline void DynamicArray<T>::print()
{
	for (int i = 0; i < getLength(); i++)
		std::cout << m_items[i] << std::endl;
}
