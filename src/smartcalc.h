#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef OK
#define OK 0
#endif

#ifndef FAIL
#define FAIL 1
#endif

// for checking during dubug
typedef enum type_t {
  NUMBER = 1,
  PLUS = 2,
  MINUS = 3,
  MUL = 4,
  DIV = 5,
  POW = 6,
  BRACKETL = 7,
  BRACKETR = 8,
  LN = 9,
  SQRT = 10,
  SIN = 11,
  COS = 12,
  TAN = 13,
  MOD = 14,
  LOG = 15,
  ASIN = 16,
  ACOS = 17,
  ATAN = 18
} type_t;

/* priority
 0 - |'0-9'|, |'.'|;
 1 - |'+'|, |'-'|;
 1 - |'*'|, |'/'|, |"mod"|;
 3 - |'^'|;
 4 - |'sin'|, |'cos'|, ...;
 5 - |'('|, |')'|;
 */

// stack preEntity
typedef struct stack_t {
  double value;
  int priority;
  type_t type;
  struct stack_t* next;
} stack_t;

int entryPoint(char* text, double* double_result);
int validator(char* text);
int isNumber(char* str, int* mod);
int checkCorrectOperator(char* text, int* i);
int funcsParentheses(char* text, int* i, int sum);
int checkCorrectOperator(char* text, int* i);
int isSign(char* text, int* i, int* dotCount);
int isOper(char symb);
int checkRatioBrackets(char* text, int text_length);

// stack funcs
stack_t stack_init_();
void stack_push_(double value, int priority, type_t type, stack_t** stack);
void stack_pop_(stack_t** last);
void stack_reverse_(stack_t** stack, stack_t** reverse_stack);
stack_t* stack_free_(stack_t* list);

#endif  // SRC_SMARTCALC_H_
