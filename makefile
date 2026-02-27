#Variable:

#compilateur
CXX = g++

#Option de compilation
CXXFLAGS = -ansi -pedantic -Wall -std=c++17 -I$(INCLUDE_DIR)

#nom de l'executable
TARGET = grammaireEtLangage

#dossier contenant les .cpp
SRC_DIR = src

#dossier contenant les .h
INCLUDE_DIR = include

#dossier pour les .o 
OBJ_DIR = out

#liste des fichiers dans SRC_DIR
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

#liste des fichiers dans INCLUDE_DIR 
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)

#liste des fichiers dans OBJ_DIR
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

#règle pour construire l'exécutable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

#régple pour compiler de cpp à .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#créer le dossier out s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#regle executé lorsque qu'on appelle le makefile  
all: $(TARGET)

#nettoie le fichier executable et les .o
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: clean all
