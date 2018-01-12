#### PROJECT SETTINGS ####

DIR_NAME=raycaster
ARCHIVE_NAME=${DIR_NAME}.tar.gz
BIN=${DIR_NAME}

CXX=g++
CXXFLAGS=-g

LFLAGS=-lglut -lGL -lGLU

SRC_DIR=./src
SRC_EXT=cpp
HDR_DIR=./include
OBJ_DIR=./build
BIN_DIR=./bin

HDR=-I${HDR_DIR}

#### END PROJECT SETTINGS ####

SHELL=/bin/bash

SRC=${shell find ${SRC_PATH} -name '*.${SRC_EXT}'}

OBJ=${SRC:${SRC_DIR}/%.${SRC_EXT}=${OBJ_DIR}/%.o}

.PHONY: all
all: dirs ${BIN_DIR}/${BIN}

# Link the executable
${BIN_DIR}/${BIN}: ${OBJ}
	@echo "Linking: $@"
	@${CXX} $^ ${LFLAGS} -o $@

# Objects compilation
${OBJ_DIR}/%.o: ${SRC_DIR}/%.${SRC_EXT}
	@echo "Compiling: $< -> $@"
	@${CXX} ${CXXFLAGS} -c $< -o $@ ${HDR}

.PHONY: dirs
dirs:
	@echo "Creating directories"
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${BIN_DIR}

.PHONY: clean
clean:
	@echo "Deleting objects and binaries files/directories"
	@rm -fr ${BIN_DIR} ${OBJ_DIR}

.PHONY: archive
archive: clean
	@echo "Making the archive file: ${DIR_NAME} -> ${ARCHIVE_NAME}"
	@cd .. && tar -czvf ${ARCHIVE_NAME} ${DIR_NAME} > /dev/null

