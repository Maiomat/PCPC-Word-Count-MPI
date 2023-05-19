CFLAGS = $(shell pkg-config --cflags glib-2.0)
CLIBS = $(shell pkg-config --libs glib-2.0)

compile:
		mkdir -p build
		mpicc main.c -o build/main.out

clean:
		rm -rf build