#include <iostream>
#include <string>

struct Person 
{
    std::string firstName;
    std::string lastName;
    int age;
    bool student;
    std::string gender;
};

void showText();

int main() {
    Person People[13];
    
    People[0].firstName = "Armen";
    People[0].lastName = "Abrahamyan";
    People[0].age = 20;
    People[0].student = true;
    People[0].gender = "male";
    
    People[1].firstName = "Arpine";
    People[1].lastName = "Harutyunyan";
    People[1].age = 23;
    People[1].student = false;
    People[1].gender = "female";
    
    People[2].firstName = "Hrach";
    People[2].lastName = "Gevorgyan";
    People[2].age = 22;
    People[2].student = true;
    People[2].gender = "male";
    
    People[3].firstName = "Lilit";
    People[3].lastName = "Melqumyan";
    People[3].age = 19;
    People[3].student = true;
    People[3].gender = "female";
    
    People[4].firstName = "Artur";
    People[4].lastName = "Gasparyan";
    People[4].age = 22;
    People[4].student = true;
    People[4].gender = "male";
    
    People[5].firstName = "Mariam";
    People[5].lastName = "Karapetyan";
    People[5].age = 21;
    People[5].student = true;
    People[5].gender = "female";
    
    People[6].firstName = "Aleksandr";
    People[6].lastName = "Avagyan";
    People[6].age = 20;
    People[6].student = true;
    People[6].gender = "male";
    
    People[7].firstName = "Nona";
    People[7].lastName = "Musaelyan";
    People[7].age = 19;
    People[7].student = true;
    People[7].gender = "female";
    
    People[8].firstName = "Edgar";
    People[8].lastName = "Grigoryan";
    People[8].age = 17;
    People[8].student = false;
    People[8].gender = "male";
    
    People[9].firstName = "Ani";
    People[9].lastName = "Hakobyan";
    People[9].age = 19;
    People[9].student = true;
    People[9].gender = "female";
    
    People[10].firstName = "Tigran";
    People[10].lastName = "Hovhannisyan";
    People[10].age = 22;
    People[10].student = true;
    People[10].gender = "male";
    
    People[11].firstName = "Nvard";
    People[11].lastName = "Harutyunyan";
    People[11].age = 19;
    People[11].student = true;
    People[11].gender = "female";
    
    People[12].firstName = "Michael";
    People[12].lastName = "Sargsyan";
    People[12].age = 17;
    People[12].student = false;
    People[12].gender = "male";

	showText();
	
	std::cout << "**************************************************\n";
	for(int i = 0; i < 13; ++i) {
		std::cout << "[" << i + 1 << "]: "<< People[i].firstName << "\n";
	}
	std::cout << "**************************************************\n";
	
	std::cout << "name - To obtain full information on one person\n" << "all - To obtain information, about all\n" << "exit - To exit\n";
	std::cout << "**************************************************\n";
	
    std::string name;
    while(true) {
		bool find = true;
		std::cout << "\nWrite NAME: ";
		std::cin >> name;
		
        if(name == "exit") {
            break;
        }
		
		if(name == "all") {
			std::cout << "\n**********************************************************************";
			for (int i = 0; i < 13; i++) {
				std::cout << "\nName: " << People[i].firstName;
				std::cout << " " << People[i].lastName << "  >>  ";
				std::cout << "Age: " << People[i].age << "  >>  ";
				if(People[i].student == true) {
					std::cout << "Student: Yes" << "  >>  ";
				} else {
					std::cout << "Student: No" << "  >>  ";
				}
				std::cout << "Gender: " << People[i].gender;
			}
			std::cout << "\n**********************************************************************\n";
			find = false;
		}
		
		for (int i = 0; i < 13; i++) {
			if (People[i].firstName == name) {
				std::cout << "\n*************************";
				std::cout << "\nFirst Name: " << People[i].firstName << "\n";
				std::cout << "Last Name: " << People[i].lastName << "\n";
				std::cout << "Age: " << People[i].age << "\n";
				if(People[i].student == true) {
					std::cout << "Student: Yes" << "\n";
				} else {
					std::cout << "Student: No" << "\n";
				}
				std::cout << "Gender: " << People[i].gender << "\n";
				std::cout << "*************************\n";
				find = false;
				break;
			}
		}
		if(find) {
			std::cout << "The name " << name <<  " isn't included in the list.\n";
		}
	}
    
    return 0;
}

void showText() {
std::cout << "    _____   _______    _____              ___   \n";
std::cout << "   |_   _| |__   __|  / ____|            |__ \\ \n";
std::cout << "     | |      | |    | |       ______       ) | \n";
std::cout << "     | |      | |    | |      |______|     / /  \n";
std::cout << "    _| |_     | |    | |____              / /_  \n";
std::cout << "   |_____|    |_|     \\_____|            |____|\n";

std::cout << "\n    This is all Students of ITC-Stepanakert-2\n\n";
}