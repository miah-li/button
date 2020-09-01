button:button.o
	gcc -o button button.o
button.o:button.c
	gcc -c button.c
button1:button1.o
	gcc -o button1 button1.o
button1.o:button1.c
	gcc -c button1.c
