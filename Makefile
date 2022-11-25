CPP=g++
CPPFLAGS=-g -Wall $(shell sdl2-config --cflags)
LDFLAGS=$(shell sdl2-config --libs)

SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(SRC)/*.h)
BIN=program

all:	$(BIN)

$(BIN): $(OBJS) $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	
$(OBJ)/%.o: $(SRC)/%.cpp $(OBJ)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ)
	$(RM) $(BIN)
