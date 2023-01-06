#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

#include <string.h>

#ifndef OK
#define OK 0
#endif

#ifndef FAIL
#define FAIL 1
#endif

int entryPoint(char* text, double* double_result);
int validator(char* text);
#endif  // SRC_SMARTCALC_H_
