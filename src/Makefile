.PHONY: all install uninstall clean dvi dist test gcov_report check

OS := $(shell uname -s)
SRC =  Model/smartcalc.c
SRC_FOR_TEST =  Model/smartcalc.c
OBJ = $(SRC:%.c=%.o)

CC = gcc -std=c11

# CFLAGS	= -Wall -Werror -Wextra
CFLAGS	=
FLAGS_PLATFORM = -lcheck

TEST = Test/test_smartcalc.c
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
ifeq ($(OS), Darwin)
	@cd View && qmake6 && make && make clean && rm Makefile && mv SmartCalc_v1-0-0.app/Contents/MacOS/SmartCalc_v1-0-0 ../
else
	@cd View && qmake6 && make && make clean && rm Makefile && mv SmartCalc_v1-0-0 ../
endif

uninstall:
	@rm -rf SmartCalc_v1-0-0

	
clean:
	@rm -rf *.{a,dSYM,out}
	@rm -rf **/**.o **.o
	@rm -rf $(EXECUTABLE)
	@rm -rf gcov_report
	@rm -rf report
	@rm -rf CPPLINT.cfg
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf test.out
	@rm -rf *tgz
	@rm -rf gcov_test
	@rm -rf .clang-format
	@rm -rf ../Archive_SmartCalc_v1.0.*
	@rm -rf build-SmartCalc_v1-0-0-Desktop-Release/
	@rm -rf build-SmartCalc_v1-0-0-Desktop_x86_darwin_generic_mach_o_64bit-Debug
	@rm -rf **/moc_predefs.h
	@rm -rf **/smartcalc
	@rm -rf **/SmartCalc_v1-0-0
	@rm -rf View/SmartCalc_v1-0-0.app
	@rm -rf **/smartcalc.dSYM
	@rm -rf GcovReport

dvi:
	open ./Help/index.html


dist: 
	rm -rf ../Archive_SmartCalc_v1.0/
	mkdir ../Archive_SmartCalc_v1.0/
	cp -a -r **/ *.* Makefile SmartCalc_v1-0-0 ../Archive_SmartCalc_v1.0
	cd ../ && tar -cvzf Archive_SmartCalc_v1.0.tar.gz Archive_SmartCalc_v1.0

test:
	@$(CC) $(CFLAGS) $(TEST) $(SRC_FOR_TEST) $(FLAGS_PLATFORM) -o test.out
	@./test.out

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
	@rm -rf CPPLINT.cfg
