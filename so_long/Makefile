NAME = so_long

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = so_long.h gnl/get_next_line.h libft/libft.h ft_printf/ft_printf.h

HEADER_BONUS = bonus/so_long_bonus.h gnl/get_next_line.h libft/libft.h ft_printf/ft_printf.h

SRC = 	paint.c \
		hooks.c \
		read_map.c \
		so_long.c \
		valid_map.c \
		utils.c \
		gnl/get_next_line.c \
	  	gnl/get_next_line_utils.c

SRC_BONUS =	bonus/read_map_bonus.c \
			bonus/for_vrag_bonus.c \
			bonus/so_long_bonus.c \
			bonus/valid_map_bonus.c \
			bonus/utils_bonus.c \
			gnl/get_next_line.c \
	  		gnl/get_next_line_utils.c 

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME) $(PRINTF) $(LIBFT)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

$(NAME) : $(OBJ) $(HEADER) $(PRINTF) $(LIBFT)
	$(CC) $(OBJ) $(PRINTF) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(OBJ_BONUS) $(PRINTF) $(HEADER_BONUS) $(LIBFT)
	$(CC) $(OBJ_BONUS) $(PRINTF) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	make -C ft_printf clean
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ft_printf fclean
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re