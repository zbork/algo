#include <iostream>
#include <stdio.h>

template <class T> class stack
{
private:
	T array[100000];
	int len;
public:
	stack() { len = 0; }
	~stack() {}
	bool empty() { return !len; }
	T pop() { return array[--len]; }
	T top() { return array[len-1]; }
	void push(T elt) { array[len++] = elt; }
	int size() { return len; }
};

char getopen(char bracket)
{
	switch (bracket)
	{
		case ')': return '(';
		case ']': return '[';
		case '}': return '{';
		default: return 0;
	}
}

int main ()
{
	freopen("check.in", "r", stdin);
	freopen("check.out", "w", stdout);

	stack<char> brackets;

	char temp;
	char open[4] = "([{";
	char close[4] = ")]}";

	while (std::cin >> temp)
	{
		if (temp == open[0] || temp == open[1] || temp == open[2])
		{
			brackets.push(temp);
		}
		else
		{
			if (brackets.top() != getopen(temp))
			{
				std::cout << "NO\n";
				return 0;
			}
			else
			{
				brackets.pop();
			}
		}
	}

	std::cout << (brackets.empty() ? "YES\n" : "NO\n");

	return 0;
}