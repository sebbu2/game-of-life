CC=gcc
FLAGS=-W -Wall -Wextra -Werror -ansi -pedantic -pedantic-errors
CFLAGS=$(FLAGS) -std=c99
CPPFLAGS=-g
TARGET_ARCH=-march=native -mtune=native
LD=ld
LDFLAGS=-Wl,--enable-auto-import
TARGET_ARCH:=$(TARGET_ARCH)
LIBS=
LOADLIBES=
LDLIBS=

all: exo322_main.exe exo323_main.exe exo324_conway.exe exo324_fredkin.exe exo33_main.exe exo33_fredkin.exe exo41_main.exe exo41_silverman.exe exo42_seeds.exe

exo322_main.exe: common.o exo321.o exo322.o exo322_main.o
exo323_main.exe: common.o exo321.o exo322.o exo323.o exo323_main.o
exo324_conway.exe: common.o exo321.o exo322.o exo323.o exo324.o exo324_conway.o
exo324_fredkin.exe: common.o exo321.o exo322.o exo323.o exo324.o exo324_fredkin.o
exo33_main.exe: common.o exo321.o exo322.o exo323.o exo33.o exo33_main.o
exo33_fredkin.exe: common.o exo321.o exo322.o exo323.o exo33.o exo33_fredkin.o
exo41_main.exe: common.o exo321.o exo322.o exo323.o exo41.o exo41_main.o
exo41_silverman.exe: common.o exo321.o exo322.o exo323.o exo41.o exo41_silverman.o
exo42_seeds.exe: common.o exo321.o exo322.o exo323.o exo41.o exo42.o exo42_seeds.o
%.exe: %.o
	$(CC) $(LDFLAGS) $(TARGET_ARCH) -o $@ $(filter %.o,$^)
