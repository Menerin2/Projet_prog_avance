CC = gcc
CFLAGS = -W -Wall -ansi -std=c99 -g -I./include
LDFLAGS = `sdl2-config --cflags --libs ` -lSDL2_ttf -lSDL2_image
LIBS = -L./SDL2_ttf/.libs -L./SDL2_image/.libs
RM = rm -rf
EXEC = dyno
SRC = $(shell find src -type f -name "*.c")
OBJ = $(SRC:.c=.o)

all: $(EXEC)
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
clean:
	$(RM) $(shell find . \( -name "#*#" -o -name "*~" -o -name "*.o" \) -delete)
fclean: clean
	$(RM) $(EXEC)
re:	fclean all