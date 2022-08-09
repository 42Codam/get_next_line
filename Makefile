NAME 	= 	get_next_line.a
CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror 
# -fsanitize=address -g

SRCS    =	get_next_line.c get_next_line_utils.c
OBJS	=	$(SRCS:.c=.o)

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

all: ${NAME}

${NAME}: ${OBJS}
	@ar rc $@ $(OBJS)

%.o: %.c
	@echo "$(GREEN)Compiling:$(NORMAL)"
	@echo "making object file" $< "->" $@
	@$(CC) $(CFLAGS) -o $@ -c $< -g


clean:
	@echo "$(RED)Removing all object files...$(NORMAL)"
	@rm -f $(SRCS:.c=.o) $(BONUS:.c=.o)
	@echo "$(GREEN)Object files succesfully removed!$(NORMAL)"

fclean: clean
	@echo "$(RED)Removing libft.a$(NORMAL)"
	@rm -f ${NAME}
	@echo "$(GREEN)libft.a removed!"
	
re: fclean all

.PHONY: all clean fclean re bonus
