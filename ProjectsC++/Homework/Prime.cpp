#include <iostream>

long int recurs(long int n, long int i = 2) {
	if (n < 2) {
		std::cout << "No Prime Number";
	}
	else if (n == 2) {
		std::cout << "Prime Number";
	}
	else if (n % i == 0) {
		std::cout << "No Prime Number";
	}
	else if (i < n / 2) {
		return recurs(n, i + 1);
	} else {
		std::cout << "Prime Number";
	}
}

int main()
{
   long int n;
   std::cout << "Write a number to know whether it is prime or not: ";
   std::cin >> n;
   
   recurs(n);
   
   std::cout << "\n";
   
   return 0;
}