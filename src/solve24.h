# include <iostream>
# include <vector>
#include <iomanip>
#include <sstream>
# include <fstream>

# ifndef _SOLVE24_H_
# define _SOLVE24_H_

void permuteOperators(std::vector< std::vector<char> > &operatorsPermutations, unsigned operatorVariant, unsigned startRow);
// Additional procedure to permute the operators if there are more than one operator variant (e.g. + and - are two different operators, hence two operator variant)

std::vector< std::vector<char> > operators();  
// Store all permutations of operators +, -, *, and / in a 2D Vector

std::vector< std::vector<double> > cards(int a, int b, int c, int d);
// Store all permutations of the four cards in a 2D Vector

std::string doubleToString(double var);
// Convert double to string with precision set to 0

void convertInput(std::string inputVar, double *var);
// Converts user input (string) to double

double operate(double operandA, double operandB, char op);
// Arithmetic operation

std::vector< std::string > solve24(double a, double b, double c, double d);
// Main algorithm of finding the solutions, returns the vector of the solution

# endif