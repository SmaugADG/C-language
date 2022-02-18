OBJS=main.o tool1.o tool2.o
CC=gcc
CFLAGS+=-c -Wall -g

mytool:$(OBJS)
	$(CC) $(OBJS) -o $@
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@
clean:
	$(RM) *.o mytool -r
