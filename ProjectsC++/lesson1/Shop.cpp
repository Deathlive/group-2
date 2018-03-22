#include <iostream>

int main() {
	float snickers = 1.5; 
	float hamburger = 2.6; 
	float cola = 1.2;
	float panda = 6;
	float roshen = 13; 
	float wather = 3.3; 
	float bread = 0.3; 
	float juise = 10; 
	float tablecloth = 2.7;
	
	double sum = 2 * snickers + 2 * hamburger + 2 * cola + 0.5 * panda + 0.2 * roshen + 4 * wather + 4 * bread + 2 * juise + 3.5 * tablecloth;
	
	std::cout << "Your sum = " << sum << "$" << std::endl;

	return 0;
} 
