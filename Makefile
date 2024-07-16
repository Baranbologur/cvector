cc = gcc

all: cvector_deneme.c c_dynamic_vector.c c_dynamic_vector.h
	$(cc) -o cvector c_dynamic_vector.c c_dynamic_vector.h cvector_deneme.c
	
clear:
	rm -r cvector
