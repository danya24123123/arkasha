.PHONY: all clean install uninstall



all: hello

clean:
		del /Q hello.exe *.o
main.o: main.c
		gcc -c -o main.o main.c
queue.o: queue.c
		gcc -c -o queue.o queue.c
hello: main.o queue.o
		gcc -o hello main.o queue.o
install:
		copy hello.exe C:\Windows\System32
uninstall:
		del /Q C:\Windows\System32\hello.exe