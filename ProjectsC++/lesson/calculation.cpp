#include <iostream>
#include <string>

void plus(int num1, int num2) {
	std::cout << num1 + num2 << std::endl;
}

void minus(int num1, int num2) {
	std::cout << num1 - num2 << std::endl;
}   

void divide(int num1, int num2) {
	std::cout << num1 / num2 << std::endl;
}

void mul(int num1, int num2) {
	std::cout << num1 * num2 << std::endl;
}

int main() {
	std::string c;
	int a, b;
	std::cout << "Enter first number " << std::endl;
	std::cin >> a;
	std::cout << "Enter second number " << std::endl;
	std::cin >> b;
	std::cout << "Action" << std::endl;
	std::cin >> c;
	
		if (c == "+") {
			plus(a, b);
		} else if (c == "-") {
			minus(a, b);
		} else if (c == "*") {
			mul(a, b);
		} else if (c == "/") {
			divide(a, b);
		} else { 
			std::cout << "Error" << std::endl;
	}
	return 0;
}
