CC = g++
MAIN_OUT = main.out
TEST_OUT = test.out

crepl:
	@echo "Compiling main..."
	${CC} main.cpp ./monkey/*.cpp	-o ${MAIN_OUT}

rrepl: 
	./${MAIN_OUT}

repl: crepl rrepl

test: ctest rtest
	@echo "Test success"

ctest:
	@echo "Compiling tests..."
	${CC} test.cpp ./monkey/*.cpp -o ${TEST_OUT}

rtest: 
	@echo "Running tests..."
	./${TEST_OUT}