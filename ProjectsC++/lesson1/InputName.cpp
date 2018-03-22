#include <iostream>
#include <string>
using namespace std;

int main() {  	
	string your_name, pair_name;
	int your_age, pair_age;
	
	std::cout << "Hello!" << std::endl;
	std::cout << "What is your name?: ";
	std::cin >> your_name;
    std::cout << "How old are you?: ";
	std::cin >>your_age;
    std::cout << "Enough told about you!" << std::endl;
    std::cout << "What is name of your pair?: ";
	std::cin >> pair_name;
    std::cout << "How old is your pair?: ";
	std::cin >> pair_age;
	
	if (your_age > pair_age) {
		std::cout << your_name << " You are older, than " << pair_name << std::endl;
	}
	else if (your_age < pair_age) { 
        std::cout << pair_name << " You are older, than " << your_name << std::endl;
	}
	else if (your_age == pair_age) {
		std::cout << your_name << " is the same age as " << pair_name << std::endl;
	} 
	
	return 0;
}
