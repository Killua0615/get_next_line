NAME    := libgnl.a
SRCS    := get_next_line.c get_next_line_utils.c
OBJS    := $(SRCS:.c=.o)

CC      := cc
CFLAGS  := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "Created $(NAME)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

clean:
	rm -f $(OBJS)
	@echo "Removed object files"

fclean: clean
	rm -f $(NAME)
	@echo "Removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re