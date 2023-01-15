OS := $(shell uname -s)
SRC =  smartcalc.c
SRC_FOR_TEST =  smartcalc.c
OBJ = $(SRC:%.c=%.o)

CC = gcc -std=c11

CFLAGS	= -Wall -Werror -Wextra 
FLAGS_PLATFORM = -lcheck

TEST = s21_calc_test.c
FLAGS_PLATFORM = -lcheck

GCOVFLAGS = -fprofile-arcs -ftest-coverage
REPORT = GcovReport

ifeq ($(OS), Darwin)
	FLAGS_PLATFORM = -lcheck
else
	FLAGS_PLATFORM = -lcheck -lsubunit -lrt -lm -lpthread -g
endif

.PHONY: all, install, uninstall, clean, dvi, dist, tests, gcov_report

all: install open

dvi:
	open dvi.html

test:
	@$(CC) $(CFLAGS) $(TEST) $(SRC_FOR_TEST) $(FLAGS_PLATFORM) -o tests.out
	@./tests.out

clean:
	@rm -rf *.{a,o,dSYM,out}
	@rm -rf $(EXECUTABLE)
	@rm -rf gcov_report
	@rm -rf report
	@rm -rf CPPLINT.cfg
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf test
	@rm -rf Archive_SmartCalc_v1.0
	@rm -rf *tgz
	@rm -rf gcov_test
	@rm -rf .clang-format

check: 
	@echo -------------------STYLE_TEST-------------------
	@cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extensions=c *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	@make leaks
	@rm -rf .clang-format

leaks:
	@echo -------------------MEMORY_TEST-------------------
	$(CC) -g $(TEST) $(SRC) $(FLAGS_PLATFORM) -o unit.out
	CK_FORK=no leaks --atExit -- ./unit.out

gcov_report:
	gcc $(GCOVFLAGS) $(TEST) $(SRC) $(FLAGS_PLATFORM) -o $(REPORT)
	chmod +x *
	./GcovReport
	lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
	genhtml -o report $(REPORT).info
	rm -rf ./*.gcno ./*.gcda ./$(REPORT).*
	open ./report/index.html
	rm $(REPORT)
	rm -rf *.dSYM

install:
	make clean
	cd ../ && mkdir build
	cd View && qmake6 && make && make clean && rm Makefile && mv SmartCalc_v1-0-0 ../../build/

open:
	cd ../build && ./SmartCalc_v1-0-0
	cd ../src

uninstall:
	@rm -rf ../build*

dist: 
	rm -rf ../Archive_SmartCalc_v1.0/
	mkdir ../Archive_SmartCalc_v1.0/
	cp -a ../build/* ../Archive_SmartCalc_v1.0
	cd ../ && tar -cvzf Archive_SmartCalc_v1.0.tar.gz Archive_SmartCalc_v1.0
	