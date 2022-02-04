#Antonio Maniscalco, Josh Sedig, Chase Jamieson
#CS460 
#Instructor: Dr. Xuechen Zhang
#Makefile

TARGET =  test my-cat 
FILES = test.c my-cat.c
LDLIBS = -lm
CFLAGS += -std=c99 -D_DEFAULT_SOURCE -Wall
RM = rm 

.PHONY: all clean

all: $(TARGET) $(FILES)

clean:
	$(RM) $(TARGET) 
