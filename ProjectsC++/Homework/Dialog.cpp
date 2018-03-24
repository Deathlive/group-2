#include <iostream>
#include <string>

int main () {

    std::string choice;

    std::cout << "Paryor!\n";
    std::cin >> choice;

    if (choice == "barev" || choice == "zdarov" || choice == "paryor" || choice == "hajox") {

        std::cout << "Kyanq@ huncha?\n";
        std::cin >> choice;

        if (choice == "lav") {
            std::cout << "De mishtel lav ini, u kanach chanapar\n";
        } 
		else if (choice == "normal") {

            std::cout << "Xe normal axper, ase bomba\n";
            std::cin >> choice;

            if (choice == "bomba" || choice == "lav" || choice == "asalum") {
                std::cout << "Hte ti maladec\n";
            } else if (choice == "che" || choice == "ozumchum" || choice == "karumchum") {
                std::cout << "Hinchae ptahal ?\n";
                std::cin >> choice;
                
                if (choice == "paski" || choice == "gorchtchi" || choice == "loxlava") {
                    std::cout << "Lav Hajox jamanakchonim.";
                } else {
					std::cout << "De lav tuvs gidum, togda hajox, lav kach";
				}
            }

        } else if (choice == "pis") {
            std::cout << "Hunch pis, min ase hincha ilal ?\n";
            std::cin >> choice;
            
            if (choice == "paski" || choice == "gorchtchi" || choice == "loxlava") {
                std::cout << "Lav Hajox jamanakchonim.";
				
            } else {
				std::cout << "Lav, kyanqt patmumel.";
				std::cin >> choice;
				if ( choice == "patmumchum" || choice == "skach" || choice == "darditkach" || choice == "hinch") {
					std::cout << "Axper Hajox, karelchum shat zuruch anim";
				} else {
					std::cout << "SOS, HELlp... internets anjatvala....";
				}
            }
        }
    } else {
        std::cout << "Axper Hajox togda!";
    }

    return 0;
}
