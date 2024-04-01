FLAGS=-Wall -Wextra -Werror -std=c11# -pedantic -fsanitize=address
LIBS=-lcheck
OS:=$(shell uname -s)
ifeq ($(OS), Darwin)
	FLAGS += -D MACOS
else
	LIBS += -lsubunit -lrt -lm -lpthread
endif

rebuild: clean all

all: test gcov_report

s21_string.a: s21_string.c
	gcc $(FLAGS) -c s21_string.c -o s21_string.o
	ar rc s21_string.a s21_string.o
	ranlib s21_string.a

test: s21_string.a test_s21_string.c
	gcc $(FLAGS) -c test_s21_string.c -o test_s21_string.o
	gcc $(FLAGS) test_s21_string.o s21_string.a $(LIBS) -o test
	./test

gcov_report:
	gcc $(FLAGS) -c s21_string.c --coverage -o s21_string.o
	gcc $(FLAGS) -c test_s21_string.c --coverage -o test_s21_string.o
	gcc $(FLAGS) test_s21_string.o s21_string.o --coverage $(LIBS) -o test
	./test
	gcovr -r . --html --html-details -o s21_string.html
	rm -rf *.gcda *.gcno

clean:
	rm -rf *.o *.a *.css *.html *.gcda *.gcno test CPPLINT.cfg cpplint.py

clf:
	clang-format -n --style=Google *.[ch]
cpk:
	cppcheck *.[ch]
cpl:
	cp ../materials/linters/CPPLINT.cfg ../materials/linters/cpplint.py ./
	python3 cpplint.py --extensions=c *.[ch]
	rm -rf CPPLINT.cfg cpplint.py

style: clf cpk cpl