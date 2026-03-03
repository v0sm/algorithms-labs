CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = program
SRCS = main.c tree.c linked_list.c 
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

main.c: tree.h
linked_list.c: linked_list.h
tree.c: tree.h linked_list.h