
OBJS = xldextract.o xld.o
CC = gcc
CFLAGS =
EXE = xldextract
RM = rm -f

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

xldextract.obj : xldextract.c
	$(CC) $(CFLAGS) xldextract.c 

xld.obj : ../../shared/xld.c
	$(CC) $(CFLAGS) ../../shared/xld.c 

clean:
	$(RM) $(OBJS)
	
reallyclean: clean
	$(RM) $(EXE)