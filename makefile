CXX = g++
C++_VERSION = c++11
CXXFLAGS = -std=$(C++_VERSION) -Wall -w -m64# -static-libgcc -static-libstdc++

OUT_DIR = bin
LAUNCHER_NAME = ResearchEngine
SRC_DIR = src
ENTRY_POINT = src/Res/main.cpp

#Libs
GLAD_ROOT = extern/glad/
GLAD_INC = $(GLAD_ROOT)include
GLAD_SRC = $(GLAD_ROOT)src

GLFW_ROOT = extern/glfw-3.3.2/MinGWmingw32/
GLFW_INC = $(GLFW_ROOT)include
GLFW_LIB = $(GLFW_ROOT)lib
GLFW_SRC = $(GLFW_ROOT)../src

GLM_ROOT = extern/glm/

STBIMAGE_ROOT = extern/stbimage

INC= -I $(SRC_DIR) -I $(GLFW_INC) -I $(STBIMAGE_ROOT) -I $(GLM_ROOT) -I $(GLAD_INC)
LIBS = -L $(GLFW_LIB)
LINKS = -lglfw3 -lgdi32

#========================OBJECTS========================#
CORE_OBJS = $(OUT_DIR)/EngineCore.o 
STARTUP_OBJS = $(OUT_DIR)/StartupSystem.o 
RENDERING_OBJS = $(OUT_DIR)/ShaderProgram.o $(OUT_DIR)/Window.o
FILE_OBJS = $(OUT_DIR)/FileLoaderFactory.o
OBJS = $(CORE_OBJS) $(ENGINE_CORE_OBJS) $(RENDERING_OBJS) $(FILE_OBJS) $(STARTUP_OBJS)


ALL_SETTINGS = $(CXX) $(CXXFLAGS) $(LIBS) $(INC)  
DEBUG_FLAGS = -DDEBUG_MODE -g -O5
RELEASE_FLAGS = -DRELEASE_MODE -O3
all: debug


debug: ALL_SETTINGS = $(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(LIBS) $(INC)  
debug: executable
 
release: ALL_SETTINGS = $(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) $(LIBS) $(INC)
release: executable

linux: LINKS = -lglfw3 -ldl
linux: executable
linux: chmod 777 bin/*
linux: run

executable: $(ENTRY_POINT) $(OBJS)
	$(ALL_SETTINGS) -o $(OUT_DIR)/$(LAUNCHER_NAME) $^ $(GLAD_SRC)/glad.c $(LINKS)
	./$(OUT_DIR)/$(LAUNCHER_NAME).exe

run:
	./$(OUT_DIR)/$(LAUNCHER_NAME).exe

$(CORE_OBJS): $(OUT_DIR)/%.o: src/Res/Cores/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  

$(RENDERING_OBJS): $(OUT_DIR)/%.o: src/Res/Rendering/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  

$(FILE_OBJS): $(OUT_DIR)/%.o: src/Res/Tools/Files/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  

$(STARTUP_OBJS): $(OUT_DIR)/%.o: src/Res/Tools/Startup/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  

  
