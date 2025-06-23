CC = gcc
CFLAGS = -w
TARGET = myshell

all: $(TARGET)

$(TARGET): myshell.c utility.c myshell.h
	$(CC) $(CFLAGS) myshell.c utility.c -o $(TARGET)
	./myshell

clean:
	rm -f $(TARGET)
