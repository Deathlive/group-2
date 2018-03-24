#include <iostream>
#include <string>
#include <stdlib.h>

//Creating Variables
int compRand = 1 + rand() % 100;
std::string singCoop;
std::string userChoice;
std::string compChoice;
std::string userNm1, userNm2;

//Output of Result
void resultOutput(std::string user, std::string userChoice) {
    std::cout << user << " choice: " << userChoice << "\n";
}

//When choose Coop Play, the game begins, the player versus the player
void uservsuser() {
    std::cout << "User1 What is your name?\n";
    std::cin >> userNm1;
    std::cout << "User2 What is your name?\n";
    std::cin >> userNm2;
    std::cout << "\n" << userNm1 << " Write Rock,Paper or Scissor?\n";
    std::cin >> userChoice;
    std::cout << userNm2 << " Write Rock,Paper or Scissor?\n";
    std::cin >> compChoice;
  
    resultOutput(userNm1, userChoice);
    resultOutput(userNm2, compChoice);
}

//When choose Single Play, the game begins, the player versus the computer
void uservspc() {
    std::cout << "User1 What is your name?\n";
    std::cin >> userNm1;
    std::cout << "\n" << userNm1 << " Write Rock,Paper or Scissor?\n";
    std::cin >> userChoice;
  
	if (compRand <= 35) {
      compChoice = "Rock";
    } else if (compRand <= 65 && compRand > 35) {
      compChoice = "Paper";
    } else if (compRand >= 65) {
      compChoice = "Scissor";
    }
    
	resultOutput(userNm1, userChoice);
	std::cout << "Computer chose: " << compChoice << "\n";
}

//Here, a comparison is made of who will win, based on the already selected values
void compare(std::string choice1, std::string choice2) {   
	if(choice1 == choice2) {
		std::cout << "Draw!\n";
	} else if(choice1 == "Rock") {
		if(choice2 == "Scissor") {
			std::cout << "Rock Win!\n"; 
		} else {
			std::cout << "Paper Win!\n";   
			}
	} else if(choice1 == "Paper") {
		if(choice2 == "Rock") {
			std::cout << "Paper Win!\n";
		} else {
			std::cout << "Scissor Win!\n";   
			}
	} else if(choice1 == "Scissor") {
		if(choice2 == "Rock") {
			std::cout << "Rock Win!\n";   
		} else {
			std::cout << "Scissor Win!\n";   
			}
	}
}

int main() {
    
    std::cout << "Single or Coop Gameplay ?\n";
    std::cin >> singCoop;
    
    if (singCoop == "Single") {
      uservspc();
    } else if (singCoop == "Coop") {
      uservsuser();
    } else {
      std::cout << "Print the correct value\n";
    }
	  
	compare(userChoice, compChoice); //Here we send a value and perform a comparison.
	  
    return 0;
}
