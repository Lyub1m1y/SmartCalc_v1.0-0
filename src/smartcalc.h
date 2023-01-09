#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#ifndef OK
#define OK 0
#endif

#ifndef FAIL
#define FAIL 1
#endif

int entryPoint(char* text, double* double_result);
int validator(char* text);
int isNumber(char* str);
int checkCorrectOperator(char* text, int* i);
int funcsParentheses(char* text, int* i, int sum);
int checkCorrectOperator(char* text, int* i);
int isSign(char* text, int* i, int* dotCount);
int checkRatioBrackets(char* text, int text_length);
#endif  // SRC_SMARTCALC_H_
