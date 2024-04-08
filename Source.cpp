/*
Program name: IntStack.cpp
Programmer: Tyler Davies
Date: 10-28-21
Version: 1.0
Description: This program implements the IntStack class which stores a static stack of integers. It
			 creates a stack of numbers 10, 20, 30, 40, and 50. The main function then tests the pop,
			 push, isFull, and isEmpty member functions.
*/

#include<iostream>
using namespace std;

//This class contains a pointer to an integer array, and two integers to hold the size of the array
//and the top index. It has member functions to perform the standard operations of a static stack.
class IntStack
{
private:
	int *array, size, top;
public:
	IntStack();
	void pop(int &);
	void push(int);
	bool isFull() const;
	bool isEmpty() const;
	void print() const;
	~IntStack()
		{ delete [] array; }
};

//The constructor dynamically creates an integer stack array to hold five values (10, 20, 30, 40, and 50).
IntStack::IntStack()
{
	size = 5;
	array = new int[size] { 10, 20, 30, 40, 50 };
	top = 4;
}

//This function first checks if the stack is empty by calling the isEmpty() member function. It then
//takes the top value off of the stack, and stores it in its parameter which was passed-by-reference.
void IntStack::pop(int &num)
{
	if (isEmpty())
		cout << "The stack is empty." << endl;
	else
	{
		num = array[top];
		top--;
	}
}

//This function first checks if the stack is full by calling the isFull() member function. It then
//increases the value of top to the next index, and stores the value in num on the top of the stack.
void IntStack::push(int num)
{
	if (isFull())
		cout << "The stack is full." << endl;
	else
	{
		top++;
		array[top] = num;
	}
}

//This function checks if the stack is full, and returns a boolean status of either true or false.
//If the value of top is equal to the last element in the array, then the stack is full. 
bool IntStack::isFull() const
{
	if (top == (size - 1))
		return true;
	else
		return false;
}

//This function checks if the stack is empty, and returns a boolean status of either true or false. If the
//value of top is equal to negative one, then there are no elements in the array and the stack is empty. 
bool IntStack::isEmpty() const
{
	if (top == -1)
		return true;
	else
		return false;
}

//This functions prints the stack elements on one line.
void IntStack::print() const
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

//The main function operates as a driver program to test each member function of the IntStack class.
int main()
{
	int number;    //Holds the values popped off the stack.
	IntStack stack;

	cout << "Starting integer stack: ";
	stack.print();
	cout << endl;

	cout << "Checking if stack is full: ";
	if (stack.isFull())
		cout << "The integer stack is currently full!";
	else
		cout << "The integer stack is not full!";
	cout << endl << endl;

	stack.pop(number);
	cout << "Popping off the top value:  " << number << endl;
	stack.pop(number);
	cout << "Popping off the next value: " << number << endl;
	stack.pop(number);
	cout << "Popping off the next value: " << number << endl;
	stack.pop(number);
	cout << "Popping off the next value: " << number << endl;
	stack.pop(number);
	cout << "Popping off the last value: " << number << endl << endl;

	cout << "Checking if stack is now empty: ";
	if (stack.isEmpty())
		cout << "The integer stack is currently empty!";
	else
		cout << "The integer stack is not empty!";
	cout << endl << endl;

	stack.push(5);
	cout << "Pushing the value 5 onto the integer stack." << endl;
	stack.push(10);
	cout << "Pushing the value 10 onto the integer stack." << endl;
	stack.push(15);
	cout << "Pushing the value 15 onto the integer stack." << endl;
	stack.push(20);
	cout << "Pushing the value 20 onto the integer stack." << endl;
	stack.push(25);
	cout << "Pushing the value 25 onto the integer stack." << endl << endl;

	cout << "Ending integer stack: ";
	stack.print();
	cout << endl;

	exit(0);
}