#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

public:
	Array(void) : _array(new T[0]), _size(0)
	{
		std::cout << "------empty array created------" << std::endl;
	};

	Array(unsigned int n) : _array(new T[n]), _size(n) 
	{
		std::cout << "------array created (size : " << n << " )------" << std::endl;
		std::cout << *this;
	};

	Array(const Array &src) : _array(new T[src._size]), _size(src._size)
	{
		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->_array[i] = src._array[i];
		}
	};

	Array &operator=(const Array &src)
	{
		if (this != &src)
		{
			T *new_arr = new T[src._size];
			for (unsigned int i = 0; i < src._size; i++)
			{
				new_arr[i] = src._array[i];
			}
			delete[] this->_array;
			this->_array = new_arr;
			this->_size = src._size;
		}
		return *this;
	}

	T getValue(unsigned int idx) const
	{
		return this->_array[idx];
	}

	unsigned int size() const
	{
		return this->_size;
	}

	T &operator[](unsigned int idx) const
	{
		std::cout << "콩스트" << "\n";
		if (static_cast<int>(idx) < 0 || idx >= this->_size)
		{
			throw IndexOutOfBoundException();
		}
		return this->_array[idx];
	};

	T &operator[](unsigned int idx)
	{
		std::cout << "안콩" << "\n";
		if (static_cast<int>(idx) < 0 || idx >= this->_size)
		{
			throw IndexOutOfBoundException();
		}
		return this->_array[idx];
	};

	class IndexOutOfBoundException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Array index out of bound exception.");
		}
	};

	~Array()
	{
		delete[] this->_array;
	};
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &ref)
{
	out << "----------array---------" << std::endl;
	for (unsigned int i = 0; i < ref.size(); i++)
	{
		out << i << " : " << ref.getValue(i) << std::endl;
	}
	out << "----------end of array---------" << std::endl;
	return out;
};

#endif