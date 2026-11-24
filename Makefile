#
# make        : build executable
# make clean  : remove build and output files
# make run    : build and run
#

CXX = g++

# 编译选项：加入 -std=c++20，按需保留协程等高级特性
CXXFLAGS := -std=c++20 -Wall -Wextra -g -O2 -march=x86-64 -mtune=generic
# CXXFLAGS := -std=c++20 -Wall -ggdb -W -O

LFLAGS =

ifeq ($(OS),Windows_NT)
	LFLAGS += -static-libstdc++ -static-libgcc
	MAIN := main.exe
	RM := del /q /f
	MD := mkdir
	SAFE_MD := if not exist
	FIXPATH = $(subst /,\,$1)
else
	MAIN := main
	RM := rm -f
	MD := mkdir -p
	SAFE_MD := @mkdir -p
	FIXPATH = $1
endif

# =========================
# Directories
# =========================
SRC     := src
INCLUDE := include 
LIB     := lib
BUILD   := build
OUTPUT  := output

# =========================
# Include / Lib flags
# =========================
INCLUDES := -I$(INCLUDE) 
LIBS := -L$(LIB) -lpthread 

# =========================
# Sources / Objects
# =========================
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp,$(BUILD)/%.o,$(SOURCES))
DEPS    := $(OBJECTS:.o=.d)

TARGET := $(call FIXPATH,$(OUTPUT)/$(MAIN))

# =========================
# Rules
# =========================
all: $(BUILD) $(OUTPUT) $(TARGET)
	@echo Build complete

# 安全创建目录（兼容 Windows cmd 和 Linux shell）
$(BUILD):
	$(SAFE_MD) $(BUILD) $(MD) $(BUILD)

$(OUTPUT):
	$(SAFE_MD) $(OUTPUT) $(MD) $(OUTPUT)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LFLAGS) $(LIBS)

# 修复：将 %.c 改为 %.cpp，并增加 -MP 优化依赖追踪
$(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

-include $(DEPS)

.PHONY: clean run

clean:
ifeq ($(OS),Windows_NT)
	-@$(RM) $(call FIXPATH,$(BUILD)\*.o) >nul 2>&1
	-@$(RM) $(call FIXPATH,$(BUILD)\*.d) >nul 2>&1
	-@$(RM) $(call FIXPATH,$(TARGET)) >nul 2>&1
else
	-@$(RM) $(call FIXPATH,$(BUILD)/*.o)
	-@$(RM) $(call FIXPATH,$(BUILD)/*.d)
	-@$(RM) $(call FIXPATH,$(TARGET))
endif
	@echo Clean complete

run: all
ifeq ($(OS),Windows_NT)
	@$(TARGET)
else
	@./$(TARGET)
endif