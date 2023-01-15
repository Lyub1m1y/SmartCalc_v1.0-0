// #include <check.h>

// #include "smartcalc.h"

// START_TEST(test_smart_calc_1) {
//   char input[255] = "3+4*2/(1-5)^2";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq(result, 3.5);
// }
// END_TEST

// START_TEST(test_smart_calc_2) {
//   char input[255] = "1+2+3+4*5*6^7";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq(result, 5598726);
// }
// END_TEST

// START_TEST(test_smart_calc_3) {
//   char input[255] = "123.456+2*3^4";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq(result, 285.456);
// }
// END_TEST

// START_TEST(test_smart_calc_4) {
//   char input[255] = "(8+2*5)/(1+3*2-4)";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq(result, 6);
// }
// END_TEST

// START_TEST(test_smart_calc_5) {
//   char input[255] =
//       "(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/2)))";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq(result, 10);
// }
// END_TEST

// START_TEST(test_smart_calc_6) {
//   char input[255] = "cos(1*2)-1";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq_tol(result, -1.41614683655, 1e-06);
// }
// END_TEST

// START_TEST(test_smart_calc_7) {
//   char input[255] =
//       "cos(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/"
//       "2)))-1";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq_tol(result, -1.83907152908, 1e-06);
// }
// END_TEST

// START_TEST(test_smart_calc_8) {
//   char input[255] = "sin(cos(5))";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq_tol(result, 0.27987335076, 1e-06);
// }
// END_TEST

// START_TEST(test_smart_calc_9) {
//   char input[255] = "2.33mod1";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq_tol(result, 0.33, 1e-06);
// }
// END_TEST

// START_TEST(test_smart_calc_10) {
//   double x = 10;
//   char input[255] = "3+4*2/1-5+2^2";
//   double result;
//   MainCalc(input, &result, x);
//   ck_assert_double_eq_tol(result, 10, 1e-06);
// }
// END_TEST

// START_TEST(test_smart_calc_11) {
//   double x = 10;
//   char input[255] = "3+4*2/1-5+2^2";
//   double result;
//   MainCalc(input, &result, x);
//   ck_assert_double_eq_tol(result, 10, 1e-06);
// }
// END_TEST

// START_TEST(test_smart_calc_12) {
//   double x = 0.0003;
//   char input[255] = "asin(2*x)";
//   double result;
//   MainCalc(input, &result, x);
//   ck_assert_double_eq_tol(result, 0.0006, 1e-06);
// }
// END_TEST

// START_TEST(test_smart_calc_13) {
//   double x = 0.0019;
//   char input[255] = "acos(2*x)";
//   double result;
//   MainCalc(input, &result, x);
//   ck_assert_double_eq_tol(result, 1.567, 1e-03);
// }
// END_TEST

// START_TEST(test_smart_calc_14) {
//   double x = 0.0019;
//   char input[255] = "atan(2*x)";
//   double result;
//   MainCalc(input, &result, x);
//   ck_assert_double_eq_tol(result, 0.00379998, 1e-06);
// }
// END_TEST

// START_TEST(test_smart_calc_15) {
//   double x = 0.004;
//   char input[255] = "tan(2*x)";
//   double result;
//   MainCalc(input, &result, x);
//   ck_assert_double_eq_tol(result, 0.00800017, 1e-06);
// }
// END_TEST

// START_TEST(test_smart_calc_16) {
//   double x = 25;
//   char input[255] = "sqrt(2*x)";
//   double result;
//   MainCalc(input, &result, x);
//   ck_assert_double_eq_tol(result, 7.07107, 1e-05);
// }
// END_TEST

// START_TEST(test_smart_calc_17) {
//   double x = 2;
//   char input[255] = "ln(10*x)";
//   double result;
//   MainCalc(input, &result, x);
//   ck_assert_double_eq_tol(result, 2.99573, 1e-05);
// }
// END_TEST

// START_TEST(test_smart_calc_18) {
//   double x = 2;
//   char input[255] = "log(10*x)";
//   double result;
//   MainCalc(input, &result, x);
//   ck_assert_double_eq_tol(result, 1.30103, 1e-05);
// }
// END_TEST

// START_TEST(test_smart_calc_19) {
//   char input[255] = "()";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq_tol(result, 0, 1e-06);
// }
// END_TEST

// START_TEST(test_smart_calc_20) {
//   char input[255] = "3-(-3)";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq_tol(result, 6, 1e-06);
// }
// END_TEST

// START_TEST(test_smart_calc_21) {
//   char input[255] = "3-(+3)";
//   double result;
//   MainCalc(input, &result, 0.0);
//   ck_assert_double_eq_tol(result, 0, 1e-06);
// }
// END_TEST

// int main() {
//   Suite *s1 = suite_create("s21_smart_calc: ");
//   TCase *tc1_1 = tcase_create("s21_smart_calc: ");
//   SRunner *sr = srunner_create(s1);
//   int result;
//   suite_add_tcase(s1, tc1_1);

//   tcase_add_test(tc1_1, test_smart_calc_1);
//   tcase_add_test(tc1_1, test_smart_calc_2);
//   tcase_add_test(tc1_1, test_smart_calc_3);
//   tcase_add_test(tc1_1, test_smart_calc_4);
//   tcase_add_test(tc1_1, test_smart_calc_5);
//   tcase_add_test(tc1_1, test_smart_calc_6);
//   tcase_add_test(tc1_1, test_smart_calc_7);
//   tcase_add_test(tc1_1, test_smart_calc_8);
//   tcase_add_test(tc1_1, test_smart_calc_9);
//   tcase_add_test(tc1_1, test_smart_calc_10);
//   tcase_add_test(tc1_1, test_smart_calc_11);
//   tcase_add_test(tc1_1, test_smart_calc_12);
//   tcase_add_test(tc1_1, test_smart_calc_13);
//   tcase_add_test(tc1_1, test_smart_calc_14);
//   tcase_add_test(tc1_1, test_smart_calc_15);
//   tcase_add_test(tc1_1, test_smart_calc_15);
//   tcase_add_test(tc1_1, test_smart_calc_16);
//   tcase_add_test(tc1_1, test_smart_calc_17);
//   tcase_add_test(tc1_1, test_smart_calc_18);
//   tcase_add_test(tc1_1, test_smart_calc_19);
//   tcase_add_test(tc1_1, test_smart_calc_20);
//   tcase_add_test(tc1_1, test_smart_calc_21);

//   srunner_run_all(sr, CK_ENV);
//   result = srunner_ntests_failed(sr);
//   srunner_free(sr);
//   return result == 0 ? 0 : 1;
// }
