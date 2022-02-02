#Antonio Maniscalco
#CS460 
#Instructor: Dr. Xuechen Zhang
#Makefile

TARGET =  my-cat my-cat.c my-sed my-sed.c my-uniq my-uniq.c
LDLIBS = -lm
CFLAGS += -std=c99 -D_DEFAULT_SOURCE -Wall
RM = rm -f
JUNK=*.o *~ *.dSYM

.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(JUNK)