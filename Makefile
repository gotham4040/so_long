NAME    = so_long

SRCS    = check_map.c check_map_utils.c load_game_1.c load_game_2.c play_game.c so_long.c valid_path.c valid_path_utils.c

MLX_DIR	= ./MLX42

OBJS    = $(SRCS:.c=.o)

CC      = gcc

CFLAGS  += -Wall -Wextra -Werror

LIBS    = ./ft_printf/libftprintf.a ./libft/libft.a $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -lm

RM      = rm -f

all: $(NAME)
	@echo "\n\n		✨ Compilation completed successfully ✨\n\n"

$(NAME): libs $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

libs:
	make -C ft_printf
	make -C libft
	@cd $(MLX_DIR) && cmake -B build && cmake --build build -j4

clean:
	$(RM) $(OBJS)
	@make --no-print-directory -C ft_printf clean
	@make --no-print-directory -C libft clean
	@echo "\n\n		🧴 Cleaning completed 🧴\n\n"

fclean: clean
	$(RM) $(NAME)
	@make -C ft_printf fclean
	@make -C libft fclean
	@echo "\n\n		☢️  Full cleaning completed ☢️\n\n"

re: fclean all

.PHONY: all clean fclean re
