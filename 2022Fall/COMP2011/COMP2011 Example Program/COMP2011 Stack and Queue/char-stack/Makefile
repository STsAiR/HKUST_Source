SRCS1	= $(shell /bin/ls char-stack?.cpp)
SRCS	= $(SRCS1) char-stack-test.cpp
OBJS1	= $(SRCS1:.cpp=.o)
OBJS	= $(SRCS:.cpp=.o)
PROGS	= char-stack-test


$(PROGS): $(lib) char-stack-test.o
		g++ -o $@  char-stack-test.o -L. -lcharstack

$(SRCS):	char-stack.h 
$(SRCS1):	char-stack.h 

lib:	$(OBJS1)
	ar rsuv libcharstack.a $(OBJS1)


clean:
	/bin/rm -f $(PROGS) $(OBJS) libcharstack.a *~
