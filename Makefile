CC=gcc
SRC=src/
TEST=tests/

main:
	${CC} -o main ${SRC}main.c

clean:
	rm main

clean_test:
	rm check_tests check_suite_runner.o check_libcheck.o 

check: check_suite_runner.o check_libcheck.o
	${CC} -o check_tests check_suite_runner.o check_libcheck.o -lcheck -lpthread -lm -lrt

check_suite_runner.o:
	${CC} -c ${TEST}check_suite_runner.c -o check_suite_runner.o

check_libcheck.o:
	${CC} -c ${TEST}check_libcheck.c -o check_libcheck.o
