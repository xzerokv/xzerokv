PROJECT_DIR := $(PWD)

SRC_DIR     := $(PROJECT_DIR)/src
INCLUDE_DIR := $(PROJECT_DIR)/include

DEBUG_BUILD_DIR   := $(PROJECT_DIR)/cmake-build-debug
RELEASE_BUILD_DIR := $(PROJECT_DIR)/cmake-build-release

BUILD_TYPE ?= Debug

ifeq ($(BUILD_TYPE),Release)
BUILD_DIR = $(RELEASE_BUILD_DIR)
else
BUILD_DIR = $(DEBUG_BUILD_DIR)
endif

.PHONY: all
all: xzerokv

.PHONY: xzerokv
xzerokv:
	cmake . -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -B$(BUILD_DIR)
	cmake --build $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
