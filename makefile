# Compilação principal
all: ex1_2 ex3

# ========= EX1_2 =========
ex1_2: ex1_2/packages.o ex1_2/package_trees.o ex1_2/trees.o
	gcc -Wall -Wextra ex1_2/main.c ex1_2/packages.o ex1_2/package_trees.o ex1_2/trees.o -o ex1_2/ex1_2.out

ex1_2/packages.o: ex1_2/packages.c ex1_2/packages.h
	gcc -c ex1_2/packages.c -o ex1_2/packages.o

ex1_2/package_trees.o: ex1_2/package_trees.c ex1_2/package_trees.h
	gcc -c ex1_2/package_trees.c -o ex1_2/package_trees.o

ex1_2/trees.o: ex1_2/trees.c ex1_2/trees.h
	gcc -c ex1_2/trees.c -o ex1_2/trees.o

# ========= EX3 =========
ex3: ex3/trees.o ex3/vetor.o
	gcc -Wall -Wextra -std=c99 ex3/main.c ex3/trees.o ex3/vetor.o -o ex3/ex3.out

ex3/trees.o: ex3/trees.c ex3/trees.h
	gcc -c ex3/trees.c -o ex3/trees.o

ex3/vetor.o: ex3/vetor.c ex3/vetor.h
	gcc -c ex3/vetor.c -o ex3/vetor.o

# Alvos que não são arquivos
.PHONY: all clean run_ex1_2 run_ex3 help

# Limpeza (Windows ou Unix)
clean:
	@echo "Limpando arquivos..."
	@del /Q ex1_2\*.o ex3\*.o ex1_2\*.out ex3\*.out 2>NUL || rm -f ex1_2/*.o ex3/*.o ex1_2\*.out ex3\*.out

# Execuções
run_ex1_2: ex1_2
	@echo "Executando ex1_2..."
	@./ex1_2/ex1_2.out

run_ex3: ex3
	@echo "Executando ex3..."
	@./ex3/ex3.out

# Ajuda
help:
	@echo
	@echo "Comandos disponiveis:"
	@echo "  make           => Compila tudo"
	@echo "  make ex1_2     => Compila apenas o ex1_2"
	@echo "  make ex3       => Compila apenas o ex3"
	@echo "  make run_ex1_2 => Roda o ex1_2"
	@echo "  make run_ex3   => Roda o ex3"
	@echo "  make help      => Exibe comandos"
	@echo "  make clean     => Limpa arquivos compilados"
