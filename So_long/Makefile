NAME        = so_long

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCDIR      = include
SRCDIR      = src
LIBFTDIR    = libft
MLXDIR      = minilibx-linux

LIBFT       = $(LIBFTDIR)/libft.a

MLX_LIB     = $(MLXDIR)/libmlx.a
MLX_FLAGS   = -lXext -lX11 -lm

INCLUDES    = -I$(INCDIR) -I$(LIBFTDIR) -I$(MLXDIR)

SRC         = main.c init_game.c map_read.c map_validate.c map_utils.c \
              flood_fill.c render.c hooks.c error_exit.c free.c grid_utils.c img_utils.c file_utils.c \
			  map_validate_checks.c map_validate_content.c move.c

SRCS        = $(addprefix $(SRCDIR)/, $(SRC))
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
