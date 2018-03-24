#include <iostream>

long int recurs(long int n) {
  if (n <= 0) {
      return n;
  }
  else {
      std::cout << (n % 10);
      return recurs(n / 10);
  }
}

int main()
{
   long int n;
   std::cout << "Write to mirror the number: ";
   std::cin >> n;
   
   recurs(n);
   
   std::cout << "\n";
   
   return 0;
}