NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

INCLUDES := -I. -I./libft

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

# Elenco dei tuoi sorgenti
SRCS = push_swap.c
SRCS += push_swap_args_utils_1.c
SRCS += push_swap_args_utils_2.c
SRCS += push_swap_args_utils_3.c
SRCS += push_swap_operation_1.c
SRCS += push_swap_operation_2.c
SRCS += push_swap_operation_3.c
SRCS += push_swap_operation_4.c
SRCS += push_swap_sort_123.c
SRCS += push_swap_sort_45.c
SRCS += push_swap_sorting_utils.c
SRCS += push_swap_stack_utils.c
SRCS += push_swap_radix_sort.c

OBJS := $(SRCS:.c=.o)

define QUOTE_LIST
$(foreach x,$1,"$(x)")
endef

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(call QUOTE_LIST,$(OBJS)) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(call QUOTE_LIST,$(OBJS))
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
