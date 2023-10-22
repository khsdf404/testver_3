#include "Program.h"

void Program::PrintInfo() {
    cout
        << "+------------ NEXTGEN CALCULATOR ------------+\n"
        << "|                                            |\n"
        << "|    e, pi, + - * (/ :) (^ **) (sqrt|root)   |\n"
        << "|      lb|log2, ln|log, sin, cos, tg|tan     |\n"
        << "|                                            |\n"
        << "|     (\\c)       Clear Console       (\\c)    |\n"
        << "|     (\\q)           Exit            (\\q)    |\n"
        << "|                                            |\n"
        << "+--------------------------------------------+\n\n";
}


int Program::Start() {
    this->PrintInfo();
    while (true) {
        cout << "Expression << ";
        string s;
        getline(cin, s);
        if (s == "\\q" || s == "exit") { 
            cin.clear(); 
            return 0; 
        }
        else if (s == "\\c" || s == "clear") {
            system("cls");
            this->PrintInfo();
        }
        else {
            FoolProof FoolProof;
            if (!FoolProof.AllCorrect(&s)) {
                printf("\n\n Equation's wrong!");
                system("pause");
            }
            else {
                double result = 0;
                Calculator counter;
                if (counter.Calculate(s, &result)) 
                    cout << "Result     >> " << result << "\n";
                    cout << "--------------------------\n";
            }
        }
        cin.clear();
    }
    return 0;
}