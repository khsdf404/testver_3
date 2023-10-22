#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

class Calculator {

public:
    int ArgumentCorrect(char, double);
    int GetPriority(string);
    vector<string> InfixToPostfix(sLink);
    double Calculate(sLink equation, double* result);

};

#endif //CALCULATOR_CALCULATOR_H
