# include <sys/time.h>
#include <ctime>
#include <cstdlib>
# include "solve24.h"

int main(){
    bool play = true, valid1, valid2;
    double a, b, c, d;
    std::string inputA, inputB, inputC, inputD, inputHandler;
    std::string choice;
                                                                                   
    std::cout << ".___  ___.     ___      __  ___  _______       __ .___________.\n";
    std::cout << "|   \\/   |    /   \\    |  |/  / |   ____|     |  ||           |\n";
    std::cout << "|  \\  /  |   /  ^  \\   |  '  /  |  |__        |  |`---|  |----`\n";
    std::cout << "|  |\\/|  |  /  /_\\  \\  |    <   |   __|       |  |    |  |     \n";
    std::cout << "|  |  |  | /  _____  \\ |  .  \\  |  |____      |  |    |  |     \n";
    std::cout << "|__|  |__|/__/     \\__\\|__|\\__\\ |_______|     |__|    |__|     \n";
    std::cout << "\n";        

    std::cout << "                        ___      _  _    \n";
    std::cout << "                       |__ \\    | || |   \n";
    std::cout << "                          ) |   | || |_  \n";
    std::cout << "                         / /    |__   _| \n";
    std::cout << "                        / /_       | |   \n";
    std::cout << "                       |____|      |_|   \n";
    std::cout << "\n";                                 

    std::cout << "     _______.  ______   __      ____    ____ _______ .______      \n";
    std::cout << "    /       | /  __  \\ |  |     \\   \\  /   /|   ____||   _  \\     \n";
    std::cout << "   |   (----`|  |  |  ||  |      \\   \\/   / |  |__   |  |_)  |    \n";
    std::cout << "    \\   \\    |  |  |  ||  |       \\      /  |   __|  |      /     \n";
    std::cout << ".----)   |   |  `--'  ||  `----.   \\    /   |  |____ |  |\\  \\----.\n";
    std::cout << "|_______/     \\______/ |_______|    \\__/    |_______|| _| `._____|\n";
    std::cout << "\n\n";                        

    while(play == true){       
        valid1 = false;
        while(valid1 == false){                           
            std::cout << "Main Menu\n1. Solve\n2. Exit\n";
            std::cout << "Enter the no. : ";
            std::cin >> choice;

            if(choice == "1" || choice == "1."){
                valid1 = true;
            }
            else if(choice == "2" || choice == "2."){
                std::cout << "Exiting . . .\n";
                valid1 = true;
                play = false;
            }
            else std::cout << "\nInvalid input, try again";
        } 

        if(play == false){
            break;
        }         

        valid1 = false;
        while(valid1 == false){
            std::cout << "\nHow would you like to input the cards?\n1. Manually input the cards\n2. Randomize the cards\n";
            std::cout << "Enter the no. : ";
            std::cin >> choice;

            if(choice == "1" || choice == "1."){
                valid2 = false;
                while(valid2 == false){
                    std::cout << "\nCard types (\"A\" or \"1\", \"2\", \"3\", \"4\", \"5\" ,\"6\" ,\"7\" ,\"8\" ,\"9\" ,\"10\" ,\"J\" or \"11\" ,\"Q\" or \"12\" ,\"K\" or \"13\")\n";
                    std::cout << "Type in the four cards : ";
                    std::cin >> inputA >> inputB >> inputC >> inputD;

                    if(inputA != "1" && inputA != "A" && inputA != "a" && inputA != "2" && inputA != "3" && inputA != "4" && inputA != "5" && inputA != "6" && inputA != "7" && inputA != "8" && inputA != "9" && inputA != "10" && inputA != "11" && inputA != "J" && inputA != "j" && inputA != "12" && inputA != "Q" && inputA != "q" && inputA != "13" && inputA != "K" && inputA != "k"){
                        std::cout << "\nInvalid input, try again";
                    }
                    else if(inputB != "1" && inputB != "A" && inputB != "a" && inputB != "2" && inputB != "3" && inputB != "4" && inputB != "5" && inputB != "6" && inputB != "7" && inputB != "8" && inputB != "9" && inputB != "10" && inputB != "11" && inputB != "J" && inputB != "j" && inputB != "12" && inputB != "Q" && inputB != "q" && inputB != "13" && inputB != "K" && inputB != "k"){
                        std::cout << "\nInvalid input, try again";
                    }
                    else if(inputC != "1" && inputC != "A" && inputC != "a" && inputC != "2" && inputC != "3" && inputC != "4" && inputC != "5" && inputC != "6" && inputC != "7" && inputC != "8" && inputC != "9" && inputC != "10" && inputC != "11" && inputC != "J" && inputC != "j" && inputC != "12" && inputC != "Q" && inputC != "q" && inputC != "13" && inputC != "K" && inputC != "k"){
                        std::cout << "\nInvalid input, try again";
                    }
                    else if(inputD != "1" && inputD != "A" && inputD != "a" && inputD != "2" && inputD != "3" && inputD != "4" && inputD != "5" && inputD != "6" && inputD != "7" && inputD != "8" && inputD != "9" && inputD != "10" && inputD != "11" && inputD != "J" && inputD != "j" && inputD != "12" && inputD != "Q" && inputD != "q" && inputD != "13" && inputD != "K" && inputD != "k"){
                        std::cout << "\nInvalid input, try again";
                    }
                    else valid2 = true;
                }
                
                a = convertInput(inputA);
                b = convertInput(inputB);
                c = convertInput(inputC);
                d = convertInput(inputD);
                valid1 = true;
            }
            else if(choice == "2" || choice == "2."){
                // Randomize the cards
                srand(time(0));
                a = (rand() % 13) + 1;
                b = (rand() % 13) + 1;
                c = (rand() % 13) + 1;
                d = (rand() % 13) + 1;

                inputA = doubleToString(a);
                inputB = doubleToString(b);
                inputC = doubleToString(c);
                inputD = doubleToString(d);

                std::cout << "\nCards : " << inputA << ' ' << inputB << ' ' << inputC << ' ' << inputD << '\n';
                valid1 = true;
            }
            else{
                std::cout << "\nInvalid input, try again";
            }
        }

        // Start measuring time
        struct timeval begin, end;
        gettimeofday(&begin, 0);

        // Solve
        std::vector< std::string > solutions = solve24(a, b, c, d);

        // Outputs the solutions
        if(solutions.size() == 0) std::cout << "\nNo solutions found\n";
        else std::cout << '\n' << solutions.size() << " solutions found :\n";

        for(int i = 0; i < solutions.size(); i++){
            std::cout << solutions[i] << '\n';
        }

        // Stop measuring time and calculate the elapsed time
        gettimeofday(&end, 0);
        long seconds = end.tv_sec - begin.tv_sec;
        long microseconds = end.tv_usec - begin.tv_usec;
        double elapsed = seconds + microseconds*1e-6;

        // Outputs the execution time
        std::cout << "\nExecution Time : " << elapsed << " seconds\n\n";

        // Save solutions to a file option
        valid1 = false;
        while(valid1 == false){
            std::cout << "Do you want to save the answer? (Y/N) ";
            std:: cin >> choice;

            if(choice == "Y" || choice == "y"){
                std::string fileName;
                std::cout << "Type the file name : ";
                std::cin >> fileName;

                std::cout << "Saving . . .\n";

                std::ofstream solutionFile;
                solutionFile.open("../test/" + fileName);
                solutionFile << "Cards : " << inputA << " " << inputB << " " << inputC << " " <<  inputD << "\n";

                if(solutions.size() == 0) solutionFile << "\nNo solutions found\n";
                else solutionFile << '\n' << solutions.size() << " solutions found :\n";

                for(int i = 0; i < solutions.size(); i++){
                    solutionFile << solutions[i] << '\n';
                }

                solutionFile << "\nExecution Time : " << elapsed << " seconds";
                solutionFile.close();

                std::cout << "Done\n\n";
                valid1 = true;
            }
            else if(choice == "N" || choice == "n"){
                valid1 = true;
            }
            else{
                std::cout << "\nInvalid input, try again\n";
            }
        }
    }

    return 0;
}