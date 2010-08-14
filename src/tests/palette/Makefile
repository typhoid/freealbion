
OBJS = palettetest.o xld.o
CC = gcc
CFLAGS = -c
EXE = palettetest
RM = rm -f

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

palettetest.o : palettetest.c
	$(CC) $(CFLAGS) palettetest.c 

xld.o : ../../shared/xld.c
	$(CC) $(CFLAGS) ../../shared/xld.c 

clean:
	$(RM) $(OBJS)
	
reallyclean: clean
	$(RM) $(EXE)
