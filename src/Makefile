CFLAGS = -c -Wall -Werror -Wextra  
LDFLAGS = -std=c11 -Wall -Werror -Wextra 
SOURCE = $(wildcard s21_*.c)
OBJECTS = $(patsubst %.c,%.o, ${SOURCE})
UNAME_S := $(shell uname -s)
NEW_TEST_SRC=$(wildcard ./s21_tests/*.c)

ifeq ($(UNAME_S),Linux)
  	OPEN_CMD = xdg-open
	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif
ifeq ($(UNAME_S),Darwin)
	OPEN_CMD = open
	ADD_LIB = -lcheck
endif

all: s21_matrix.a

s21_matrix.a: 
	@gcc $(CFLAGS) $(SOURCE)
	@ar rc $@ $(OBJECTS)
	@-rm -rf *.o
	ranlib s21_matrix.a

test: s21_matrix.a
	@gcc $(LDFLAGS) ${NEW_TEST_SRC}  s21_matrix.a -o test $(ADD_LIB)
	./test

leaks:
	CK_FORK=no leaks --atExit -- ./test

clean:
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./gcov_report
	-rm -fr report
	-rm -fr test
	-rm -rf *.txt

style:
	clang-format -style=Google -i *.c *.h */*.c */*.h
	cppcheck --enable=all --suppress=missingIncludeSystem ${SOURCE} ${NEW_TEST_SRC}
	
gcov_report:${SOURCE}
	@gcc --coverage ${SOURCE} ${NEW_TEST_SRC} -o test $(ADD_LIB) 
	./test
	@lcov -t "stest" -o s21_test.info -c -d .
	@genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html


.PHONY:	s21_matrix.a test prov valgrind
