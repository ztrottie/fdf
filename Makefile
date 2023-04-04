NAME	=	fdf

BINDIR	=	bin/
SRCDIR	=	src/


all: libft

libft:
	$(MAKE) -C libft

clean:

fclean: clean

re: fclean all

.PHONY: all clean fclean re libft