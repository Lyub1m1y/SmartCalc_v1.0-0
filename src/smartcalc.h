#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef OK
#define OK 0
#endif

#ifndef FAIL
#define FAIL 1
#endif

typedef enum type_t {
  NUMBER = 1,
  PLUS,
  MINUS,
  MUL,
  DIV,
  POW,
  MOD,
  OPENBRACKET,
  CLOSEBRACKET,
  LN,
  SQRT,
  SIN,
  COS,
  TAN,
  LOG,
  ASIN,
  ACOS,
  ATAN,
  UNPLUS,
  UNMINUS,
  DOT,
  X
} type_t;

/* priority
 0 - |'0-9'|, |'.'|,'('|, |')'|;
 1 - |'+'|, |'-'|;
 1 - |'*'|, |'/'|, |"mod"|;
 3 - |'^'|;
 4 - |'sin'|, |'cos'|, ...;
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
void parser(char* text, stack_t** reverseTokens);
void reversePolishNotation(stack_t* stack, stack_t** numStack);
void calculate(stack_t** stack);
// int isX(char* str); // TODO delete
void comToDot(char* text);  // TODO delete
int isNumber(char* str, int* mod);
int isDot(char* dot);
int isSign(char* text, int* i, int* dotCount);
int isOper(char symb);
int checkCorrectOperator(char* text, int* i);
int checkCorrectOperator(char* text, int* i);
int checkRatioBrackets(char* text, int text_length);
int checkSupport(stack_t* helpStack, int priority);
int funcsParentheses(char* text, int* i, int sum);
void calcLexems(stack_t** stack, stack_t* tmp_1, stack_t* tmp_2,
                stack_t* tmp_3);
void calcFuncs(stack_t** stack, stack_t* tmp_2, stack_t* tmp_3);
void delStack(stack_t** result, stack_t* tmp);

// stack funcs
void stack_push_(double value, int priority, type_t type, stack_t** stack);
void stack_pop_(stack_t** last);
void stack_reverse_(stack_t** stack, stack_t** reverse_stack);
void stack_print_(stack_t* stack);  // TODO debug delete
int stack_peekType_(stack_t* list);
stack_t* stack_free_(stack_t* list);

#endif  // SRC_SMARTCALC_H_
