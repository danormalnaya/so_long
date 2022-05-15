NAME = so_long

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = so_long.h gnl/get_next_line.h libft/libft.h ft_printf/ft_printf.h

# HEADER_BONUS = bonus/so_long_bonus.h

SRC = 	paint.c \
		hooks.c \
		read_map.c \
		so_long.c \
		valid_map.c \
		utils.c \
		gnl/get_next_line.c \
	  	gnl/get_next_line_utils.c

# SRC_BONUS = bonus/check_map_bonus.c bonus/init_bonus.c bonus/hooks_bonus.c bonus/read_map_bonus.c \
# 	  		bonus/utils_bonus.c bonus/load_sprites_bonus.c gnl/get_next_line.c \
# 	  		gnl/get_next_line_utils.c bonus/draw_bonus.c bonus/ft_itoa.c \
# 	  		bonus/enemy.c bonus/draw_enemy.c bonus/utils_bonus_2.c

OBJ = $(SRC:%.c=%.o)

# OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME) $(PRINTF) $(LIBFT)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

$(NAME) : $(OBJ) $(HEADER) $(PRINTF) $(LIBFT)
	$(CC) $(OBJ) $(PRINTF) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# bonus: $(MLX) $(OBJ_BONUS) $(PRINTF) $(HEADER_BONUS)
# 	$(CC) $(OBJ_BONUS) -Lprintf -lftprintf -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C ft_printf clean
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ft_printf fclean
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re