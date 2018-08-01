#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp src/cpu.cpp src/mmu.cpp src/debugger.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2_ttf -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = c64_emu

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run: all
	./$(OBJ_NAME)