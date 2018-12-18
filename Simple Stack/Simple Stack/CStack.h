#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

namespace mylib
{
	template <class T>
	class stack
	{
	public:
		stack(int iSize = 0);
		~stack();

		bool push(T iData);
		bool pop(T *pOut);
		bool peek(T *pOut);
		void Print();

		int size();
		int stacksize();
		bool empty();

	protected:
		T * _pStack;
		int _Top;
		int _Size;
	};

	template <class T>
	inline stack<T>::stack(int iSize) :_Size(iSize), _Top(0)
	{
		_pStack = new T[_Size];
	}

	template <class T>
	inline stack<T>::~stack()
	{
		delete[] _pStack;
	}

	template <class T>
	inline bool stack<T>::push(T iData)
	{
		if (_Top >= _Size)
			return false;
		_pStack[_Top++] = iData;
		return true;
	}

	template <class T>
	inline bool stack<T>::pop(T *pOut)
	{
		if (_Top == 0)
			return false;
		*pOut = _pStack[--_Top];
		return true;
	}

	template <class T>
	inline bool stack<T>::peek(T *pOut)
	{
		if (_Top == 0)
			return false;
		*pOut = _pStack[_Top - 1];
		return true;
	}

	template <class T>
	inline void stack<T>::Print()
	{
		cout << "[ ";
		for (T i = 0; i < _Top; i++)
			cout << _pStack[i] << " ";
		cout << "]" << endl;
	}

	template <class T>
	inline int stack<T>::size()
	{
		return _Top;
	}

	template <class T>
	inline int stack<T>::stacksize()
	{
		return _Size;
	}

	template <class T>
	inline bool stack<T>::empty()
	{
		if (_Top == 0)
			return true;
		return false;
	}
}
#endif