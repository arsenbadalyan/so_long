# Main Variables
NAME     = so_long
GCC      = gcc
CFLAGS   = -Wall -Wextra -Werror
RM       = rm -rf
OUTPUT   = ./$(NAME)
LIBS     = -I./includes/ -I./mlx/
LIBS_DIR = includes

# Compiled directories
SRC = src
OBJ = obj
SUBDIRS = game validation gnl maps utils

# Folder directions
SRC_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(SRC)/, $(dir)))
OBJ_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(OBJ)/, $(dir)))

# File directions
SRCS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJS = $(subst $(SRC), $(OBJ), $(SRCS:.c=.o))
LIB_DIR = $(foreach dir, $(LIBS_DIR), $(wildcard $(dir)/*.h))

# Libft
LIBFT     = ft
MLX   	  = mlx
LIBFT_DIR = ./lib$(LIBFT)/
MLX_DIR   = ./$(MLX)/

# Colors
RESET  = \033[0m
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m

# @$(GCC) $(CFLAGS) $(LIBS) -L$(MLX_DIR) -l$(MLX) -L$(LIBFT_DIR) -l$(LIBFT) -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

all: $(NAME)
	@echo > /dev/null

bonus: all

$(NAME): $(LIB_DIR) Makefile $(OBJS)
	@make WAIT_COMPILE_MSG
	@echo "${GREEN}-> Compiling LIBFT...${RESET}"
	@make -C $(LIBFT_DIR) all
	@$(GCC) -g $(CFLAGS) $(LIBS) -L$(MLX_DIR) -l$(MLX) -L$(LIBFT_DIR) -l$(LIBFT) -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)
	@make DONE_MSG

$(OBJ)/%.o: $(SRC)/%.c $(LIB_DIR)
	@mkdir -p $(OBJ) $(OBJ_DIR)
	@echo "${YELLOW}Compiling $<${RESET}"
	@$(GCC) $(CFLAGS) $(LIBS) -c $< -o $@

clean: DELETE_OBJ_MSG
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ)
fclean: clean DELETE_PROGRAM_MSG
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
re: fclean all

# Helper messages
WAIT_COMPILE_MSG:
	@echo "${YELLOW}Please wait until game is compiling...${RESET}"
DONE_MSG:
	@echo "${GREEN}! GAME COMPILED SUCCESSFULLY !${RESET}"
DELETE_OBJ_MSG:
	@echo "${RED}Object files deleting...${RESET}"
DELETE_PROGRAM_MSG:
	@echo "${RED}! ATTENTION !\nGame is deleting...${RESET}"