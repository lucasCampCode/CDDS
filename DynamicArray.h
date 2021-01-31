#pragma once
template<typename T>
class DynamicArray
{
public:
	DynamicArray<T>()
	{
		m_items = new T[m_length];
	}
	~DynamicArray<T>()
	{
		delete[] m_items;
	}
	void push(T item)
	{
		T* tempArray = new T[m_length + 1];
		for (int i = 0; i < m_length; i++)
		{
			tempArray[i] = m_items[i];
		}
		tempArray[m_length] = item;
		m_items = tempArray;
		m_length++;
	}
	bool remove(T item)
	{

		//If the scene is null then return before running any other logic
		if (!item)
			return false;

		bool Removed = false;

		//Create a new temporary array that is one less than our original array
		T* tempArray = new T[m_length - 1];

		//Copy all scenes except the scene we don't want into the new array
		int j = 0;
		for (int i = 0; i < m_length; i++)
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
	T pop()
	{
		T item = m_items[m_length - 1];
		remove(item);
		return item;
	}
	void sort()
	{
		for (int i = 0; i < m_length-1; i++) {
			for (int j = m_length-1; j > i; j--) {
				if (m_items[j] < m_items[j - 1]) {
					int temp = m_items[j];
					m_items[j] = m_items[j - 1];
					m_items[j - 1] = temp;
				}
			}
		}
	}
	bool getItem(int index,T* item)
	{
		if (!item)
			return false;
		if (index < 0 || index > m_length)
			return false;

		item = m_items[index];
		return true;
	}
	T get(int index) { return m_items[index]; }
	int getLength() { return m_length; }
private:
	T* m_items;
	int m_length;
};

