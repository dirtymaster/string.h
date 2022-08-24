CC+FLAGS = gcc -std=c11 -Wall -Wextra -Werror
GCOVFLAGS = -L. -ls21_string --coverage
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck
endif

TEST_COMPILE = $(CC+FLAGS) tests.c libs21_string.a $(CHECK_FLAGS) -L. -ls21_string

all: clean s21_string.a test

clean:
	rm -rf *.o *.g* *.info *.out report *.a *.dSYM

rebuild: clean all

test: s21_string.a
	$(TEST_COMPILE)
	./a.out

gcov_report: s21_string.a test
	rm -f *.g*
	$(CC+FLAGS) s21*.c tests.c libs21_string.a $(CHECK_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno s21_tests s21_tests.info

s21_string.a: s21_string.o
	ar rcs libs21_string.a *.o
	rm -rf *.o
	ranlib libs21_string.a
	cp libs21_string.a s21_string.a
	cp libs21_string.a ls21_string.a

s21_string.o:
	$(CC+FLAGS) -c s21*.c

lo:
	for i in `seq 100 $(OP)`;	do ./a.out; done;

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./a.out
else
	valgrind ./a.out --leak-check=full
endif
	make clean