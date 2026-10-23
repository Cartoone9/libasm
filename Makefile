NAME := libasm.a

AS      := nasm
ASFLAGS := -f elf64
AR      := ar rcs
CC      := cc
CFLAGS  := -Wall -Werror -Wextra

ifdef DEBUG
	CFLAGS += -g3
endif

OBJS_DIR := .objs

SRCS := $(wildcard */*.s)
OBJS := $(patsubst %.s, $(OBJS_DIR)/%.o, $(SRCS))

TESTS := $(wildcard */*_test.c)
BINS  := $(patsubst %_test.c, %_test, $(TESTS))

RESET  := \033[0m
YELLOW := \033[0;33m

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.s
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) $< -o $@

%_test: %_test.c $(NAME)
	$(CC) $(CCFLAGS) $< $(NAME) -o $@

test: $(BINS)
	@echo
	@for b in $(BINS); do printf "$(YELLOW)=== $$b ===$(RESET)\n"; ./$$b; echo; done

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(BINS) $(NAME)

re: fclean
	$(MAKE) all

.PHONY:
	all test clean fclean re
