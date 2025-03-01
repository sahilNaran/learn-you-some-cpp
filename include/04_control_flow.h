#ifndef CONTROL_FLOW_H
#define CONTROL_FLOW_H

#include <string>
unsigned long long factorial(int n);
char gradeConverter_if(int score);
char gradeConverter_switch(int score);
int findFirstDigit(int number);
int sumOddDigits(int number);
int countDigitsInRange_for(int number, int min, int max);
int countDigitsInRange_while(int number, int min, int max);
int countDigitsInRange_dowhile(int number, int min, int max);
std::string fizzBuzz_if(int number);

#endif
