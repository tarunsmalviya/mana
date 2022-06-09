CC=cc
CFLAGS=-g -L/global/homes/m/malviyat/projects/mana/lib/dmtcp -lmpistub

all: mpi-cart-test mpi-comm-test

#========================

mpi-cart-test: mpi-cart-test.c
	${CC} ${CFLAGS} -o $@ $<

mpi-comm-test: mpi-comm-test.c
	${CC} ${CFLAGS} -o $@ $<

#========================

clean:
	rm -f mpi-cart-test mpi-comm-test
	rm -rf ckpt_rank_* dmtcp* cartesian.info core a.out > /dev/null 2>&1

#========================
