SRCS	= $(shell /bin/ls *.cpp)
SRCS1	= $(shell /bin/ls int-stack?.cpp)
OBJS	= $(SRCS:.cpp=.o)
OBJS1	= $(SRCS1:.cpp=.o)
PROGS	= int-stack-test


$(PROGS): $(OBJS)
		g++ -o $@ $(OBJS)

$(SRCS):	int-stack.h 
$(SRCS1):	int-stack.h 

lib:	$(OBJS1)
	ar rsuv libintstack.a $(OBJS1)


clean:
	/bin/rm -f $(PROGS) $(OBJS) *~
