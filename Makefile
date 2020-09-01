button:button.o
	gcc -o button button.o
button.o:button.c
	gcc -c button.c
