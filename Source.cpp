#include<iostream>
using namespace std;

/*	 Prime Factorization

	prime factors of 450

	2,3,3,5,5        |   5   | 
                     ---------
	                 |   5   |
	                 ---------          
	                 |   3   |
	                 ---------
	                 |   3   |
	                 ---------
                     |   2   |
	                 ---------
*/

int stack_arr[500];
int top = -1;

int isFull()
{
	if (top == stack_arr[500] - 1)
		return 1;
	else
		return 0;
}

int isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

void push(int data)
{
	if (isFull())
	{
		cout << " Stack overflow !" << endl;
		exit(1);
	}
	top++;
	stack_arr[top] = data;
}

int pop()
{
	int val;
	if(isEmpty())
	{
		cout << " Stack underflow !" << endl;
		exit(1);
	}
	val = stack_arr[top];
	top--;
	return val;
}

void prime_fac(int num)
{
	int i = 2;

	while (num != 1)
	{
		while (num%i == 0)
		{
			push(i);
			num = num / i;
		}
		i++;
	}
	cout << "Prime factor of the number in decending order are as follow : ";
	while (top != -1)
	{
		cout << pop();
	}
}

int main()
{
	int no;

	cout << " Enter a positive number: ";
	cin >> no;

	prime_fac(no);
	return 0;
}