#include "headers/check_libcheck.h"

START_TEST (test_libcheck_one_equals_one__returns_true)
{
  ck_assert( 1 == 1);
}
END_TEST

START_TEST (test_libcheck_one_equals_two__returns_false)
{
  ck_assert( 1 != 2);
}
END_TEST

Suite * libcheck_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("Libcheck");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_libcheck_one_equals_one__returns_true);
  tcase_add_test(tcase_core, test_libcheck_one_equals_two__returns_false);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
