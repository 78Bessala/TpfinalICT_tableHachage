Produit: function_bessala_23V2531.c function_bessala_23V2531.h main_function_bessala_23V2531.c
	gcc -o Produit function_bessala_23V2531.c main_function_bessala_23V2531.c -g -O0 -lm -lpthread -fopenmp 

run:Produit
	./Produit
run_valgrind:Produit
	valgrind  --tool=memcheck --leak-check=yes --leak-resolution=low --show-reachable=yes  ./Produit
clean:
	rm  Produit

profile:
	gcc -Wall -pg function_bessala_23V2531.c main_function_bessala_23V2531.c -lm -lpthread -o Produit