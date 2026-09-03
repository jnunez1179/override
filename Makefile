CC				:= gcc

INCDIR		:= . inc
SRCDIR		:= . src
BUILD			:= build
OBJDIR		:= $(BUILD)/obj
BINDIR		:= $(BUILD)/bin

OPT				:= -O0
DEBUG			:= -g
WFLAGS		:= -Wall -Wextra -Wshadow
INCFLAGS	:= $(foreach D, $(INCDIR), -I$(D))
DEPFLAGS	:= -MP -MD

CFLAGS		:= $(OPT) $(DEBUG) $(INCFLAGS) $(DEPFLAGS)
SRC				:= $(shell find $(SRCDIR) -type f -name "*.c" | sed "s#^\./##")
OBJS	    := $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))
DEPFILES	:= $(OBJS:.o=.d)
BINARY		:= $(BINDIR)/binread

.PHONY: clean all run

#Build

all: $(BINARY)

$(BINARY): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(BUILD)

run: $(BINARY)
	@$(BINARY)

-include $(DEPFILES)
