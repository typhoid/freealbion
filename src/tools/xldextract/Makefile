
OBJS = xldextract.o xld.o
CC = gcc
CFLAGS = -c
EXE = xldextract
RM = rm -f

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

xldextract.o : xldextract.c
	$(CC) $(CFLAGS) xldextract.c 

xld.o : ../../shared/xld.c
	$(CC) $(CFLAGS) ../../shared/xld.c 

clean:
	$(RM) $(OBJS)
	
reallyclean: clean
	$(RM) $(EXE)
