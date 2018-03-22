#include <iostream>
#include <string>

int main() {
    int a;
	int my_age, pair_age;
    std::string my_name, pair_name;
	
    std::cout << "What is your name?:";
    std::cin >> my_name;
    std::cout << "How old are you?: ";
    std::cin >> my_age;
    std::cout << "What is your pair name?:";
    std::cin >> pair_name;
    std::cout << "How old are  your pair?: ";
    std::cin >> pair_age;
	
	a = ((myname == "Armen" && myage == 19)||(pairname == "Arpine" && pairage == 23)) ? 1 : 0;
	
	std::cout << "a = " << a << std::endl;
	
    return 0;
}

