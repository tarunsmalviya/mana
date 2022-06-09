CC=cc
CFLAGS=-g3 -O0
LDFLAGS=-L$$PWD/../lib/dmtcp -lmpistub

all: mpi-cart-test mpi-comm-test

#========================

mpi-cart-test: mpi-cart-test.c
	${CC} ${CFLAGS} -o $@.mana.exe $< ${LDFLAGS}
	${CC} ${CFLAGS} -o $@.exe $<

mpi-comm-test: mpi-comm-test.c
	${CC} ${CFLAGS} -o $@.mana.exe $< ${LDFLAGS}
	${CC} ${CFLAGS} -o $@.exe $<

#========================

clean:
	rm -f *.exe
	rm -rf ckpt_rank_* dmtcp* cartesian.info core a.out > /dev/null 2>&1

#========================
