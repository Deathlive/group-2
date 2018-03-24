#include <iostream>
#include <string>

long double fact(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    else 
        return n * fact(n - 1);
}

long double doubleFact(int n)
{
	if (n < 0)
        return 0;
	if (n == 0)
        return 1;
	if (n < 3)
		return n;
	else
		return n * doubleFact(n - 2);
}

int main() {
	int n;
	std::string choice;
	std::cout << "Enter f1 or f2\n";
	std::cin >> choice;
	
	if (choice == "f1") {
		std::cout << "Enter the number to calculate the factorial: ";
		std::cin >> n;
		std::cout << "factorial for the number of " << n << " = " << fact(n) << "\n";
	} 
	else if (choice == "f2") {
		std::cout << "Enter the number to calculate the double factorial: ";
		std::cin >> n;
		std::cout << "double factorial for the number of " << n << " = " << doubleFact(n) << "\n";
	} else {
		std::cout << "Enter the correct character\n";
	}
	
    return 0;
}