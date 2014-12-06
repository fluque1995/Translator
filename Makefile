SRC = src
INCLUDE = include
OBJ = obj
BIN = bin
CC = g++
CPPFLAGS = -Wall -g  -I$(INC) -c
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)


all: $(BIN)/pruebatraductor
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de módulos ************
$(BIN)/pruebatraductor: $(OBJECTS)
	$(CC) -g -o $@ -I$(INCLUDE) $^


$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -g -I$(INCLUDE) -o $@ -c $<


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
