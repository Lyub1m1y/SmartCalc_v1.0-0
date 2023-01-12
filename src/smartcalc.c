#include "smartcalc.h"

// debug
// int main() {
//   int status = OK;
//   double double_result = 0.0;
//   char text[] = "2+2";
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

    stack_t* reverseOutput = NULL;
    reversePolishNotation(tokens, &reverseOutput);
    stack_t* output = NULL;
    stack_reverse_(&output, &reverseOutput);

    calculate(&output);
    // sprintf(text, "%lf", output->value);
    *double_result = output->value;
    // stack_print_(output);  // TODO debug delete
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
  }
}

void reversePolishNotation(stack_t* stack, stack_t** numStack) {
  stack_t* supportStack = {0};
  while (stack) {
    if (stack_peekType_(stack) != CLOSEBRACKET) {
      if (stack_peekType_(stack) == NUMBER) {
        stack_push_(stack->value, stack->priority, stack_peekType_(stack),
                    numStack);
      } else {
        while (1) {
          if ((checkSupport(supportStack, stack->priority)) ||
              stack_peekType_(stack) == OPENBRACKET) {
            stack_push_(stack->value, stack->priority, stack_peekType_(stack),
                        &supportStack);
            break;
          } else {
            stack_push_(supportStack->value, supportStack->priority,
                        supportStack->type, numStack);
            stack_pop_(&supportStack);
          }
        }
      }
    } else {
      while (supportStack->type != OPENBRACKET) {
        stack_push_(supportStack->value, supportStack->priority,
                    supportStack->type, numStack);
        stack_pop_(&supportStack);
      }
      stack_pop_(&supportStack);
    }
    stack = stack->next;
  }
  while (supportStack) {
    stack_push_(supportStack->value, supportStack->priority, supportStack->type,
                numStack);
    stack_pop_(&supportStack);
  }
}

void calculate(stack_t** stack) {
  while ((*stack)->next != NULL) {
    stack_t *tmp_1 = {0}, *tmp_2 = {0}, *tmp_3 = {0};
    tmp_1 = *stack;
    tmp_2 = tmp_1->next;
    if (tmp_2->next != NULL) {
      tmp_3 = tmp_2->next;
    }
    if (tmp_2->type == NUMBER) {
      while (!tmp_3->priority) {
        tmp_1 = tmp_2;
        tmp_2 = tmp_1->next;
        tmp_3 = tmp_2->next;
      }
      if (stack_peekType_(tmp_3) > 1 && stack_peekType_(tmp_3) < 8) {
        calcLexems(stack, tmp_1, tmp_2, tmp_3);
      } else {
        calcFuncs(stack, tmp_2, tmp_3);
      }
    } else {
      calcFuncs_2(stack, tmp_1, tmp_2);
    }
  }
}

void calcLexems(stack_t** stack, stack_t* tmp_1, stack_t* tmp_2,
                stack_t* tmp_3) {
  double numStack = 0;
  double a = tmp_1->value;
  double b = tmp_2->value;
  if (stack_peekType_(tmp_3) == PLUS) {
    numStack = a + b;
  } else if (stack_peekType_(tmp_3) == MINUS) {
    numStack = a - b;
  } else if (stack_peekType_(tmp_3) == MUL) {
    numStack = a * b;
  } else if (stack_peekType_(tmp_3) == DIV) {
    numStack = a / b;
  } else if (stack_peekType_(tmp_3) == POW) {
    numStack = pow(a, b);
  } else if (stack_peekType_(tmp_3) == MOD) {
    numStack = fmod(a, b);
  }
  tmp_1->priority = 0;
  tmp_1->type = NUMBER;
  tmp_1->value = numStack;
  delStack(stack, tmp_3);
  delStack(stack, tmp_2);
}

void calcFuncs(stack_t** stack, stack_t* tmp_2, stack_t* tmp_3) {
  double a = 0;
  double numStack = 0;
  a = tmp_2->value;
  if (stack_peekType_(tmp_3) == UNPLUS) {
    numStack = +a;
  } else if (stack_peekType_(tmp_3) == UNMINUS) {
    numStack = -a;
  } else if (stack_peekType_(tmp_3) == SIN) {
    numStack = sin(a);
  } else if (stack_peekType_(tmp_3) == COS) {
    numStack = cos(a);
  } else if (stack_peekType_(tmp_3) == TAN) {
    numStack = tan(a);
  } else if (stack_peekType_(tmp_3) == ASIN) {
    numStack = asin(a);
  } else if (stack_peekType_(tmp_3) == ACOS) {
    numStack = acos(a);
  } else if (stack_peekType_(tmp_3) == ATAN) {
    numStack = atan(a);
  } else if (stack_peekType_(tmp_3) == LN) {
    numStack = log(a);
  } else if (stack_peekType_(tmp_3) == LOG) {
    numStack = log10(a);
  } else if (stack_peekType_(tmp_3) == SQRT) {
    numStack = sqrt(a);
  }
  tmp_2->priority = 0;
  tmp_2->type = NUMBER;
  tmp_2->value = numStack;
  delStack(stack, tmp_3);
}

void calcFuncs_2(stack_t** stack, stack_t* tmp_1, stack_t* tmp_2) {
  double a = 0;
  double numStack = 0;
  a = tmp_1->value;
  if (stack_peekType_(tmp_2) == UNPLUS) {
    numStack = +a;
  } else if (stack_peekType_(tmp_2) == UNMINUS) {
    numStack = -a;
  } else if (stack_peekType_(tmp_2) == SIN) {
    numStack = sin(a);
  } else if (stack_peekType_(tmp_2) == COS) {
    numStack = cos(a);
  } else if (stack_peekType_(tmp_2) == TAN) {
    numStack = tan(a);
  } else if (stack_peekType_(tmp_2) == ASIN) {
    numStack = asin(a);
  } else if (stack_peekType_(tmp_2) == ACOS) {
    numStack = acos(a);
  } else if (stack_peekType_(tmp_2) == ATAN) {
    numStack = atan(a);
  } else if (stack_peekType_(tmp_2) == LN) {
    numStack = log(a);
  } else if (stack_peekType_(tmp_2) == LOG) {
    numStack = log10(a);
  } else if (stack_peekType_(tmp_2) == SQRT) {
    numStack = sqrt(a);
  }
  tmp_1->priority = 0;
  tmp_1->type = NUMBER;
  tmp_1->value = numStack;
  delStack(stack, tmp_2);
}

void delStack(stack_t** result, stack_t* tmp) {
  stack_t* tmp_in_function = {0};
  tmp_in_function = *result;
  if (*result == tmp) {
    tmp_in_function = (*result)->next;
    free(*result);
    *result = tmp_in_function;
  } else {
    while (tmp_in_function->next != tmp) {
      tmp_in_function = tmp_in_function->next;
    }
    tmp_in_function->next = tmp->next;
    free(tmp);
  }
}

// Эта функция для проверки строки(var x) число это или чтобы заменить x
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
  if (symb == 'm') {
    status = OK;
    (*i) += 3;
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
  if (((prev == 'x') || (isdigit(prev != 0) || (prev != '\0'))) &&
      ((funcsParentheses(text, i, 1) == OK) ||
       (isdigit(next != 0) || (next != '\0')) && (next != ')'))) {
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

int stack_peekType_(stack_t* stack) { return stack->type; }

int checkSupport(stack_t* helpStack, int priority) {
  int numStack = 0;
  if (helpStack != NULL) {
    if (priority > helpStack->priority) {
      numStack = 1;
    }
  } else {
    numStack = 1;
  }
  return numStack;
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
