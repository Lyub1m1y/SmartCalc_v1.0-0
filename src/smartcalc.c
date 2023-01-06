#include "smartcalc.h"
// debug
// int main() {
//   double double_result = 0.0;
//   char text[] = "22.22";
//   int status = entryPoint(text, &double_result);
//   return 0;
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
  for (int i = 0; i < text_length && status != FAIL; i++, ++text) {
    if (text[i] = "") {
    } else {
      status = FAIL;
    }
    ++text;
  }
  return status;
}
