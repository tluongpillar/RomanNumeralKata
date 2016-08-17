main: src/main.c
	gcc -o main src/main.c

clean:
	rm main

check: check_libcheck.o
	gcc -o check_tests check_libcheck.o -lcheck -lpthread -lm -lrt

check_libcheck.o:
	gcc -c tests/check_libcheck.c -o check_libcheck.o
