#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Set
{
	vector<T> arr;
public:
	Set();
	Set(vector<T> obj);
	~Set();

	void show_set();
	void push_element(const T & obj);
	void crossing_elements(Set & obj);

	Set operator+(const Set & obj);
	Set operator-(const Set & obj);
};


template <class T>
Set<T>::Set()
{
	arr = { 0, 0, 0, 0, 0 };
}

template <class T>
Set<T>::Set(vector<T> obj)
{
	arr = obj;
}

template <class T>
Set<T>::~Set()
{

}

template <class T>
void Set<T>::show_set()
{
	for (auto it = arr.begin(); it != arr.end(); ++it)
		cout << *it << "  ";
	cout << endl;
}

template <class T>
void Set<T>::push_element(const T & obj)
{
	arr.push_back(obj);
}

template <class T>
void Set<T>::crossing_elements(Set & obj)
{
	cout << "\nCrossing elements of sets:\n";
	vector <T> vec;
	sort(arr.begin(), arr.end());
	sort(obj.arr.begin(), obj.arr.end());

	set_intersection(arr.begin(), arr.end(),
		obj.arr.begin(), obj.arr.end(),
		back_inserter(vec));

	for (auto it = vec.begin(); it != vec.end(); ++it)
		cout << *it << "  ";
	cout << endl;

}

template <class T>
Set<T> Set<T>::operator+(const Set<T> & obj)
{
	Set<T> tmp;
	if (arr.size() == obj.arr.size()) {
		tmp.arr.resize(arr.size());
		for (int i = 0; i < obj.arr.size(); i++)
			tmp.arr[i] = this->arr[i] + obj.arr[i];
		return tmp;
	}
	else
	{
		cout << "Error. The sizes are different.\n";
		return tmp;
	}

}

template <class T>
Set<T> Set<T>::operator-(const Set<T> & obj)
{
	Set<T> tmp;
	if (arr.size() == obj.arr.size()) {
		tmp.arr.resize(arr.size());
		for (int i = 0; i < obj.arr.size(); i++)
			tmp.arr[i] = this->arr[i] - obj.arr[i];
		return tmp;
	}
	else
	{
		cout << "Error. The sizes are different.\n";
		return tmp;
	}
	
}