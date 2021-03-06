CC            := g++ -O3 -Wall
LD            := g++ -O3 -Wall

SDL_LIBS      := -lSDL2
OPENGL_LIBS   := -lGL
X11_LIBS      := -lX11

SRC_DIR       := src/
BIN_DIR       := bin/
INC_DIR       := include/

SRC           := $(foreach sdir, $(SRC_DIR), $(wildcard src/*.cpp))
OBJ           := $(patsubst src/%.cpp, bin/%.o, $(SRC))
INCLUDES      := $(addprefix -I, $(INC_DIR))

vpath %.cpp $(SRC_DIR)

define make-goal
$(BIN_DIR)%.o: %.cpp
	$(CC) $(INCLUDES) -c $$< -o $$@
endef

.PHONY: all checkdirs clean

all: checkdirs bin/BulletinBoard

bin/BulletinBoard: $(OBJ)
	$(LD) $^ -o $@ $(SDL_LIBS) $(OPENGL_LIBS) $(X11_LIBS)

checkdirs: $(BIN_DIR)


$(BIN_DIR):
	@mkdir -p $@

clean:
	@rm $(OBJ); rm bin/BulletinBoard

$(foreach bdir,$(BIN_DIR),$(eval $(call make-goal,$(bdir))))
