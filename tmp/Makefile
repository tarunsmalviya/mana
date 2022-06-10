CC=cc
MPICC=mpicc
CFLAGS=-g3 -O0
LDFLAGS=-L$$PWD/../lib/dmtcp -lmpistub

all: mpi-cart-test mpi-comm-test

#========================

mpi-cart-test: mpi-cart-test.c
	${CC} ${CFLAGS} -o $@.mana.exe $< ${LDFLAGS}
	${MPICC} ${CFLAGS} -o $@.exe $<

mpi-comm-test: mpi-comm-test.c
	${CC} ${CFLAGS} -o $@.mana.exe $< ${LDFLAGS}
	${MPICC} ${CFLAGS} -o $@.exe $<

#========================

tidy:
	rm -rf ckpt_rank_* dmtcp* cartesian.info core a.out > /dev/null 2>&1

clean: tidy
	rm -f *.exe

#========================
