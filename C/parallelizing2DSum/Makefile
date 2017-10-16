CC=gcc
CFLAGS = -fopenmp 
all: Cache_Examples

Cache_Examples: cache_hits test cache_hits_nonPar

clean:
	rm test cache_hits cache_hits_nonPar


cache_hits: cache_hits.c

cache_hits_nonPar:cache_hits_nonPar.c

test: test.c
