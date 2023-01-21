#include <check.h>

#include "../Model/smartcalc.h"

START_TEST(test_smart_calc_1) {
  char input[255] = "(((5)))";
  int text_length = strlen(input);
  int status = checkRatioBrackets(input, text_length);
  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(test_smart_calc_2) {
  char input[255] = "(((5))";
  int text_length = strlen(input);
  int status = checkRatioBrackets(input, text_length);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(test_smart_calc_3) {
  char input_1[255] = "xln(log(sqrt(sin(cos(modtan(";
  int intput_1_length = strlen(input_1);
  int status = FAIL;
  for (int i = 0; i < intput_1_length; i++) {
    status = funcsParentheses(input_1, &i, 0);
  }
  char input_2[255] = "log(-sin(3mod4+acos(-asin(-atan(";
  int intput_2_length = strlen(input_2);
  for (int i = 0; i < intput_2_length; i++) {
    status = funcsParentheses(input_2, &i, 0);
  }
  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(test_smart_calc_4) {
  char input[255] = "++-*/^.()";
  int text_length = strlen(input);
  int status = OK;
  for (int i = 0; i < text_length; i++) {
    status = checkCorrectOperator(input, &i);
  }
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(test_smart_calc_5) {
  char input[255] = "++-*/^.()";
  int text_length = strlen(input);
  int dotCount = 0;
  int status = FAIL;
  for (int i = 0; i < text_length; i++) {
    status = isSign(input, &i, &dotCount);
  }
  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(test_smart_calc_6) {
  char input[255] = "1+2+3+4.5*5*6..^7*cos(25)";
  int status = validator(input);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(test_smart_calc_7) {
  char input[255] = "g";
  int status = validator(input);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(test_smart_calc_8) {
  char input[255] = "((5)";
  int status = validator(input);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(test_smart_calc_9) {
  double x_value = 3.3;
  stack_tt *reverseTokens = NULL;
  char input[255] =
      "(+3-log(2))-(-ln(3))^23mod1+cos(87)-x)*tan(sin(sqrt(asin(acos("
      "atan(30/"
      "20^))))))";
  parser(input, &reverseTokens, x_value);
  ck_assert_int_eq(reverseTokens->type, CLOSEBRACKET);
  stack_free_(reverseTokens);
}
END_TEST

START_TEST(test_smart_calc_10) {
  double x_value = 3.3;
  stack_tt *reverseTokens = NULL;
  stack_tt *tokens = NULL;
  stack_tt *reverseOutput = NULL;
  char input[255] = "2mod4-(2+cos(3))";
  parser(input, &reverseTokens, x_value);
  stack_reverse_(&tokens, &reverseTokens);

  reversePolishNotation(tokens, &reverseOutput);
  ck_assert_int_eq(reverseOutput->type, MINUS);
  stack_free_(reverseTokens);
  stack_free_(tokens);
  stack_free_(reverseOutput);
}
END_TEST

START_TEST(test_smart_calc_11) {
  double x_value = 3.3;
  char input[255] =
      "x+ln(-3-log(+4/sqrt(5*sin(cos(3mod5^tan(asin(acos(atan(100)))))))))";
  stack_tt *reverseTokens = NULL;
  stack_tt *tokens = NULL;
  stack_tt *reverseOutput = NULL;
  stack_tt *output = NULL;
  parser(input, &reverseTokens, x_value);
  stack_reverse_(&tokens, &reverseTokens);

  reversePolishNotation(tokens, &reverseOutput);
  stack_reverse_(&output, &reverseOutput);

  calculate(&output);
  double result = output->value;
  ck_assert_double_nan(result);
  stack_free_(reverseTokens);
  stack_free_(tokens);
  stack_free_(reverseOutput);
  stack_free_(output);
}
END_TEST

START_TEST(test_smart_calc_12) {
  char input[255] = "+-*/^";
  int text_length = strlen(input);
  int status = OK;
  for (int i = 0; i < text_length && status != FAIL; i++) {
    status = isOper(input[i]);
  }
  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(test_smart_calc_13) {
  char *dot = ".,";
  int status = isDot(dot);
  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(test_smart_calc_14) {
  char input[] = "123";
  chToTZ(input, 3, 3);
  ck_assert_str_eq(input, "");
}
END_TEST

START_TEST(test_smart_calc_15) {
  char input[] = "123.4g";
  int status = isNumber(input);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(test_smart_calc_16) {
  char input[] = "123.4";
  int status = isNumber(input);
  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(test_smart_calc_17) {
  char input[255] = "3+4*2/(1-5)^2";
  double result;
  entryPoint(input, &result, 0.0);
  ck_assert_double_eq(result, 3.5);
}
END_TEST

int main() {
  Suite *s1 = suite_create("s21_smart_calc: ");
  TCase *tc1_1 = tcase_create("s21_smart_calc: ");
  SRunner *sr = srunner_create(s1);
  int result;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, test_smart_calc_1);
  tcase_add_test(tc1_1, test_smart_calc_2);
  tcase_add_test(tc1_1, test_smart_calc_3);
  tcase_add_test(tc1_1, test_smart_calc_4);
  tcase_add_test(tc1_1, test_smart_calc_5);
  tcase_add_test(tc1_1, test_smart_calc_6);
  tcase_add_test(tc1_1, test_smart_calc_7);
  tcase_add_test(tc1_1, test_smart_calc_8);
  tcase_add_test(tc1_1, test_smart_calc_9);
  tcase_add_test(tc1_1, test_smart_calc_10);
  tcase_add_test(tc1_1, test_smart_calc_11);
  tcase_add_test(tc1_1, test_smart_calc_12);
  tcase_add_test(tc1_1, test_smart_calc_13);
  tcase_add_test(tc1_1, test_smart_calc_14);
  tcase_add_test(tc1_1, test_smart_calc_15);
  tcase_add_test(tc1_1, test_smart_calc_16);
  tcase_add_test(tc1_1, test_smart_calc_17);
  srunner_run_all(sr, CK_ENV);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result == 0 ? 0 : 1;
}
