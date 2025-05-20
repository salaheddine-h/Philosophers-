NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror  #-fsanitize=thread -g

SRCS = main.c cleanup.c get_time.c init_data.c monitor.c parse_args.c philo_routine.c print_state.c utils.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
