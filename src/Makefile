PROGS=vmatrixcat vmatrixmul vmatrixreduce
CFLAGS=-I../include -g
LDFLAGS=-L../lib -lvmatrix -g
BIN=../bin

all: $(PROGS)

install: all
	cp $(PROGS) $(BIN)

vmatrixcat: vmatrixcat.o
	$(CC) -o $@ $^ $(LDFLAGS)

vmatrixmul: vmatrixmul.o
	$(CC) -o $@ $^ $(LDFLAGS)

vmatrixreduce: vmatrixreduce.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(PROGS) *.o

