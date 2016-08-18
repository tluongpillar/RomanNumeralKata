CC=gcc
SRC=src/
TEST=tests/

main:
	${CC} -o main ${SRC}main.c

clean:
	rm main

clean_test:
	rm check_tests roman_numeral.o check_suite_runner.o check_roman_numeral.o check_libcheck.o

check: roman_numeral.o check_suite_runner.o check_roman_numeral.o check_libcheck.o
	${CC} -o check_tests roman_numeral.o check_suite_runner.o check_roman_numeral.o check_libcheck.o -lcheck -lpthread -lm -lrt

roman_numeral.o:
	${CC} -c ${SRC}roman_numeral.c -o roman_numeral.o

check_suite_runner.o:
	${CC} -c ${TEST}check_suite_runner.c -o check_suite_runner.o

check_roman_numeral.o:
	${CC} -c ${TEST}check_roman_numeral.c -o check_roman_numeral.o

check_libcheck.o:
	${CC} -c ${TEST}check_libcheck.c -o check_libcheck.o
