#include <iostream>

long double recursion1(int n)
{
    if (n % 2 == 0) {
        std::cout << n << " ";
		if (n > 1){
			--n;
			recursion1(n);
		} 
		else if ( n <= 0) {
			return 1;
		}
	} else {
		--n;
		recursion1(n);
	}
}

long double recursion2(int n)
{
    if (n % 2 != 0) {
        std::cout << n << " ";
		if (n > 1){
			--n;
			recursion2(n);
		} 
		else if ( n <= 0) {
			return 0;
		}
	} else {
		--n;
		recursion2(n);
	}
}

int main() {
	int n;
	std::cout << "Enter number to write an even and odd: ";
	std::cin >> n;
	
	recursion1(n);
	std::cout << "\n";
	recursion2(n);
	
    return 0;
}