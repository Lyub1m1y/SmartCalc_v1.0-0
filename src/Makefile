.PHONY: all, install, uninstall, clean, dvi, dist, tests, gcov_report

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


all: install open

install:
	@make clean
	@cd View && qmake6 && make && make clean && rm Makefile && mv SmartCalc_v1-0-0 ../

uninstall:
	@rm -rf SmartCalc_v1-0-0

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
	@rm -rf *tgz
	@rm -rf gcov_test
	@rm -rf .clang-format
	@rm -rf ../Archive_SmartCalc_v1.0.*

dvi:
	open ./help/index.html


dist: 
	rm -rf ../Archive_SmartCalc_v1.0/
	mkdir ../Archive_SmartCalc_v1.0/
	cp -a -r **/ *.* Makefile SmartCalc_v1-0-0 ../Archive_SmartCalc_v1.0
	cd ../ && tar -cvzf Archive_SmartCalc_v1.0.tar.gz Archive_SmartCalc_v1.0

test:
	@$(CC) $(CFLAGS) $(TEST) $(SRC_FOR_TEST) $(FLAGS_PLATFORM) -o tests.out
	@./tests.out

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

open:
	./SmartCalc_v1-0-0

check: 
	@echo -------------------STYLE_TEST-------------------
	@cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extensions=c **/*.c
	clang-format -style=Google -n **/*.c
	# cppcheck --enable=all --suppress=missingIncludeSystem **/*.c
	# @make leaks

leaks:
	@echo -------------------MEMORY_TEST-------------------
	$(CC) -g $(TEST) $(SRC) $(FLAGS_PLATFORM) -o unit.out
	CK_FORK=no leaks --atExit -- ./unit.out
