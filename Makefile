CC=gcc
CFLAGS=-Wall -pedantic -lpthread
BIN=graph-kun
OBJ=sqlite3.o

all: sqlite3.o
	g++ src/main.cpp src/graphWindow.cpp src/graphSQL.cpp sqlite3.o -o graph-kun -Iinclude -Llib -lraylib -lgdi32 -lwinmm

sqlite3.o:
	${CC} ${CFLAGS} -c include/sqlite3.c -o $@

format:
	clang-format -i --verbose include/main.c
