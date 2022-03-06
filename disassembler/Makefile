CC=cc -g --std=c11 -I./include -c
C_FILES=$(wildcard source/*.c)
O_FILES=$(wildcard build/*.o)
.PHONY: prep

all: build

build: compile
	@-cc $(O_FILES) -o ./disas

clean:
	@-[ -f disas ] && rm disas || exit 0;
	@-[ -d build ] && rm -r build || exit 0;

compile: prep
	@-for f in $(C_FILES); do \
		$(CC) $$f -o build/`basename $$f`.o; \
	done;

prep:
	@-[ ! -d build ] && mkdir build || rm build/*;