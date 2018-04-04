#include <iostream>

void func1(int n);
void func2(int n);
void func3(int n);
void func4(int n);
void func5(int n);
void func6(int n);

int main() {
    int n, choose;
    std::cout << "Write Length: ";
    std::cin >> n;
	
    std::cout << "0 > ALL\n";
	
    std::cout << "1  ^"    << "  2 ^^^^^" << "  3 ^  "     << "  4  ^^^^^" << "  5     ^" << "  6  ^^^^^" << "\n";
    std::cout << "  ^^^"   << "     ^^^"  << "    ^^^  "   << "     ^^^"   << "      ^^^" << "       ^^^" << "\n";
    std::cout << " ^^^^^"  << "      ^"   << "    ^^^^^  " << "     ^"     << "    ^^^^^" << "         ^" << "\n";
	
    std::cin >> choose;
	
    switch (choose) {
      case 1:
        std::cout << "\n";
        func1(n);
        break;
      case 2:
        std::cout << "\n";
        func2(n);
        break;
      case 3:
        std::cout << "\n";
        func3(n);
        break;
      case 4:
        std::cout << "\n";
        func4(n);
        break;
      case 5:
        std::cout << "\n";
        func5(n);
        break;
      case 6:
        std::cout << "\n";
        func6(n);
        break;
      default:
        std::cout << "\n";
        func1(n);
        std::cout << "\n";
        func2(n);
        std::cout << "\n";
        func3(n);
        std::cout << "\n";
        func4(n);
        std::cout << "\n";
        func5(n);
        std::cout << "\n";
        func6(n);
        std::cout << "\n";
        break;
    }
	
    std::cout << "\n";
    
    return 0;
}

void func1(int n) {
	for (int i = 1; i <= n; i++) 
	{
		for (int a = i; a <= n; a++) {
			std::cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
			std::cout << "^";
        }
        std::cout << "\n";
	}
}

void func2(int n) {
	for (int i = n; i >= 0; i--) 
    { 
        for (int a = 0; a <= n - i; a++) {
			std::cout << " "; 
        }
        for (int k = 1; k <= i * 2 - 1; k++) {
			std::cout << "^"; 
        }
        std::cout << "\n";
    }
}

void func3(int n) {
    for (int i = 1; i <= n; i++)
	{
        for (int k = 1; k <= 2 * i - 1; k++)
        {
			std::cout << "^";
        }
        std::cout << "\n"; 
    }
}

void func4(int n) {
    for(int i = n; i >= 1; i--)
    {
        for(int k = 1; k <= 2 * i - 1; k++)
        {
          std::cout << "^";
        }
        std::cout << "\n"; 
    }
}

void func5(int n) {
	for (int i = 1; i <= n; i++)
    {
        for (int a = i; a <= n; a++) {
          std::cout << " ";
        }
        for (int k = 1; k <= i; k++) {
          std::cout << "^";
        }
        std::cout << "\n"; 
    }
}

void func6(int n) {
	for (int i = n; i >= 0; i--) 
    { 
        for (int a = 0; a <= n - i; a++) {
          std::cout << " "; 
        }
        for (int k = 1; k <= i; k++) {
          std::cout << "^"; 
        }
          std::cout << "\n";
    }
}