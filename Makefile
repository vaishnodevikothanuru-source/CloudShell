CC = gcc

CFLAGS = -Wall -Wextra -g -Iinclude

LDFLAGS = -pthread

SRC = \
	src/main.c \
	src/cloud.c \
	src/vm.c \
	src/storage.c \
	src/network.c \
	src/monitor.c

TARGET = bin/cloudadmin

all: $(TARGET)

$(TARGET):
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf bin
