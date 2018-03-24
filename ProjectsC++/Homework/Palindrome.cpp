#include <iostream>
#include <string>

std::string word;

int recurs(int len, int i = 0) {
    if (i < len / 2) {
      if(word[i] != word[len-i-1]) {
  			return false;
  		}
      return recurs(len, i + 1);
  	}
  	 return true;
}

bool check_polindrom(int len) {
    recurs(len);
}

int main() {
	std::cout << "Enter the word to determine the palindrome: ";
	std::cin >> word;
	int len = word.length();

	if(check_polindrom(len)) {
		std::cout << "Word is polindrom.";
	} else {
		std::cout << "Word is not polindrom";
	}
	
	return 0;
}