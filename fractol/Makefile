NAME = fractol
BO_NAME = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBMLX_DIR = MLX42
INC_DIR = includes
SRCS = srcs/free_exit.c\
	srcs/ft_atof.c\
	srcs/hooks.c\
	srcs/initialize.c\
	srcs/julia.c\
	srcs/main.c\
	srcs/mandelbrot.c\
	srcs/parser.c\
	srcs/utils.c
BONUS = bonus/free_exit_bonus.c\
	bonus/ft_atof_bonus.c\
	bonus/hooks_bonus.c\
	bonus/initialize_bonus.c\
	bonus/julia_bonus.c\
	bonus/main_bonus.c\
	bonus/mandelbrot_bonus.c\
	bonus/parser_bonus.c\
	bonus/utils_bonus.c\
	bonus/burning_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a
LIBS = -L$(LIBFT_DIR) -lft  -L$(LIBMLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm 
HEADERS = -I$(INC_DIR) -I$(LIBFT_DIR)/includes -I$(LIBMLX_DIR)/include/MLX42/MLX42.h -I$(LIBMLX_DIR)/include/MLX42/MLX42_Int.h

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS)  -o $(NAME)

$(OBJS): %.o: %.c $(INC_DIR)/fractol.h
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && $(MAKE) -C $(LIBMLX_DIR)/build -j4

bonus: $(BO_NAME)

$(BO_NAME): $(LIBFT) $(LIBMLX) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(HEADERS) $(LIBS) -o $(BO_NAME)

$(BONUS_OBJS): %.o: %.c $(INC_DIR)/fractol_bonus.h
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(LIBMLX_DIR)/build
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)
	rm -rf $(BO_NAME)

re: fclean all

.PHONY: all clean fclean re

