CXX = g++
EMXX = em++
OUTPUT_DIR = html
SRC_DIR = src
OBJ_DIR = obj
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
OBJ_NAME = berylchamber
CC = -g -std=c++20 -Wall -Wextra -Wpedantic -Iincludes

all : $(OBJ_NAME) $(OUTPUT_DIR)/index.html

$(OUTPUT_DIR)/index.html : $(SRCS)
	#mkdir -p $(OUTPUT_DIR)
	#$(EMXX) $(SRCS) $(CC) -o $(OUTPUT_DIR)/index.html --shell-file custom.html -sUSE_SDL=2 --preload-file romfont8x8.png -sUSE_SDL_IMAGE=2 -sALLOW_MEMORY_GROWTH -sSDL2_IMAGE_FORMATS='["png"]'

$(OBJ_NAME) : $(OBJS)
	$(CXX) $(OBJS) $(CC) -o $(OBJ_NAME) -lSDL2 -lSDL2_image

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CC) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_NAME) $(OUTPUT_DIR)/index.html