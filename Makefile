CC=gcc
CFLAGS=-std=c99
SRC=src/
TEST=tests/

main:
	${CC} ${CFLAGS} -o main ${SRC}main.c

clean:
	rm main

clean_test:
	rm check_tests roman_numeral.o check_suite_runner.o check_roman_numeral.o check_libcheck.o

check: clean_test roman_numeral.o check_suite_runner.o check_roman_numeral.o check_libcheck.o
	${CC} ${CFLAGS} -o check_tests roman_numeral.o check_suite_runner.o check_roman_numeral.o check_libcheck.o -lcheck -lpthread -lm -lrt
	./check_tests

roman_numeral.o:
	${CC} ${CFLAGS} -c ${SRC}roman_numeral.c -o roman_numeral.o

check_suite_runner.o:
	${CC} ${CFLAGS} -c ${TEST}check_suite_runner.c -o check_suite_runner.o

check_roman_numeral.o:
	${CC} ${CFLAGS} -c ${TEST}check_roman_numeral.c -o check_roman_numeral.o

check_libcheck.o:
	${CC} ${CFLAGS} -c ${TEST}check_libcheck.c -o check_libcheck.o
