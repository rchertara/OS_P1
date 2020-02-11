syscall:
	gcc -g syscall.c -o syscall

signal:
    gcc -g signal.c -o signal

thread:
    gcc -g threads.c -o threads -lpthread

clean:
    rm -rf threads syscall signal