BIN = bin
SRC = src
OBJECTS_CORE = glad.o engine.o inputmanager.o camera.o statemanager.o renderer.o shadermanager.o windowmanager.o \
				assets/asset.o assets/mesh.o assets/geometry.o \
				scenegraph/scenegraph.o scenegraph/scenenode.o scenegraph/scenenodegeometry.o
DIRECTORIES = assets scenegraph
OBJECTS_CLIENT = main.o game.o 

MKDIR_P = mkdir -p

# The flags to use for compilation
CXXFLAGS = -Wall -m64 -std=c++14
# The code compiler to use for compilation
CC = g++

INC = -I/usr/local/include -Ilibs/glfw-3.2.1/include -Ilibs/glm -Ilibs/glad/include -Isrc
LIB = -L/usr/lib64/ -L/usr/local/lib64/
DEPS = -lglfw3 -lGL -pthread -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -ldl -lXcursor

LIST_DIRECTORIES=$(addprefix $(BIN)/, $(DIRECTORIES))
LIST_CORE=$(addprefix $(BIN)/, $(OBJECTS_CORE))
LIST_CLIENT=$(addprefix $(BIN)/, $(OBJECTS_CLIENT))

.PHONY: all clean directories

#######################################
# Final program
#######################################
all: directories $(BIN)/client.exe

$(BIN)/client.exe: $(LIST_CLIENT) $(BIN)/core.o
	$(CC) $(CXXFLAGS) -o $@ $^ $(INC) $(LIB) $(DEPS)
#######################################
# Core build
#######################################
$(BIN)/glad.o: libs/glad/src/glad.c
	$(CC) $(CXXFLAGS) -c -Ilibs/glad/include $< -o $@ $(LIB)
$(BIN)/core.o: $(LIST_CORE)
	ld -r -o $@ $^
$(BIN)/%.o: $(SRC)/core/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INC) $(LIB)
#######################################
# Client build
#######################################
$(BIN)/%.o: $(SRC)/client/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INC) $(LIB)
#######################################
# Clean
#######################################
clean:
	rm -rf $(BIN)/*
directories: ${LIST_DIRECTORIES}

${LIST_DIRECTORIES}:
	${MKDIR_P} $@
