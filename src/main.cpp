# include <iostream>
# include <vector>
#include <sys/time.h>

void displayCardsPermutations(std::vector< std::vector<double> > cardsPermutations){
    unsigned count = 0;

    for(int i = 0; i < 24; i++){
        if(cardsPermutations[i][0] == 0) continue;
        else{
            count++;
            std::cout << count << ". ";
            for(int j = 0; j < 4; j++){
                if(j == 3) std::cout << cardsPermutations[i][j] << '\n';
                else std::cout << cardsPermutations[i][j] << ' ';
            }
        }
    }
}

void displayOperatorsPermutations(std::vector< std::vector<char> > operatorsPermutations){
    unsigned count = 0;

    for(int i = 0; i < 64; i++){
        count++;
        std::cout << count << ". ";
        for(int j = 0; j < 3; j++){
            if(j == 2) std::cout << operatorsPermutations[i][j] << '\n';
            else std::cout << operatorsPermutations[i][j] << ' ';
        }
    }
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

void permuteOperators(std::vector< std::vector<char> > &operatorsPermutations, unsigned operatorVariant, unsigned startRow){
    // Additional procedure to permute the operators if there are more than one operator variant (e.g. + and - are two different operators, hence two operator variant)
    if(operatorVariant == 2){
        // Second permutation
        operatorsPermutations[startRow][0] = operatorsPermutations[startRow-1][0];
        operatorsPermutations[startRow][1] = operatorsPermutations[startRow-1][2];
        operatorsPermutations[startRow][2] = operatorsPermutations[startRow-1][1];

        // Third permutation
        operatorsPermutations[startRow+1][0] = operatorsPermutations[startRow-1][2];
        operatorsPermutations[startRow+1][1] = operatorsPermutations[startRow-1][0];
        operatorsPermutations[startRow+1][2] = operatorsPermutations[startRow-1][1];
    }
    else if(operatorVariant == 3){
        // Second permutation
        operatorsPermutations[startRow][0] = operatorsPermutations[startRow-1][0];
        operatorsPermutations[startRow][1] = operatorsPermutations[startRow-1][2];
        operatorsPermutations[startRow][2] = operatorsPermutations[startRow-1][1];

        // Third permutation
        operatorsPermutations[startRow+1][0] = operatorsPermutations[startRow-1][1];
        operatorsPermutations[startRow+1][1] = operatorsPermutations[startRow-1][0];
        operatorsPermutations[startRow+1][2] = operatorsPermutations[startRow-1][2];

        // Fourth permutation
        operatorsPermutations[startRow+2][0] = operatorsPermutations[startRow-1][2];
        operatorsPermutations[startRow+2][1] = operatorsPermutations[startRow-1][0];
        operatorsPermutations[startRow+2][2] = operatorsPermutations[startRow-1][1];

        // Fifth permutation
        operatorsPermutations[startRow+3][0] = operatorsPermutations[startRow-1][1];
        operatorsPermutations[startRow+3][1] = operatorsPermutations[startRow-1][2];
        operatorsPermutations[startRow+3][2] = operatorsPermutations[startRow-1][0];

        // Sixth permutation
        operatorsPermutations[startRow+4][0] = operatorsPermutations[startRow-1][2];
        operatorsPermutations[startRow+4][1] = operatorsPermutations[startRow-1][1];
        operatorsPermutations[startRow+4][2] = operatorsPermutations[startRow-1][0];
    }
    else{
        return;
    }
}

std::vector< std::vector<char> > operators(){
    // Store all permutations of operators +, -, *, and / in a 2D Vector
    std::vector< std::vector<char> > operatorsPermutations;
    operatorsPermutations.resize(64, std::vector<char>(3, 0));

    operatorsPermutations[0][0] = '+';
    operatorsPermutations[0][1] = '+';
    operatorsPermutations[0][2] = '+';

    operatorsPermutations[1][0] = '+';
    operatorsPermutations[1][1] = '+';
    operatorsPermutations[1][2] = '-';

    permuteOperators(operatorsPermutations, 2, 2);

    operatorsPermutations[4][0] = '+';
    operatorsPermutations[4][1] = '+';
    operatorsPermutations[4][2] = '*';

    permuteOperators(operatorsPermutations, 2, 5);

    operatorsPermutations[7][0] = '+';
    operatorsPermutations[7][1] = '+';
    operatorsPermutations[7][2] = '/';

    permuteOperators(operatorsPermutations, 2, 8);

    operatorsPermutations[10][0] = '-';
    operatorsPermutations[10][1] = '-';
    operatorsPermutations[10][2] = '-';

    operatorsPermutations[11][0] = '-';
    operatorsPermutations[11][1] = '-';
    operatorsPermutations[11][2] = '+';

    permuteOperators(operatorsPermutations, 2, 12);

    operatorsPermutations[14][0] = '-';
    operatorsPermutations[14][1] = '-';
    operatorsPermutations[14][2] = '*';

    permuteOperators(operatorsPermutations, 2, 15);

    operatorsPermutations[17][0] = '-';
    operatorsPermutations[17][1] = '-';
    operatorsPermutations[17][2] = '/';

    permuteOperators(operatorsPermutations, 2, 18);

    operatorsPermutations[20][0] = '*';
    operatorsPermutations[20][1] = '*';
    operatorsPermutations[20][2] = '*';

    operatorsPermutations[21][0] = '*';
    operatorsPermutations[21][1] = '*';
    operatorsPermutations[21][2] = '+';

    permuteOperators(operatorsPermutations, 2, 22);

    operatorsPermutations[24][0] = '*';
    operatorsPermutations[24][1] = '*';
    operatorsPermutations[24][2] = '-';

    permuteOperators(operatorsPermutations, 2, 25);

    operatorsPermutations[27][0] = '*';
    operatorsPermutations[27][1] = '*';
    operatorsPermutations[27][2] = '/';

    permuteOperators(operatorsPermutations, 2, 28);

    operatorsPermutations[30][0] = '/';
    operatorsPermutations[30][1] = '/';
    operatorsPermutations[30][2] = '/';

    operatorsPermutations[31][0] = '/';
    operatorsPermutations[31][1] = '/';
    operatorsPermutations[31][2] = '+';

    permuteOperators(operatorsPermutations, 2, 32);

    operatorsPermutations[34][0] = '/';
    operatorsPermutations[34][1] = '/';
    operatorsPermutations[34][2] = '-';

    permuteOperators(operatorsPermutations, 2, 35);

    operatorsPermutations[37][0] = '/';
    operatorsPermutations[37][1] = '/';
    operatorsPermutations[37][2] = '*';

    permuteOperators(operatorsPermutations, 2, 38);

    operatorsPermutations[40][0] = '+';
    operatorsPermutations[40][1] = '-';
    operatorsPermutations[40][2] = '*';

    permuteOperators(operatorsPermutations, 3, 41);

    operatorsPermutations[46][0] = '+';
    operatorsPermutations[46][1] = '-';
    operatorsPermutations[46][2] = '/';

    permuteOperators(operatorsPermutations, 3, 47);

    operatorsPermutations[52][0] = '-';
    operatorsPermutations[52][1] = '*';
    operatorsPermutations[52][2] = '/';

    permuteOperators(operatorsPermutations, 3, 53);

    operatorsPermutations[58][0] = '+';
    operatorsPermutations[58][1] = '*';
    operatorsPermutations[58][2] = '/';

    permuteOperators(operatorsPermutations, 3, 59);

    return operatorsPermutations;
}

std::vector< std::vector<double> > cards(int a, int b, int c, int d){
    // Store all permutations of the four cards in a 2D Vector
    std::vector< std::vector<double> > cardsPermutations;
    cardsPermutations.resize(24, std::vector<double>(4, 0));

    cardsPermutations[0][0] = a;
    cardsPermutations[0][1] = b;
    cardsPermutations[0][2] = c;
    cardsPermutations[0][3] = d;

    cardsPermutations[1][0] = a;
    cardsPermutations[1][1] = b;
    cardsPermutations[1][2] = d;
    cardsPermutations[1][3] = c;

    cardsPermutations[2][0] = a;
    cardsPermutations[2][1] = c;
    cardsPermutations[2][2] = b;
    cardsPermutations[2][3] = d;

    cardsPermutations[3][0] = a;
    cardsPermutations[3][1] = d;
    cardsPermutations[3][2] = b;
    cardsPermutations[3][3] = c;

    cardsPermutations[4][0] = a;
    cardsPermutations[4][1] = c;
    cardsPermutations[4][2] = d;
    cardsPermutations[4][3] = b;

    cardsPermutations[5][0] = a;
    cardsPermutations[5][1] = d;
    cardsPermutations[5][2] = c;
    cardsPermutations[5][3] = b;

    cardsPermutations[6][0] = b;
    cardsPermutations[6][1] = a;
    cardsPermutations[6][2] = c;
    cardsPermutations[6][3] = d;

    cardsPermutations[7][0] = b;
    cardsPermutations[7][1] = a;
    cardsPermutations[7][2] = d;
    cardsPermutations[7][3] = c;

    cardsPermutations[8][0] = c;
    cardsPermutations[8][1] = a;
    cardsPermutations[8][2] = b;
    cardsPermutations[8][3] = d;

    cardsPermutations[9][0] = d;
    cardsPermutations[9][1] = a;
    cardsPermutations[9][2] = b;
    cardsPermutations[9][3] = c;

    cardsPermutations[10][0] = c;
    cardsPermutations[10][1] = a;
    cardsPermutations[10][2] = d;
    cardsPermutations[10][3] = b;

    cardsPermutations[11][0] = d;
    cardsPermutations[11][1] = a;
    cardsPermutations[11][2] = c;
    cardsPermutations[11][3] = b;

    cardsPermutations[12][0] = b;
    cardsPermutations[12][1] = c;
    cardsPermutations[12][2] = a;
    cardsPermutations[12][3] = d;

    cardsPermutations[13][0] = b;
    cardsPermutations[13][1] = d;
    cardsPermutations[13][2] = a;
    cardsPermutations[13][3] = c;

    cardsPermutations[14][0] = c;
    cardsPermutations[14][1] = b;
    cardsPermutations[14][2] = a;
    cardsPermutations[14][3] = d;

    cardsPermutations[15][0] = d;
    cardsPermutations[15][1] = b;
    cardsPermutations[15][2] = a;
    cardsPermutations[15][3] = c;

    cardsPermutations[16][0] = c;
    cardsPermutations[16][1] = d;
    cardsPermutations[16][2] = a;
    cardsPermutations[16][3] = b;

    cardsPermutations[17][0] = d;
    cardsPermutations[17][1] = c;
    cardsPermutations[17][2] = a;
    cardsPermutations[17][3] = b;

    cardsPermutations[18][0] = b;
    cardsPermutations[18][1] = c;
    cardsPermutations[18][2] = d;
    cardsPermutations[18][3] = a;

    cardsPermutations[19][0] = b;
    cardsPermutations[19][1] = d;
    cardsPermutations[19][2] = c;
    cardsPermutations[19][3] = a;

    cardsPermutations[20][0] = c;
    cardsPermutations[20][1] = b;
    cardsPermutations[20][2] = d;
    cardsPermutations[20][3] = a;

    cardsPermutations[21][0] = d;
    cardsPermutations[21][1] = b;
    cardsPermutations[21][2] = c;
    cardsPermutations[21][3] = a;

    cardsPermutations[22][0] = c;
    cardsPermutations[22][1] = d;
    cardsPermutations[22][2] = b;
    cardsPermutations[22][3] = a;

    cardsPermutations[23][0] = d;
    cardsPermutations[23][1] = c;
    cardsPermutations[23][2] = b;
    cardsPermutations[23][3] = a;

    // Disable duplicate permutation
    unsigned isSameElmt; // Boolean value

    for(int i = 0; i < 24; i++){
        for(int j = 0; j < 24; j++){
            isSameElmt = 0;
            if(i != j){
                for(int k = 0; k < 4; k++){
                    if(cardsPermutations[i][k] == cardsPermutations[j][k]) isSameElmt = 1;
                    else{
                        isSameElmt = 0;
                        break;
                    }
                }
                if(isSameElmt == 1) cardsPermutations[j][0] = 0; // Make the element of the first column in a duplicate row 0 to disable the row
            }
        }
    }

    return cardsPermutations;
}

void solve24(){
    // Main algorithm of finding the solutions
    unsigned solutionCount = 0;
    double a, b, c, d; 
    std::vector< std::vector<double> > cardsPermutations;
    std::vector< std::vector<char> > operatorsPermutations = operators();

    std::cin >> a >> b >> c >> d;

    cardsPermutations = cards(a, b, c, d);

    for(int i = 0; i < 24; i++){     // For each row in the cards' 2D Vector, traverse through all of the possible operator permutations stored in another 2D Vector
        for(int j = 0; j < 64; j++){
            if(cardsPermutations[i][0] != 0){
                // Case 1: (a operates b) operates (c operates d)
                if(operate(operate(cardsPermutations[i][0], cardsPermutations[i][1], operatorsPermutations[j][0]), operate(cardsPermutations[i][2], cardsPermutations[i][3], operatorsPermutations[j][2]), operatorsPermutations[j][1]) == 24){
                    std::cout << '(' << cardsPermutations[i][0] << ' ' << operatorsPermutations[j][0] << ' ' << cardsPermutations[i][1] << ") " << operatorsPermutations[j][1] << " (" << cardsPermutations[i][2] << ' ' << operatorsPermutations[j][2] << ' ' << cardsPermutations[i][3] << ")\n";
                    solutionCount++;
                }
                // Case 2: ((a operates b) operates c) operates d
                if(operate(operate(operate(cardsPermutations[i][0], cardsPermutations[i][1], operatorsPermutations[j][0]), cardsPermutations[i][2], operatorsPermutations[j][1]), cardsPermutations[i][3], operatorsPermutations[j][2]) == 24){
                    std::cout << "((" << cardsPermutations[i][0] << ' ' << operatorsPermutations[j][0] << ' ' << cardsPermutations[i][1] << ") " << operatorsPermutations[j][1] << ' ' << cardsPermutations[i][2] << ") " << operatorsPermutations[j][2] << ' ' << cardsPermutations[i][3] << '\n';
                    solutionCount++;
                }
                // Case 3: (a operates (b operates c)) operates d
                if(operate(operate(cardsPermutations[i][0], operate(cardsPermutations[i][1], cardsPermutations[i][2], operatorsPermutations[j][1]), operatorsPermutations[j][0]), cardsPermutations[i][3], operatorsPermutations[j][2]) == 24){
                    std::cout << '(' << cardsPermutations[i][0] << ' ' << operatorsPermutations[j][0] << " (" << cardsPermutations[i][1] << ' ' << operatorsPermutations[j][1] << ' ' << cardsPermutations[i][2] << ")) " << operatorsPermutations[j][2] << ' ' << cardsPermutations[i][3] << '\n';
                    solutionCount++;
                }
                // Case 4: a operates ((b operates c) operates d)
                if(operate(cardsPermutations[i][0], operate(operate(cardsPermutations[i][1], cardsPermutations[i][2], operatorsPermutations[j][1]), cardsPermutations[i][3], operatorsPermutations[j][2]), operatorsPermutations[j][0]) == 24){
                    std::cout << cardsPermutations[i][0] << ' ' << operatorsPermutations[j][0] << " ((" << cardsPermutations[i][1] << ' ' << operatorsPermutations[j][1] << ' ' << cardsPermutations[i][2] << ") " << operatorsPermutations[j][2] << ' ' << cardsPermutations[i][3] << ")\n";
                    solutionCount++;
                }
                // Case 5: a operates (b operates(c operates d))
                if(operate(cardsPermutations[i][0], operate(cardsPermutations[i][1], operate(cardsPermutations[i][2], cardsPermutations[i][3], operatorsPermutations[j][2]), operatorsPermutations[j][1]), operatorsPermutations[j][0]) == 24){
                    std::cout << cardsPermutations[i][0] << ' ' << operatorsPermutations[j][0] << " (" << cardsPermutations[i][1] << ' ' << operatorsPermutations[j][1] << " (" << cardsPermutations[i][2] << ' ' << operatorsPermutations[j][2] << ' ' << cardsPermutations[i][3] << "))\n";
                    solutionCount++;
                }
            }
        }
    }

    if(solutionCount == 0) std::cout << "No solutions found\n";
    else std::cout << solutionCount << " solutions found\n";
}

int main(){
    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    // Solve
    solve24();

    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    printf("Execution Time : %.3f seconds\n", elapsed);

    return 0;
}