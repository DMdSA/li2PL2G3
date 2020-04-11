gcc -c logicaPrograma.c
gcc -c interfacePrograma.c
gcc -c camadaDados.c
gcc -c main.c

gcc -o a logicaPrograma.o interfacePrograma.o camadaDados.o main.o
a.exe