#include "smartcalc.h"

// debug
// int main() {
//   int status = OK;
//   double double_result = 0.0;
//   char text[] = "((5))";
//   status = entryPoint(text, &double_result);
//   // printf("|status = %d|", status);
//   return status;
// }

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
  int text_length = strlen(text);
  if (checkRatioBrackets(text, text_length) == OK) {
    int dotCount = 0;
    for (int i = 0; i < text_length && status != FAIL; i++) {
      if (isdigit(text[i]) == 0) {
        if (isSign(text, &i, &dotCount) == FAIL) {
          if (funcsParentheses(text, &i, 0) == FAIL) {
            status = FAIL;
          }
        }
      }
      if (dotCount == 2) {
        status = FAIL;
      }
    }
  } else {
    status = FAIL;
  }
  return status;
}

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

int funcsParentheses(char* text, int* i, int sum) {
  int status = FAIL;
  char symb = text[(*i) + sum];
  char next = text[(*i) + sum + 1];
  if (symb == 'x') {
    status = OK;
  }
  if (symb == 'l') {
    if (next == 'n') {
      status = OK;
      (*i) += 1;
    }
    if (next == 'o') {
      status = OK;
      (*i) += 2;
    }
  }
  if (symb == 's') {
    if (next == 'q') {
      status = OK;
      (*i) += 3;
    }
    if (next == 'i') {
      status = OK;
      (*i) += 2;
    }
  }
  if (symb == 'c') {
    status = OK;
    (*i) += 2;
  }
  if (symb == 't') {
    status = OK;
    (*i) += 2;
  }
  if (symb == 'a') {
    if (next == 's') {
      status = OK;
      (*i) += 3;
    }
    if (next == 'c') {
      status = OK;
      (*i) += 3;
    }
    if (next == 't') {
      status = OK;
      (*i) += 3;
    }
  }
  return status;
}

int checkCorrectOperator(char* text, int* i) {
  int status = FAIL;
  char prev = text[(*i) - 1];
  char next = text[(*i) + 1];
  if (((prev == 'x') || (isdigit(prev != 0) || (prev != NULL))) &&
      ((funcsParentheses(text, i, 1) == OK) ||
       (isdigit(next != 0) || (next != NULL)) && (next != ')'))) {
    status = OK;
  }
  return status;
}

int isSign(char* text, int* i, int* dotCount) {
  int status = FAIL;
  char symb = text[(*i)];
  if (symb == '+') {
    if (checkCorrectOperator(text, i) == 0) {
      status = OK;
      (*dotCount) = 0;
    }
  }
  if (symb == '-') {
    if (checkCorrectOperator(text, i) == 0) {
      status = OK;
      (*dotCount) = 0;
    }
  }
  if (symb == '*') {
    if (checkCorrectOperator(text, i) == 0) {
      status = OK;
      (*dotCount) = 0;
    }
  }
  if (symb == '/') {
    if (checkCorrectOperator(text, i) == 0) {
      status = OK;
      (*dotCount) = 0;
    }
  }
  if (symb == '^') {
    if (checkCorrectOperator(text, i) == 0) {
      status = OK;
      (*dotCount) = 0;
    }
  }
  if (symb == '.') {
    if (checkCorrectOperator(text, i) == 0) {
      status = OK;
      (*dotCount) += 1;
    }
  }
  if (symb == '(') {
    status = OK;
  }
  if (symb == ')') {
    status = OK;
  }
  return status;
}

int checkRatioBrackets(char* text, int text_length) {
  int status = FAIL;
  int countL = 0;  // '('
  int countR = 0;  // ')'
  for (int i = 0; i < text_length; i++) {
    if (text[i] == '(') {
      countL++;
    }
    if (text[i] == ')') {
      countR++;
    }
  }
  if (countL == countR) {
    status = OK;
  }
  return status;
}
