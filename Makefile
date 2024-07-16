cc = gcc

all: c_vector_example.c c_vector.c c_vector.h
	$(cc) -o cvector c_vector.c c_vector.h c_vector_example.c
	
clear:
	rm -r cvector
