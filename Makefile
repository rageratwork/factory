CC = g++

DEFINES =
DEFINES_D =

CFLAGS = -c -O3 -Wall -fmessage-length=0 $(DEFINES)
CFLAGS_D = -c -O0 -g3 -Wall -fmessage-length=0 $(DEFINES_D)

LFLAGS = -s -static-libstdc++
LFLAGS_D = -static-libstdc++

DLLFLAGS = -shared $(LFLAGS)
DLLFLAGS_D = -shared $(LFLAGS_D)

OBJ_DIR = obj
OBJ_DIR_R = $(OBJ_DIR)/release
OBJ_DIR_D = $(OBJ_DIR)/debug

BIN_DIR = bin

OBJS = Child1.o \
       Child2.o \
       Child3.o \
       Creator.o \
       Factory.o

OBJS_R = $(OBJS:%.o=$(OBJ_DIR_R)/%.o)
OBJS_D = $(OBJS:%.o=$(OBJ_DIR_D)/%.o)

EXE_OBJS = $(OBJ_DIR_R)/main.o
EXE_OBJS_D = $(OBJ_DIR_R)/main.o

#targets
DIST = factorydemo.zip
EXE = $(BIN_DIR)/main.exe
EXE_D = $(BIN_DIR)/maind.exe
DLL = $(BIN_DIR)/factory.dll
DLL_D = $(BIN_DIR)/factoryd.dll

default: release

release: $(EXE)

debug: $(EXE_D)

$(EXE) : $(DLL) $(EXE_OBJS)
	$(CC) $(LFLAGS) -o $@ $^

$(EXE_D) : $(DLL_D) $(EXE_OBJS_D)
	$(CC) $(LFLAGS_D) -o $@ $^

$(DLL) : $(OBJS_R)
	$(CC) $(DLLFLAGS) -o $@ $^

$(DLL_D) : $(OBJS_D)
	$(CC) $(DLLFLAGS_D) -o $@ $^

$(OBJ_DIR_R)/%.o: %.cpp %.h
	$(CC) -o $@ $(CFLAGS) $<

$(OBJ_DIR_R)/%.o: %.cpp
	$(CC) -o $@ $(CFLAGS) $<

$(OBJ_DIR_D)/%.o: %.cpp %.h
	$(CC) -o $@ $(CFLAGS_D) $<

$(OBJ_DIR_D)/%.o: %.cpp
	$(CC) -o $@ $(CFLAGS_D) $<

$(OBJS_R) : | $(OBJ_DIR_R)

$(OBJS_D) : | $(OBJ_DIR_D)

$(OBJ_DIR_R) : | $(OBJ_DIR)
	mkdir -p $(OBJ_DIR_R)

$(OBJ_DIR_D) : | $(OBJ_DIR)
	mkdir -p $(OBJ_DIR_D)

$(OBJ_DIR) : $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

$(BIN_DIR) :
	mkdir -p $(BIN_DIR)

dist: release
	zip -j $(DIST) $(EXE) $(DLL) *.cpp *.h Makefile

clean:
	rm -rf $(OBJ_DIR)

clobber: clean
	rm -rf $(BIN_DIR) $(DIST)

