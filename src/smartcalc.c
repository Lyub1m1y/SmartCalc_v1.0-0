#include "smartcalc.h"

// debug
// int main() {
//   double double_result = 0.0;
//   char text[] = "+.12345";
//   int status = entryPoint(text, &double_result);
//   return 0;
// }
// Эта функция для проверки input(var x) число это или чтобы заменить x начисло
int isNumber(char* str) {
  int status = OK;
  int strLength = strlen(str);
  int dotCount = 0;
  for (int i = 0; i < strLength && status != FAIL; i++) {
    if (isdigit(str[i]) == 0) {
      if (str[i] != '.') {
        status = FAIL;
      } else {
        dotCount++;
        if (dotCount > 1) {
          status = FAIL;
        }
      }
    }
  }
  return status;
}

int funcsParentheses(char* text, int i) {
  int status = FAIL;
  char symb = text[i + 1];
  if (symb == 'c') {
  }

  return status;
}

int isSign(char* text, int i, int* dot) {
  int status = FAIL;
  if (text[i] == '+') {
    if ((isdigit(text[i - 1] != 0) || text[i - 1] != NULL ||
         text[i - 1] == '(' || text[i - 1] == ')') &&
        (isdigit(text[i + 1] != 0) || text[i + 1] != NULL ||
         text[i + 1] == '(' || text[i + 1] == ')')) {
      status = OK;
    }
  }
  if (text[i] == '-') {
    status = OK;
  }
  if (text[i] == '*') {
    status = OK;
  }
  if (text[i] == '/') {
    status = OK;
  }
  if (text[i] == '^') {
    status = OK;
  }
  if (text[i] == '.') {
    status = OK;
  }
}

int entryPoint(char* text, double* double_result) {
  int status = OK;
  if (validator(text) == OK) {
  } else {
    status = FAIL;
  }
  // *double_result = 99999.9;
  return status;
}

int validator(char* text) {
  int status = OK;
  // int text_length = strlen(text);
  // for (int i = 0; i < text_length && status != FAIL; i++) {
  //   if (isdigit(text[i])) {
  //   } else if () {
  //     status = FAIL;
  //   }
  // }
  return status;
}
