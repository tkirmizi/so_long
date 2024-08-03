NAME = so_long
SRCS = main.c map.c map_check.c map_exit.c image.c end.c walk.c free.c
OBJS := $(SRCS:%.c=%.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -I$(MLX_PATH) -I$(FT_PRINTF_PATH) -O3
MLX_PATH = mlx
MLX_LIB = $(MLX_PATH)/libmlx.a

FT_PRINTF_PATH = printf
FT_PRINTF_LIB = printf/libftprintf.a

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL:%.c=%.o)

all: $(NAME)

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_PATH) clean
	make -C $(FT_PRINTF_PATH)


$(MLX_LIB):
	@$(MAKE) -C $(MLX_PATH)

$(NAME): $(OBJS) $(GNL_OBJS) $(FT_PRINTF_LIB) $(MLX_LIB)
	$(CC) $(CCFLAGS) $(OBJS) $(GNL_OBJS) $(FT_PRINTF_LIB) $(MLX_LIB) -lm -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(GNL_OBJS)
	$(MAKE) clean -C $(MLX_PATH)
	$(MAKE) clean -C $(FT_PRINTF_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FT_PRINTF_PATH)

re: fclean all

.PHONY: all clean fclean re