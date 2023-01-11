#include "smartcalc.h"

// debug
// int main() {
//   int status = OK;
//   double double_result = 0.0;
//   char text[] = "(5+(cos(7)+atan(20.505056)^30))";
//   status = entryPoint(text, &double_result);
//   printf("|status = %d|\n", status);
//   return status;
// }

int entryPoint(char* text, double* double_result) {
  int status = OK;
  if (validator(text) == OK) {
    stack_t* reverseTokens = NULL;
    parser(text, &reverseTokens);
    stack_t* tokens = NULL;
    stack_reverse_(&tokens, &reverseTokens);
    stack_print_(tokens);
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

void parser(char* text, stack_t** reverseTokens) {
  int text_length = strlen(text);
  for (int i = 0; i < text_length; i++) {
    if (isdigit(text[i]) != 0) {
      char number[255] = {0};
      double value = 0.0;
      int j = 0;
      while ((isdigit(text[i]) != 0) || (isDot(&text[i]) == OK)) {
        number[j] = text[i];
        j++;
        i++;
      }
      i--;
      sscanf(number, "%lf", &value);
      stack_push_(value, 0, NUMBER, reverseTokens);
    } else if (text[i] == '(') {
      stack_push_(0, 0, OPENBRACKET, reverseTokens);
    } else if (text[i] == ')') {
      stack_push_(0, 0, CLOSEBRACKET, reverseTokens);
    } else if (text[i] == '*') {
      stack_push_(0, 2, MUL, reverseTokens);
    } else if (text[i] == '/') {
      stack_push_(0, 2, DIV, reverseTokens);
    } else if (text[i] == 'm') {
      stack_push_(0, 2, MOD, reverseTokens);
      i += 2;
    } else if (text[i] == '^') {
      stack_push_(0, 3, POW, reverseTokens);
    } else if (text[i] == 's') {
      if (text[i + 1] == 'i') {
        stack_push_(0, 4, SIN, reverseTokens);
        i += 2;
      } else if (text[i + 1] == 'q') {
        stack_push_(0, 4, SQRT, reverseTokens);
        i += 3;
      }
    } else if (text[i] == 'l') {
      if (text[i + 1] == 'n') {
        stack_push_(0, 4, LN, reverseTokens);
        i += 1;
      } else if (text[i + 1] == 'o') {
        stack_push_(0, 4, LOG, reverseTokens);
        i += 2;
      }
    } else if (text[i] == 'c') {
      stack_push_(0, 4, COS, reverseTokens);
      i += 2;
    } else if (text[i] == 't') {
      stack_push_(0, 4, TAN, reverseTokens);
      i += 2;
    } else if (text[i] == 'a') {
      if (text[i + 1] == 's') {
        stack_push_(0, 4, ASIN, reverseTokens);
        i += 3;
      } else if (text[i + 1] == 'c') {
        stack_push_(0, 4, ACOS, reverseTokens);
        i += 3;
      } else if (text[i + 1] == 't') {
        stack_push_(0, 4, ATAN, reverseTokens);
        i += 3;
      }
    } else if (text[i] == '+') {
      if ((i == 0) || (text[i - 1] == '(')) {
        stack_push_(0, 1, UNPLUS, reverseTokens);
      } else {
        stack_push_(0, 1, PLUS, reverseTokens);
      }
    } else if (text[i] == '-') {
      if ((i == 0) || (text[i - 1] == '(')) {
        stack_push_(0, 1, UNMINUS, reverseTokens);
      } else {
        stack_push_(0, 1, MINUS, reverseTokens);
      }
    }
    // TODO нужно допилить парсер
  }
}

// Эта функция для проверки reverseTokens(var x) число это или чтобы заменить x
// начисло
int isNumber(char* str, int* mod) {
  int status = OK;
  int dotCount = 0;
  int i = (*mod);
  while (((isdigit(str[i]) == OK) || (str[i] == '.')) && (status != FAIL)) {
    if (isdigit(str[i]) == OK) {
      if (str[i] != '.') {
        status = FAIL;
      } else {
        dotCount++;
        if (dotCount > 1) {
          status = FAIL;
        }
      }
    }
    i++;
  }
  (*mod) = i;
  return status;
}
// int checkSin(char* sin, int* mod) {
//   int status = FAIL;
//   if (strncmp((&sin[(*mod)]), "sin(", 4)) {
//     status = OK;
//   }
//   return status;
// }

// int checkCos(char* cos, int* mod) {
//   int status = FAIL;
//   if (strncmp((&cos[(*mod)]), "cos(", 4)) {
//     status = OK;
//   }
//   return status;
// }

// int checkTan(char* tan, int* mod) {
//   int status = FAIL;
//   if (strncmp((&tan[(*mod)]), "tan(", 4)) {
//     status = OK;
//   }
//   return status;
// }

// int checkAcos(char* acos, int* mod) {
//   int status = FAIL;
//   if (strncmp((&acos[(*mod)]), "acos(", 5)) {
//     status = OK;
//   }
//   return status;
// }

// int checkAtan(char* atan, int* mod) {
//   int status = FAIL;
//   if (strncmp((&atan[(*mod)]), "atan(", 5)) {
//     status = OK;
//   }
//   return status;
// }

// int checkAsin(char* asin, int* mod) {
//   int status = FAIL;
//   if (strncmp((&asin[(*mod)]), "asin(", 5)) {
//     status = OK;
//   }
//   return status;
// }

// int checkSqrt(char* sqrt, int* mod) {
//   int status = FAIL;
//   if (strncmp((&sqrt[(*mod)]), "sqrt(", 5)) {
//     status = OK;
//   }
//   return status;
// }

// int checkLn(char* ln, int* mod) {
//   int status = FAIL;
//   if (strncmp((&ln[(*mod)]), "ln(", 3)) {
//     status = OK;
//   }
//   return status;
// }

// int checkLog(char* log, int* mod) {
//   int status = FAIL;
//   if (strncmp((&log[(*mod)]), "log(", 4)) {
//     status = OK;
//   }
//   return status;
// }

int isDot(char* dot) {
  int status = FAIL;
  if (*dot == '.') {
    status = OK;
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
      (*i) += 3;
    }
    if (next == 'o') {
      status = OK;
      (*i) += 4;
    }
  }
  if (symb == 's') {
    if (next == 'q') {
      status = OK;
      (*i) += 5;
    }
    if (next == 'i') {
      status = OK;
      (*i) += 4;
    }
  }
  if (symb == 'c') {
    status = OK;
    (*i) += 4;
  }
  if (symb == 't') {
    status = OK;
    (*i) += 4;
  }
  if (symb == 'a') {
    if (next == 's') {
      status = OK;
      (*i) += 5;
    }
    if (next == 'c') {
      status = OK;
      (*i) += 5;
    }
    if (next == 't') {
      status = OK;
      (*i) += 5;
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
  char prev = text[(*i) - 1];
  char next = text[(*i) + 1];
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

int isOper(char symb) {
  int status = FAIL;
  if (symb == '+') {
    status = OK;
  }
  if (symb == '-') {
    status = OK;
  }
  if (symb == '*') {
    status = OK;
  }
  if (symb == '/') {
    status = OK;
  }
  if (symb == '^') {
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

void stack_push_(double value, int priority, type_t type, stack_t** stack) {
  stack_t* new = malloc(sizeof(stack_t));
  if (new != NULL) {
    new->value = value;
    new->priority = priority;
    new->type = type;
    new->next = *stack;
    *stack = new;
  }
}

void stack_pop_(stack_t** last) {
  if (*last != NULL) {
    stack_t* tmp = (*last)->next;
    free(*last);
    *last = tmp;
  }
}

void stack_reverse_(stack_t** stack, stack_t** reverse_stack) {
  while (*reverse_stack) {
    stack_push_((*reverse_stack)->value, (*reverse_stack)->priority,
                (*reverse_stack)->type, stack);
    stack_pop_(reverse_stack);
  }
}
// TODO del func stack_print__
void stack_print_(stack_t* stack) {
  char delimeter[] = "";
  stack_t* tmp = stack;
  while (tmp != NULL) {
    printf("[");
    printf("\"%f\",", tmp->value);
    printf("\"%d\",", tmp->priority);
    printf("\"%d\",", tmp->type);
    if (tmp == NULL) break;
    tmp = tmp->next;
    printf("]\n");
  }
}

stack_t* stack_free_(stack_t* list) {
  while (list != NULL) {
    stack_t* temporary = list;
    list = list->next;
    free(temporary);
  }
  return NULL;
}

// int isX(char* str) {
//   int status = FAIL;
//   int str_length = strlen(str);
//   for (int i = 0; i < str_length; i++) {
//     if (str[i] == 'x') {
//       status = OK;
//     }
//   }
//   return status;
// }
