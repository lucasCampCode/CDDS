#pragma once
template<typename T,int N>
class DynamicArray
{
public:
	DynamicArray()
	{
		T m_items[N] = new T ();
		m_length = N;
	}
	~DynamicArray()
	{
		delete[] m_items;
	}
	void addItem(T item)
	{
		//If the scene is null then return before running any other logic
		if (!item)
			return -1;

		//Create a new temporary array that one size larger than the original
		T** tempArray = new T * [m_length + 1];

		//Copy values from old array into new array
		for (int i = 0; i < m_length; i++)
		{
			tempArray[i] = m_items[i];
		}

		//Store the current index
		int index = m_length;

		//Sets the scene at the new index to be the scene passed in
		tempArray[index] = item;

		//Set the old array to the tmeporary array
		m_items = tempArray;
		m_length++; 

		return index;
	}
	bool removeItem(T item)
	{

		//If the scene is null then return before running any other logic
		if (!item)
			return false;

		bool Removed = false;

		//Create a new temporary array that is one less than our original array
		T** tempArray = new T * [m_length - 1];

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

		//If the scene was successfully removed set the old array to be the new array
		if (Removed)
		{
			m_items = tempArray;
			m_length--;
		}

		return Removed;
	}
	void sortItems()
	{
		for (int i = 0; i < m_length; i++) {
			int swaped = 0;
			for (int j = m_length; j > i; j--) {
				if (m_items[j] < m_items[j - 1]) {
					T temp = m_items[j];
					m_items[j] = m_items[j - 1];
					m_items[j - 1] = temp;
					swaped++;
				}
			}
			if (swaped == 0)
				break;
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
	int getLength() { return m_length; }
private:
	T* m_items[1];
	int m_length;
};

