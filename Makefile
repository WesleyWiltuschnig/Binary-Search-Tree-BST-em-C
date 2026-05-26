CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11
TARGET  = bst
SRCS    = main.c insercao.c busca.c remocao.c remocao_arvore.c travessias.c
OBJS    = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c arvore.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
