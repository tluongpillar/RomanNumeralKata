#include <check.h>

START_TEST (test_libcheck)
{
  ck_assert( 1 == 2);
}
END_TEST

Suite * libcheck_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("Libcheck");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_libcheck);
  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main()
{
  Suite *suite;
  SRunner *srunner;

  suite = libcheck_suite();
  srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_NORMAL);
  srunner_free(srunner);

  return 0;
}
