#include <iostream>
#include <string>

int main() {
    int a, age;
    std::string name;
	
    std::cout <<"What is your name?: ";
    std::cin >> name;
    std::cout << "How old are you?: ";
    std::cin >> age;
	
    a = (name == "Armen" && age == 19) ? 1 : 0;
	
    std::cout << "a = " << a << std::endl;
	
    return 0;
}