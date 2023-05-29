CFLAGS = $(shell pkg-config --cflags glib-2.0)
CLIBS = $(shell pkg-config --libs glib-2.0)

IDIR = ../lib
CXXFLAGS += -I$(IDIR)

# Directory di destinazione per i file oggetto
OBJ_DIR = build

# Lista dei file oggetto
OBJ_FILES = $(OBJ_DIR)/main.o $(OBJ_DIR)/file_operations.o $(OBJ_DIR)/chunk_operations.o $(OBJ_DIR)/file_print_operations.o $(OBJ_DIR)/lexer_functions.o $(OBJ_DIR)/word_processing.o

all: create_build_dir $(OBJ_FILES)
	mpicc $(OBJ_FILES) -o word_count.out $(CFLAGS) $(CLIBS)

$(OBJ_DIR)/main.o: main.c
	mpicc $(CXXFLAGS) -c $< -o $@ $(CFLAGS) $(CLIBS)

$(OBJ_DIR)/file_print_operations.o: file_print_operations.c
	mpicc $(CXXFLAGS) -c $< -o $@ $(CFLAGS) $(CLIBS)

$(OBJ_DIR)/lexer_functions.o: lexer_functions.c
	mpicc $(CXXFLAGS) -c $< -o $@ $(CFLAGS) $(CLIBS)

$(OBJ_DIR)/file_operations.o: file_operations.c
	mpicc $(CXXFLAGS) -c $< -o $@ $(CFLAGS) $(CLIBS)

$(OBJ_DIR)/chunk_operations.o: chunk_operations.c
	mpicc $(CXXFLAGS) -c $< -o $@ $(CFLAGS) $(CLIBS)

$(OBJ_DIR)/word_processing.o: word_processing.c
	mpicc $(CXXFLAGS) -c $< -o $@ $(CFLAGS) $(CLIBS)

create_build_dir:
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) word_count.out output.txt ../*.txt
