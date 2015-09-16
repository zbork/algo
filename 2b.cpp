#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>

int operate(int first, int second, char operation)
{
	switch (operation)
	{
		case '+':
		{
			return second + first;
		}
		case '-':
		{
			return second - first;
		}
		case '*':
		{
			return second * first;
		}
	}
}

int main ()
{
	freopen("postfix.in", "r", stdin);
	freopen("postfix.out", "w", stdout);

	std::stack<int> stack;
	char temp;
	char zero = '0', nine = '9';

	while (std::cin >> temp)
	{
		if (temp >= zero && temp <= nine)
		{
			stack.push(temp - zero);
		}
		else
		{
			int right = stack.top();
			stack.pop();
			int left = stack.top();
			stack.pop();
			stack.push( operate(right, left, temp) );
		}
	}

	if (!stack.empty())
	{
		std::cout << stack.top() << std::endl;
	}

	return 0;
}