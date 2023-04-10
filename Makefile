NAME		=	fdf
NAME2		=	fdf_bonus

BINDIR		=	bin/
INCDIR		=	includes/
LIBDIR		=	libs/

MLXDIR		=	$(LIBDIR)MLX42
LIBFTDIR	=	$(LIBDIR)libft
FDF_DIR		=	src/fdf/
COMMON_DIR	=	src/common/
BONUS_DIR	=	src/bonus/

LIBMLX		=	$(MLXDIR)/build/libmlx42.a
HEADERS		=	-I ./include -I $(LIBMLX)/include
LIBFT		=	$(LIBFTDIR)/libft.a	
CC			=	gcc
CFLAGS		=	-Wextra -Wall -Werror -Wunreachable-code -Ofast

FDF_SRCS	=	fdf.c

COMMON_SRCS	=

BONUS_SRCS	=

FDF_OBJS	=	$(addprefix ${BINDIR}, ${FDF_SRCS:.c=.o})
COMMON_OBJS	=	$(addprefix ${BINDIR}, ${COMMON_SRCS:.c=.o})
BONUS_OBJS	=	$(addprefix ${BINDIR}, ${BONUS_SRCS:.c=.o})

all: $(BINDIR) libmlx libft $(NAME)

${BINDIR}%.o: ${FDF_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BINDIR}%.o: ${COMMON_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BINDIR}%.o: ${BONUS_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

libft:
	@$(MAKE) -C $(LIBDIR)libft

libmlx:
	@cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

$(NAME): $(FDF_OBJS)
	@$(CC) $(CFLAGS) $(LIBFT) $(LIBMLX) $(HEADERS) $(FDF_OBJS) -lglfw -L "/USERS/$(USER)/.brew/opt/glfw/lib/" -o $@

$(BINDIR):
	@mkdir -p bin

bonus: $(BINDIR) libmlx libft $(NAME2)

$(NAME2): $(BONUS_OBJS)
	@$(CC) -g $(CFLAGS) $(LIBFT) $(LIBMLX) $(HEADERS) $(BONUS_OBJS) -o $@


clean:
	@rm -fr $(BINDIR)
	@rm -fr $(MLXDIR)/build
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft
