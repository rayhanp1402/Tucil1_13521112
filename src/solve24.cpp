# include "solve24.h"

std::string doubleToString(double var){
    std::stringstream stream;
    stream << std::fixed << std::setprecision(0) << var;

    return stream.str();
}

double convertInput(std::string inputVar){
    if(inputVar == "1" || inputVar == "A" || inputVar == "a") return 1;
    if(inputVar == "2") return 2;
    if(inputVar == "3") return 3;
    if(inputVar == "4") return 4;
    if(inputVar == "5") return 5;
    if(inputVar == "6") return 6;
    if(inputVar == "7") return 7;
    if(inputVar == "8") return 8;
    if(inputVar == "9") return 9;
    if(inputVar == "10") return 10;
    if(inputVar == "11" || inputVar == "J" || inputVar == "j") return 11;
    if(inputVar == "12" || inputVar == "Q" || inputVar == "q") return 12;
    if(inputVar == "13" || inputVar == "K" || inputVar == "k") return 13;
}

double operate(double operandA, double operandB, char op){
    switch (op){
        case '+':
            return operandA + operandB;
        case '-':
            return operandA - operandB;
        case '*':
            return operandA * operandB;
        case '/':
            return operandA / operandB;
        default:
            break;
    }
}

std::vector< std::string > solve24(double a, double b, double c, double d){
    // Main algorithm of finding the solutions
    std::vector< std::string > solutions;
    std::vector< std::vector<double> > cardsPermutations;
    std::vector< std::vector<char> > operatorsPermutations = operators();

    cardsPermutations = cards(a, b, c, d);

    for(int i = 0; i < 24; i++){     // For each row in the cards' 2D Vector, traverse through all of the possible operator permutations stored in another 2D Vector
        for(int j = 0; j < 64; j++){
            if(cardsPermutations[i][0] != 0){
                // Case 1: (a operates b) operates (c operates d)
                if(operate(operate(cardsPermutations[i][0], cardsPermutations[i][1], operatorsPermutations[j][0]), operate(cardsPermutations[i][2], cardsPermutations[i][3], operatorsPermutations[j][2]), operatorsPermutations[j][1]) == 24){
                    solutions.push_back("(" + doubleToString(cardsPermutations[i][0]) + " " + std::string(1, operatorsPermutations[j][0]) + " " + doubleToString(cardsPermutations[i][1]) + ") " + std::string(1, operatorsPermutations[j][1]) + " (" + doubleToString(cardsPermutations[i][2]) + " " + std::string(1, operatorsPermutations[j][2]) + " " + doubleToString(cardsPermutations[i][3]) + ")");
                }
                // Case 2: ((a operates b) operates c) operates d
                if(operate(operate(operate(cardsPermutations[i][0], cardsPermutations[i][1], operatorsPermutations[j][0]), cardsPermutations[i][2], operatorsPermutations[j][1]), cardsPermutations[i][3], operatorsPermutations[j][2]) == 24){
                    solutions.push_back("((" + doubleToString(cardsPermutations[i][0]) + " " + std::string(1, operatorsPermutations[j][0]) + " " + doubleToString(cardsPermutations[i][1]) + ") " + std::string(1, operatorsPermutations[j][1]) + " " + doubleToString(cardsPermutations[i][2]) + ") " + std::string(1, operatorsPermutations[j][2]) + " " + doubleToString(cardsPermutations[i][3]));
                }
                // Case 3: (a operates (b operates c)) operates d
                if(operate(operate(cardsPermutations[i][0], operate(cardsPermutations[i][1], cardsPermutations[i][2], operatorsPermutations[j][1]), operatorsPermutations[j][0]), cardsPermutations[i][3], operatorsPermutations[j][2]) == 24){
                    solutions.push_back("(" + doubleToString(cardsPermutations[i][0]) + " " + std::string(1, operatorsPermutations[j][0]) + " (" + doubleToString(cardsPermutations[i][1]) + " " + std::string(1, operatorsPermutations[j][1]) + " " + doubleToString(cardsPermutations[i][2]) + ")) " + std::string(1, operatorsPermutations[j][2]) + " " + doubleToString(cardsPermutations[i][3]));          
                }
                // Case 4: a operates ((b operates c) operates d)
                if(operate(cardsPermutations[i][0], operate(operate(cardsPermutations[i][1], cardsPermutations[i][2], operatorsPermutations[j][1]), cardsPermutations[i][3], operatorsPermutations[j][2]), operatorsPermutations[j][0]) == 24){
                    solutions.push_back(doubleToString(cardsPermutations[i][0]) + " " + std::string(1, operatorsPermutations[j][0]) + " ((" + doubleToString(cardsPermutations[i][1]) + " " + std::string(1, operatorsPermutations[j][1]) + " " + doubleToString(cardsPermutations[i][2]) + ") " + std::string(1, operatorsPermutations[j][2]) + " " + doubleToString(cardsPermutations[i][3]) + ")");                    
                }
                // Case 5: a operates (b operates(c operates d))
                if(operate(cardsPermutations[i][0], operate(cardsPermutations[i][1], operate(cardsPermutations[i][2], cardsPermutations[i][3], operatorsPermutations[j][2]), operatorsPermutations[j][1]), operatorsPermutations[j][0]) == 24){
                    solutions.push_back(doubleToString(cardsPermutations[i][0]) + " " + std::string(1, operatorsPermutations[j][0]) + " (" + doubleToString(cardsPermutations[i][1]) + " " + std::string(1, operatorsPermutations[j][1]) + " (" + doubleToString(cardsPermutations[i][2]) + " " + std::string(1, operatorsPermutations[j][2]) + " " + doubleToString(cardsPermutations[i][3]) + "))");
                }
            }
        }
    }
    return solutions;
}