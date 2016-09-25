CC = gcc
CFLAGS = -std=c99 -fPIC
SRC := $(patsubst %.c,%.o,$(wildcard src/*.c))
TEST := $(patsubst %.c,%.o,$(wildcard tests/*.c))

clean:
	rm -f *.so check_tests $(SRC) $(TEST)

check: $(SRC) $(TEST)
	${CC} ${CFLAGS} -o check_tests $(SRC) $(TEST) -lcheck -lpthread -lm -lrt
	./check_tests

libromancal: $(SRC)
	${CC} ${CFLAGS} -shared -o libromancal.so $(SRC)

.c.o:
	${CC} ${CFLAGS} -c $< -o $@
