NAME			=	fdf

BINDIR			=	bin/
INCDIR			=	include/
LIBDIR			=	lib/

FDF_DIR			=	src/fdf/

LIBMLX			=	./lib/MLX42
HEADERS			=	-I ./include -I $(LIBMLX)/include
LIBS			=	$(LIBMLX)/build/libmlx42.a
LIBFTDIR		=	./lib/libft
LIBFT			=	$(LIBFTDIR)/libft.a

CC				=	gcc
CFLAGS			=	-Wextra -Wall -Werror -Wunreachable-code -Ofast

FDF_SRCS		=	main.c \
					error.c \
					maps.c \
					image.c \
					exit.c \
					utils.c \
					coords.c \
					list.c \
					points.c \
					lines.c \
					line_utils.c

FDF_OBJS		=	$(addprefix ${BINDIR}, ${FDF_SRCS:.c=.o})

all: $(BINDIR) libmlx libft $(NAME)

${BINDIR}%.o: ${FDF_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

libft:
	@$(MAKE) -C $(LIBDIR)libft

$(LIBMLX):
	@cd $(LIBDIR) && git clone https://github.com/codam-coding-college/MLX42.git

libmlx: $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(FDF_OBJS)
	@$(CC) $(FDF_OBJS) $(LIBFT) $(LIBS) $(HEADERS) -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

$(BINDIR):
	@mkdir -p bin

clean:
	@rm -fr $(BINDIR)
	@rm -fr $(LIBMLX)/build
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft
