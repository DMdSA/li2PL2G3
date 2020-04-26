gcc -c logicaPrograma.c
gcc -c interfacePrograma.c
gcc -c camadaDados.c
gcc -c lista.c
gcc -c main.c

gcc -o diogo logicaPrograma.o interfacePrograma.o camadaDados.o main.o lista.o
