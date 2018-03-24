#include <iostream>

int myPow(int n, int k) {
    if (k <= 0) return 1;
    
    return n * myPow(n, --k);
}

int main()
{
    int n, k;
    std::cout << "Enter n and k:\n";
    std::cin >> n >> k;

    std::cout << myPow(n, k) << "\n";

    return 0;
}