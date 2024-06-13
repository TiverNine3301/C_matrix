CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
FLAG_COV = --coverage
LIBS_ADDITIONAL =

ifeq ($(OS), Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell uname -s)
endif
ifeq ($(detected_OS), Linux)
	detected_Linux := $(shell cat /etc/issue | sed -n '1p' | awk '{print $$1}')
	# Значение по умолчанию для любых версий Linux
	LIBS_ADDITIONAL = -lm -pthread -lsubunit -lrt
	ifeq ($(detected_Linux), Arch)
	LIBS_ADDITIONAL = -lm
	CMD_OPEN = xdg-open
	endif

	ifeq ($(detected_Linux), Ubuntu)
	LIBS_ADDITIONAL = -lm -pthread -lsubunit -lrt
	CMD_OPEN = xdg-open
	endif

	ifeq ($(detected_Linux), Debian)
	 LIBS_ADDITIONAL = -lm -pthread -lsubunit -lrt
	endif
endif

TST_LIBS = -lcheck $(LIBS_ADDITIONAL)

TESTS = tests/s21_matrix_test.c $(wildcard tests/test_suites/*.c)


SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
TEST_OBJECTS = $(patsubst %.c,%.o,$(TESTS))
MAIN_TEST_EXECUTABLE = s21_matrix

all: s21_matrix.a test gcov_report

debug: CFLAGS = -g -O0
debug: clean test

s21_matrix.a: $(OBJECTS)
	ar rcs $@ $^

gcov_report: test
	$(CC) $(FLAGS) --coverage $(SOURCES) $(TESTS) $(TST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	gcov *.gcda
	lcov -t "test" -o s21_matrix.info -c -d .
	genhtml -o ./report s21_matrix.info
	open report/index.html

rebuild: clean all

$(OBJECTS):
	gcc -c $(CFLAGS) $(patsubst %.o,%.c,$@) -o $@
	
$(TEST_OBJECTS):
	gcc -c $(CFLAGS) $(patsubst %.o,%.c,$@) -o $@

test: s21_matrix.a $(TEST_OBJECTS)	
	gcc $(TST_LIBS) $^ -o $(MAIN_TEST_EXECUTABLE)
	echo "RUNNING TESTS"
	./$(MAIN_TEST_EXECUTABLE)

leaks: test
	leaks -atExit -- ./s21_matrix
	make clean

clean:
	rm -f **/*.a **/*.o| true
	rm -f **/**/*.a **/**/*.o| true
	rm -f *.a *.o| true
	rm -r report | true
	rm *.info | true
	rm *.gcno | true
	rm *.gcov | true
	rm *.gcda | true
	rm gcov_test | true
	rm $(MAIN_TEST_EXECUTABLE) | true
	rm a.out | true

style:
	clang-format -n --style=google *.c *.h ./tests/*.c ./tests/*.h ./tests/test_suites/*.c
	clang-format -i --style=google *.c *.h ./tests/*.c ./tests/*.h ./tests/test_suites/*.c

.PHONY : all debug clean
