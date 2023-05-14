NAME			=	fdf
NAME2			=	fdf_bonus

BINDIR			=	bin/
INCDIR			=	include/
LIBDIR			=	lib/

FDF_DIR			=	src/fdf/
BONUS_DIR		=	src/bonus/

LIBMLX			=	./lib/MLX42
HEADERS			=	-I ./include/fdf -I $(LIBMLX)/include
HEADERS_BONUS	=	-I ./include/bonus -I $(LIBMLX)/includesp
LIBS			=	$(LIBMLX)/build/libmlx42.a
LIBFTDIR		=	./lib/libft
LIBFT			=	$(LIBFTDIR)/libft.a

CC				=	gcc
CFLAGS			=	-Wextra -Wall -Werror -Wunreachable-code -Ofast

COLOUR_GREEN	=	\033[0;32m
COLOUR_YELLOW	=	\033[0;33m
COLOUR_RED		=	\033[0;31m
COLOUR_END		=	\033[0m

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

BONUS_SRCS		=	main_bonus.c \
					error_bonus.c \
					maps_bonus.c \
					image_bonus.c \
					exit_bonus.c \
					utils_bonus.c \
					coords_bonus.c \
					list_bonus.c \
					points_bonus.c \
					lines_bonus.c \
					line_utils_bonus.c \
					matrices_bonus.c \
					hooks_bonus.c \
					color_bonus.c \
					rotation_hooks.c \
					translation_hooks.c

FDF_OBJS		=	$(addprefix ${BINDIR}, ${FDF_SRCS:.c=.o})
BONUS_OBJS		=	$(addprefix ${BINDIR}, ${BONUS_SRCS:.c=.o})

all:  brew $(BINDIR) libmlx libft $(NAME)

${BINDIR}%.o: ${FDF_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BINDIR}%.o: ${BONUS_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

libft:
	@$(MAKE) -C $(LIBDIR)libft

$(LIBMLX):
	@cd $(LIBDIR) && git clone  -b v2.3.1 https://github.com/codam-coding-college/MLX42.git

libmlx: $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(FDF_OBJS)
	@$(CC) $(FDF_OBJS) $(LIBFT) $(LIBS) $(HEADERS) -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

$(BINDIR):
	@mkdir -p bin

bonus: brew $(BINDIR) libmlx libft $(NAME2)

$(NAME2): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBFT) $(LIBS) $(HEADERS_BONUS) -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME2)

brew:
	@if command -v brew >/dev/null 2>&1; then \
        echo "$(COLOUR_GREEN)Homebrew is already installed.$(COLOUR_END)"; \
		if command -v cmake >/dev/null 2>&1; then \
			echo "$(COLOUR_GREEN)cmake is already installed.$(COLOUR_END)"; \
		else \
			echo "$(COLOUR_RED)cmake is not installed. Please follow the instructions to install it: $(COLOUR_GREEN)brew install Cmake$(COLOUR_END)"; \
		fi; \
		if command -v brew --version glfw >/dev/null 2>&1; then \
			echo "$(COLOUR_GREEN)glfw is already installed.$(COLOUR_END)"; \
		else \
			echo "$(COLOUR_RED)glfw is not installed. Please follow the instructions to install it: $(COLOUR_GREEN)brew install glfw$(COLOUR_END)"; \
		fi \
    else \
        echo "$(COLOUR_YELLOW)Homebrew is not installed. Please follow the instructions of this website to install it: $(COLOUR_GREEN)https://brew.sh/index_fr$(COLOUR_END)"; \
    fi

clean:
	@rm -fr $(BINDIR)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@rm -fr $(LIBMLX)/build
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft, brew
