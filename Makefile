
CC = cc

CFLAGS = -Wall -Wextra -Werror  -fsanitize=thread -g

SRCS = main.c parse_args.c init_data.c  philo_routine.c  monitor.c  get_time.c print_state.c cleanup.c utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = philo

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT) : 
	make -s -C libft
	make bonus -s -C libft

clean:
	rm -f $(NAME)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(OBJS)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
