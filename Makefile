COMP = gcc
FLAG = -Wall -g
LIB  = `sdl2-config --cflags --libs` -lSDL2_gfx

SRC_DIR = src
SRC_FILES = Vector2 Node Node_disp Box main main_disp main_node main_mouse

SRC    = $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(SRC_FILES)))
OUTPUT = bin/pointer-helper

$(OUTPUT): $(SRC)
	$(COMP) $(FLAG) $(SRC) -o $(OUTPUT) $(LIB)