SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
LIB=libvmatrix.a
CFLAGS=-I../include -g

vmatrix.a: $(OBJ)
	ar r $(LIB) $(OBJ)

clean:
	rm -f $(OBJ) $(LIB)

