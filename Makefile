CC=clang
CFLAGS=-Wall

SRC=src
INC=include
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
HDRS=$(wildcard $(INC)/*.h)
OBJS=$(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))

TESTDIR=tests
TESTS=$(wildcard $(TESTDIR)/*.c)
TESTBIN=$(patsubst $(TESTDIR)/%.c,$(TESTDIR)/bin/%,$(TESTS))
CMOCKA_INC=/opt/homebrew/include/
CMOCKA_LIB=/opt/homebrew/lib/

BINDIR=bin
BIN=app

all: $(BIN) test

$(BIN): $(BINDIR) main
	$(CC) $(CFLAGS) $(OBJ)/*.o -o $(BINDIR)/$@

$(BINDIR):
	mkdir $@

$(OBJ):
	mkdir $@

main: $(OBJ) $(OBJS)
	$(CC) $(CFLAGS) -c main.c -o $(OBJ)/main.o

test: $(OBJ) $(OBJS) $(TESTDIR)/bin $(TESTBIN)

run-test: test
	for test in $(TESTBIN) ; do ./$$test ; done

$(TESTDIR)/bin/%: $(TESTDIR)/%.c
	$(CC) $(CFLAGS) $^ $(OBJS) -o $@ -I$(CMOCKA_INC) -L$(CMOCKA_LIB) -lcmocka

$(TESTDIR)/bin:
	mkdir $@

$(OBJ)/%.o: $(SRC)/%.c $(INC)/%.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -r $(BINDIR)/* $(OBJ)/* $(TESTDIR)/bin/*
