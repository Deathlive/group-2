#include <iostream>

int main() {
	std::cout << "Hello world!!!" << std::endl;
	int a = 5;
	int b = 7;
	a = a + b;
	b = a - b;
	a = a - b;
	
	std::cout << "a = " << a << ' ' << "b = " << b << std::endl;
	
	return 0;
}
