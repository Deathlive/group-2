#include <iostream>
#include <string>

int SIZE = 13;
struct Person 
{
    std::string firstName;
    std::string lastName;
    int age;
    bool student;
    std::string gender;
    bool familyStatus;
};

void showText();
void showHelp();
void PrintPerson(Person People[]);

int main() {
    Person People[SIZE] = {
        {"Armen", "Abrahamyan", 20, true, "male", false},
        {"Arpine", "Harutyunyan", 23, false, "female", false},
        {"Hrach", "Gevorgyan", 22, true, "male", false},
        {"Lilit", "Melqumyan", 19, true, "female", false},
        {"Artur", "Gasparyan", 22, true, "male", false},
        {"Ani", "Hakobyan", 19, true, "female", false},
        {"Aleksandr", "Avagyan", 20, true, "female", false},
        {"Nona", "Musaelyan", 19, true, "female", false},
        {"Edgar", "Grigoryan", 17, false, "male", false},
        {"Mariam", "Karapetyan", 21, true, "female", false},
        {"Tigran", "Hovhannisyan", 22, true, "male", false},
        {"Nvard", "Harutyunyan", 19, true, "female", false},
        {"Michael", "Sargsyan", 17, true, "male", false}
    };
    
    showText();
	
    std::cout << "\n*****This is all Students of ITC-Stepanakert-2*****\n";
    for(int i = 0; i < 13; ++i) {
        std::cout << "[" << i + 1 << "]: "<< People[i].firstName << " " << People[i].lastName << "\n";
    }
    
    showHelp();
    
    PrintPerson(People);
    
    return 0;
}

void showText() {
    std::cout << "    _____   _______    _____              ___   \n";
    std::cout << "   |_   _| |__   __|  / ____|            |__ \\ \n";
    std::cout << "     | |      | |    | |       ______       ) | \n";
    std::cout << "     | |      | |    | |      |______|     / /  \n";
    std::cout << "    _| |_     | |    | |____              / /_  \n";
    std::cout << "   |_____|    |_|     \\_____|            |____|\n";
}

void showHelp() {
    std::cout << "**************************************************\n";
    std::cout << "name - To obtain full information on one person\n";
    std::cout << "all - To obtain information, about all\n";
    std::cout << "help - List options\n";
    std::cout << "exit - To exit\n";
    std::cout << "**************************************************\n";
}

void PrintPerson(Person People[]) {
    while(true) {
        std::string name;
        bool find = true;
        
        std::cout << "\nWrite NAME: ";
        std::cin >> name;
        std::cout << "\n";
        
        if(name == "exit") {
            break;
        }
		
        if(name == "help") {
            showHelp();
            find = false;
        }
		
        for (int i = 0; i < SIZE; i++) {
            if (People[i].firstName == name) {
                std::cout << "*************************";
                std::cout << "\nName: ";
                if (People[i].gender == "male") {
                    std::cout << "Mr. ";
                } else if (People[i].gender == "female" && People[i].familyStatus == false) {
                    std::cout << "Miss ";
                } else if (People[i].gender == "female" && People[i].familyStatus == true) {
                    std::cout << "Mrs. ";
                }
                std::cout << People[i].firstName << " " << People[i].lastName << "\n";
                std::cout << "Age: " << People[i].age << "\n";
                if(People[i].student == true) {
                    std::cout << "Student: Yes" << "\n";
                } else {
                    std::cout << "Student: No" << "\n";
                }
                std::cout << "Gender: " << People[i].gender << "\n";
                if(People[i].familyStatus == false) {
                    std::cout << "FamilyStatus: Single" << "\n";
                } else {
                    std::cout << "FamilyStatus: is married" << "\n";
                }
                std::cout << "*************************\n";
                find = false;
                break;
            } else if (name == "all") {
                if(i == 0) {
                    std::cout << "**************************************************\n";
                }

                std::cout << "Name: ";
                if (People[i].gender == "male") {
                    std::cout << "Mr. ";
                } else if (People[i].gender == "female" && People[i].familyStatus == false) {
                    std::cout << "Miss ";
                } else if (People[i].gender == "female" && People[i].familyStatus == true) {
                    std::cout << "Mrs. ";
                }
                std::cout << People[i].firstName << " " << People[i].lastName << "  >>  ";
                std::cout << "Age: " << People[i].age << "  >>  ";
                if(People[i].student == true) {
                    std::cout << "Student: Yes" << "  >>  ";
                } else {
                    std::cout << "Student: No" << "  >>  ";
                }
                std::cout << "Gender: " << People[i].gender << "  >>  ";
                if(People[i].familyStatus == false) {
                    std::cout << "FamilyStatus: Single\n";
                } else {
                    std::cout << "FamilyStatus: is married\n";
                }

                if(i == SIZE - 1) {
                    std::cout << "**************************************************\n";
                }

                find = false;
            } else if (name == "name") {
                if(i == 0) {
                    std::cout << "**************************************************\n";
                }
			    
                std::cout << "[" << i + 1 << "]: "<< People[i].firstName << " " << People[i].lastName << "\n";
                
                if (i == SIZE - 1) {
			        std::cout << "**************************************************\n";
                }
                find = false;
            }
        }
        
        if (find) {
            std::cout << "The name " << name <<  " isn't included in the list.\n";
        }
    }
}