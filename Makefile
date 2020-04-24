NAME = sudokusolver

CFLAGS = -Wall -Werror -Wextra

SRCDIR = src
HEADDIR = includes

SRC =	$(SRCDIR)/builder.c \
		$(SRCDIR)/solver.c \
		$(SRCDIR)/main.c

SRC_O = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_O)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -I$(HEADDIR) -o $@ $<

clean:
	rm -f $(SRC_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re