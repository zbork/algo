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

int main ()
{
	freopen("erase.in", "r", stdin);
	freopen("erase.out", "w", stdout);

	stack<int> a;

	char temp;
	int count=0;
	int deleted=0;

	while (std::cin >> temp)
	{
		if (temp == '(')
		{
			count++;
		}
		else
		{
			if (count == 0)
			{
				deleted++;
			}
			else
			{
				count--;
			}
		}
	}

	deleted += count;
	std::cout << deleted << std::endl;

	return 0;
}