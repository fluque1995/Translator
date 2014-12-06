SRC = src
INCLUDE = include
OBJ = obj
BIN = bin
CC = g++
CPPFLAGS = -Wall -g  -I$(INC) -c
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)
MAINOBJS = $(OBJ)/word.o $(OBJ)/translator.o

all: $(BIN)/traductor $(BIN)/inverse_trad $(BIN)/composed_trad $(BIN)/intersect_trad

# ************ Generación de documentación ******************
documentacion:
	
	doxygen doc/doxys/Doxyfile > /dev/null
	
# ************ Compilación de módulos ************
$(BIN)/traductor: $(OBJ)/traductor.o $(MAINOBJS)
	
	$(CC) -g -o $@ -I$(INCLUDE) $^

$(BIN)/inverse_trad: $(OBJ)/inverse_trad.o $(MAINOBJS)
	
	$(CC) -g -o $@ -I$(INCLUDE) $^

$(BIN)/composed_trad: $(OBJ)/composed_trad.o $(MAINOBJS)
	
	$(CC) -g -o $@ -I$(INCLUDE) $^

$(BIN)/intersect_trad: $(OBJ)/intersect_trad.o $(MAINOBJS)
	
	$(CC) -g -o $@ -I$(INCLUDE) $^

$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.cpp
	
	$(CC) -g -I$(INCLUDE) -o $@ -c $<


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* 

mrproper : clean
	-rm $(BIN)/* doc/html/*
