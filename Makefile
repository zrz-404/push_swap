# Standard
NAME				= push_swap

# Directories
LIBFT				= includes/libft/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source Files
MOVES_DIR		=	$(SRC_DIR)moves/push.c \
					$(SRC_DIR)moves/rev_rotate.c \
					$(SRC_DIR)moves/rotate.c \
					$(SRC_DIR)moves/sort_stacks.c \
					$(SRC_DIR)moves/sort_three.c \
					$(SRC_DIR)moves/swap.c

MAIN_DIR		=	$(SRC_DIR)main/main.c \
					$(SRC_DIR)main/utils.c \
					$(SRC_DIR)main/errors.c \
					$(SRC_DIR)main/init_ab.c \
					$(SRC_DIR)main/init_ba.c \
					$(SRC_DIR)main/init_stacks.c

SRCS 				= $(MOVES_DIR) $(MAIN_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Rules
start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re