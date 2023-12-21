G++ = g++ -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lgtest -pthread
TEST_SRC = *.cc
TEST_NAME = test

all: clean test

test: 
	$(G++) $(CHECKFLAGS) */*$(TEST_SRC) -o $(TEST_NAME) $(TEST_LIBS) -g
	./$(TEST_NAME)

clean:
	rm -rf *.o *.a a.out *.css *.html gcov_test *.gcda *.gcno $(NAME_EXE) info gcovreport.info report test.dSYM test

gcov_report: clean
	$(G++) $(CHECKFLAGS) */*$(TEST_SRC) $(TEST_LIBS) -coverage -o gcov_test
	./gcov_test
	gcovr -r . --html --html-details -o containers.html
	open ./containers.html

format: 
	clang-format -style=google -i */*.cc
	clang-format -style=google -i */*.h

clang-format: 
	clang-format -style=google -n */*.cc
	clang-format -style=google -n */*.h

html:
	open ../documentation/html/index.html
	open ../documentation/map_documentation/html/annotated.html
	open ../documentation/vector_documentation/html/annotated.html

fsanitize: 
	$(G++) */*$(TEST_SRC) $(CHECKFLAGS) -g -fsanitize=address $(TEST_LIBS) -o $(TEST_NAME) 
	./$(TEST_NAME)

valgrind: test
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TEST_NAME)
