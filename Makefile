NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror  #-fsanitize=thread -g

SRCS = main.c parse_args.c init_data.c  philo_routine.c  monitor.c  get_time.c print_state.c cleanup.c utils.c

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
