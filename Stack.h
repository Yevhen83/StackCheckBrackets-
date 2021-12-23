#pragma once
#include <iostream>
#include <ostream>
#include <climits>
#include <string>
#include <sstream>
using namespace std;

template<typename T>
class Stack
{
public:
	Stack(); // ����������� �� ���������
	Stack(const Stack& other); // ����������� �����������
	Stack(Stack&& other); // ����������� �����������
	~Stack(); // ����������
	Stack<T>& operator=(Stack&& other); // �������� �����������
	Stack<T>& operator=(const Stack& other); // �������� ������������
	T GetData();//���������� ������ ������� ����� (�������)
	friend ostream& operator<<<T> (ostream& out, const Stack& stack); // ���������� ��������� � �����
	bool IsEmpty(); // ���������, �������� �� stack ������.
	void Pop(); // ������� ������� �� ������� ����� stack.
	void Push(T item); // ��������� ������� � ������� ����� stack.
	int GetSize(); //���������� ���������� ��������� � ���������� stack.
	void SetCapacity(int capacity); // ��������� ��� ��������� ������� �����
private:
	T* _data;
	int _size;
	int _capacity;
};