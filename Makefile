NAME = philo

CC = cc

CFLAGS = #-Wall -Wextra -Werror

SRCS = main.c parse_args.c init_data.c  philo_routine.c  monitor.c  get_time.c print_state.c cleanup.c utils.cc

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
