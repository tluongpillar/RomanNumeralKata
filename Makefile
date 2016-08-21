CC=gcc
CFLAGS=-std=c99
SRC=src/
TEST=tests/

clean:
	rm check_tests roman_numeral_conversion.o roman_numeral_letter.o check_suite_runner.o check_roman_numeral_conversion.o check_roman_numeral_letter.o check_libcheck.o

check: roman_numeral_conversion.o roman_numeral_letter.o check_suite_runner.o check_roman_numeral_conversion.o check_roman_numeral_letter.o check_libcheck.o
	${CC} ${CFLAGS} -o check_tests roman_numeral_conversion.o roman_numeral_letter.o check_suite_runner.o check_roman_numeral_conversion.o check_roman_numeral_letter.o check_libcheck.o -lcheck -lpthread -lm -lrt
	./check_tests

roman_numeral_conversion.o:
	${CC} ${CFLAGS} -c ${SRC}roman_numeral_conversion.c -o roman_numeral_conversion.o

roman_numeral_letter.o:
	${CC} ${CFLAGS} -c ${SRC}roman_numeral_letter.c -o roman_numeral_letter.o

check_suite_runner.o:
	${CC} ${CFLAGS} -c ${TEST}check_suite_runner.c -o check_suite_runner.o

check_roman_numeral_conversion.o:
	${CC} ${CFLAGS} -c ${TEST}check_roman_numeral_conversion.c -o check_roman_numeral_conversion.o

check_roman_numeral_letter.o:
	${CC} ${CFLAGS} -c ${TEST}check_roman_numeral_letter.c -o check_roman_numeral_letter.o

check_libcheck.o:
	${CC} ${CFLAGS} -c ${TEST}check_libcheck.c -o check_libcheck.o
