BIN = bin
SRC = src
OBJECTS_CORE = engine.o inputmanager.o camera.o statemanager.o renderer.o shadermanager.o windowmanager.o scenegraph.o scenenode.o glad.o
OBJECTS_CLIENT = main.o game.o 
# The flags to use for compilation
CXXFLAGS = -Wall -m64 -std=c++14
# The code compiler to use for compilation
CC = g++

INC = -I/usr/local/include -Ilibs/glfw-3.2.1/include -Ilibs/glm -Ilibs/glad/include -Isrc
LIB = -L/usr/lib64/ -L/usr/local/lib64/
DEPS = -lglfw3 -lGL -pthread -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -ldl -lXcursor

LIST_CORE=$(addprefix $(BIN)/, $(OBJECTS_CORE))
LIST_CLIENT=$(addprefix $(BIN)/, $(OBJECTS_CLIENT))

#######################################
# Final program
#######################################
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
	rm -f $(BIN)/* ./core.client.exe.*
