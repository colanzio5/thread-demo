CC=g++ # define the compiler to use
TARGET=thread # define the name of the executable
SOURCES=thread_demo.c worker.c
CFLAGS=-O3
LFLAGS=

# define list of objects
OBJSC=$(SOURCES:.c=.o)
OBJS=$(OBJSC:.cpp=.o)

# the target is obtained linking all .o files
all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -pthread $(LFLAGS) $(OBJS) -o $(TARGET)

purge: clean
	rm -f $(TARGET)

clean:
	rm -f *.o