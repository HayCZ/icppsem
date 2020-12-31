#pragma once

template<typename T>
class DynamicArray {
public:
	DynamicArray();
	~DynamicArray();
	// - pøidá element na konec pole
	void append(const T& element);
	// - výjimky pøi neplatném nebo nekorektním indexu
	const T& getElementAt(int index) const;
	void removeElementAt(int index);
	// - vrací velikost (poèet prvkù) v poli
	int getSize() const;
private:
	T* array;
	int count;
};

template<typename T>
DynamicArray<T>::DynamicArray()
{
	array = new T[0];
	count = 0;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	if (this->array != nullptr)
	{
		delete[] this->array;
	}
}

template<typename T>
void DynamicArray<T>::append(const T& element)
{
	this->count++;
	T* temp = new T[this->count];

	for (int i = 0; i < this->count - 1; i++)
	{
		temp[i] = this->array[i];
	}

	temp[this->count - 1] = element;

	if (this->array != nullptr)
	{
		delete[] this->array;
	}

	this->array = temp;
}

template<typename T>
const T& DynamicArray<T>::getElementAt(int index) const
{
	return array[index];
}

template<typename T>
void DynamicArray<T>::removeElementAt(int index)
{
	this->count--;
	T* temp = new T[this->count];

	bool foundAlready = false;
	for (int i = 0; i < this->count + 1; i++)
	{
		if (i == index) {
			foundAlready = true;
		}
		else {
			if (foundAlready) {
				temp[i - 1] = this->array[i];
			}
			else {
				temp[i] = this->array[i];
			}
		}
	}

	if (this->array != nullptr)
	{
		delete[] this->array;
	}

	this->array = temp;
}

template<typename T>
int DynamicArray<T>::getSize() const
{
	return count;
}
