CC = g++
TEST_OUT = test.out


test: ctest rtest
	@echo "Test success"

ctest:
	@echo "Compiling tests..."
	${CC} test.cpp ./monkey/*.cpp -o ${TEST_OUT}

rtest: 
	@echo "Running tests..."
	./${TEST_OUT}