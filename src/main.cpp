#include <sys/time.h>
# include "solve24.h"

int main(){
    double a, b, c, d;
    std::string inputA, inputB, inputC, inputD;
    // std::cin >> inputA >> inputB >> inputC >> inputD;
    std::cin >> a >> b >> c >> d;

    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    // Solve
    std::vector< std::string > solutions = solve24(a, b, c, d);

    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    // Outputs the solutions
    std::cout << '\n' << solutions.size() << " solutions found :\n";
    for(int i = 0; i < solutions.size(); i++){
        std::cout << solutions[i] << '\n';
    }

    std::cout << "\nExecution Time : " << elapsed << " seconds\n\n";

    std::cout << "Do you want to save the answer? (Y/N) ";
    std::string input;
    std:: cin >> input;

    if(input == "Y"){
        std::cout << "Type the file name : ";
        std::cin >> input;

        std::cout << "Saving . . .\n";

        std::ofstream solutionFile;
        solutionFile.open("../test/" + input);
        solutionFile << "Cards : " << a << " " << b << " " << c << " " <<  d << "\n\n";
        solutionFile << solutions.size() << " solutions found :\n";

        for(int i = 0; i < solutions.size(); i++){
            solutionFile << solutions[i] << '\n';
        }

        solutionFile << "\nExecution Time : " << elapsed << " seconds";
        solutionFile.close();

        std::cout << "Done\n";
    }

    return 0;
}