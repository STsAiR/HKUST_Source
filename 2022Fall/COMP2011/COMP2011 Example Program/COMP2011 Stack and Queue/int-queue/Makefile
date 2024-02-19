SRCS	= $(shell /bin/ls *.cpp)
SRCS1	= $(shell /bin/ls int-queue?.cpp)
OBJS	= $(SRCS:.cpp=.o)
OBJS1	= $(SRCS1:.cpp=.o)
PROGS	= int-queue-test


$(PROGS): $(OBJS)
		g++ -o $@ int-queue-test.o -L. -lintqueue

$(SRCS):	int-queue.h 
$(SRCS1):	int-queue.h 

lib:	$(OBJS1)
	ar rsuv libintqueue.a $(OBJS1)


clean:
	/bin/rm -f $(PROGS) $(OBJS) *~ libintqueue.a 
