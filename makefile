CXX = g++
C++_VERSION = c++17
CXXFLAGS = -std=$(C++_VERSION) -Wall -w -g -static-libgcc -static-libstdc++

OUT_DIR = bin
LAUNCHER_NAME = ResearchEngine
SRC_DIR = src
ENTRY_POINT = src/main.cpp

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

INC= -I $(SRC_DIR) -I $(GLFW_INC) -I $(STBIMAGE_ROOT) -I $(GLM_ROOT)
LIBS = -L $(GLFW_LIB)
LINKS = -lglfw3 -lgdi32 -lpthread

#========================OBJECTS========================#
CORE_OBJS = $(OUT_DIR)/EngineCore.o
OBJS = $(CORE_OBJS) $(ENGINE_CORE_OBJS) $(RENDERING_OBJS) $(STARTUP_OBJS) $(TOOLS_OBJS)


ALL_SETTINGS = $(CXX) $(CXXFLAGS) $(LIBS) $(INC) 


main: $(ENTRY_POINT) $(OBJS)
	$(ALL_SETTINGS) -DDEBUG_MODE -o $(OUT_DIR)/$(LAUNCHER_NAME) $^ $(LINKS)
	./$(OUT_DIR)/$(LAUNCHER_NAME).exe
	
release: $(ENTRY_POINT) $(OBJS)
	$(ALL_SETTINGS) -DRELEASE_MODE -o $(OUT_DIR)/$(LAUNCHER_NAME) $^ $(LINKS)
	./$(OUT_DIR)/$(LAUNCHER_NAME).exe

$(CORE_OBJS): $(OUT_DIR)/%.o: src/Cores/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  



  
