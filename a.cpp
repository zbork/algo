#include <iostream>
#include <stdio.h>

int main () {
	freopen("spaces.in", "r", stdin);
	freopen("spaces.out", "w", stdout);

	char buf[200];

while (std::cin >> buf)
	std::cout	 << buf << ' ';
std::cout << std::endl;
	
	return 0;
}