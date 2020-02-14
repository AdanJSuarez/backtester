# Make file. You just need to type "make" in root directory and wait for the magic!

CXX=g++
CXXFLAGS=-std=c++17 -Wall -Weffc++ -Wextra -Wsign-conversion -Wno-switch
BASE_SRC_DIR=src
INCLUDES=-I${BASE_SRC_DIR}
TARGET=main
# Test
TEST=test
CXX_TEST_FLAGS=-std=c++17
BASE_TEST_DIR=test

all: $(TARGET) run_tests done

$(TARGET):
	@echo "- Compiling and linking C++ files:"
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(BASE_SRC_DIR)/*.cpp $(BASE_SRC_DIR)/*/*.cpp -o bin/$(TARGET)
	@echo " "
	@echo "- Cleaning:"
	rm -f $(TARGET) *.o
	rm -f bin/$(TEST)*
	@echo " "
	@echo "- Compiling and linking tests:"
	$(CXX) $(CXX_TEST_FLAGS) $(BASE_TEST_DIR)/*/*.cpp $(BASE_SRC_DIR)/*/*.cpp -o bin/$(TEST)

run_tests:
	@echo " "
	@echo "- Running tests"
	bin/$(TEST)

done:
	@echo "Done!"
