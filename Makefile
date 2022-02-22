CC = g++
CPPFLAGS = -g -std=c++17
DEPS := main.o  ProcessData.o Colors.o ListFiles.o
BUILD_DIR ?= ./bin
TARGET_BUILD ?= codestat


$(BUILD_DIR)/$(TARGET_BUILD): $(DEPS)
	${CC} $(BUILD_DIR)/main.o $(BUILD_DIR)/ProcessData.o $(BUILD_DIR)/Colors.o  $(BUILD_DIR)/ListFiles.o -o codestat
	
main.o: main.cpp
	@mkdir -p ./bin
	$(CC) $(CPPFLAGS) -c main.cpp -o $(BUILD_DIR)/main.o

ProcessData.o: ProcessData.cpp include/ProcessData.h
	@mkdir -p ./bin
	$(CC) $(CPPFLAGS) -c ProcessData.cpp -o $(BUILD_DIR)/ProcessData.o

Colors.o: Colors.cpp include/Colors.h
	@mkdir -p ./bin
	$(CC) $(CPPFLAGS) -c Colors.cpp -o $(BUILD_DIR)/Colors.o

ListFiles.o: ListFiles.cpp include/ListFiles.h
	@mkdir -p ./bin
	$(CC) $(CPPFLAGS) -c ListFiles.cpp -o $(BUILD_DIR)/ListFiles.o

clean:
	rm -rf ./bin
	rm codestat
