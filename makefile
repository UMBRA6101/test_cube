### COLOR ###
RED = \e[31m
MAJA = \e[35m
GREEN = \e[32m
END = \e[0m

### NAME ###
NAME = cube3d

### INC ###
DIRINC = ./includes/

### LIB ###
DIRLIBFT = ./lib/libft

### SRC ###
SRCDIR = src/
SRC =           main.c \
				init.c \
				utils.c \
				raycasting.c \
				free/clear.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

### OBJ ###
OBJDIR = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))

### COMPILE ###
CC = cc
CCFLAG = -Wall -Wextra -g3
INCFLAG = -I$(DIRINC)
MLXFLAG = -L./lib/mlx_Linux -lmlx_Linux -lmlx -lXext -lX11 -lbsd -lm
LIBFTDIR = ./lib/libft/
PIPEXDIR = pipex/

### VAR_BP ###
TOTAL := $(words $(SRCS))
COUNT := 0

all: progress $(NAME)
		@echo "$(tput bold)$(GREEN)\n$(NAME) is compile$(END)";

libft:
		@if [ ! -f "libft.a" ]; then \
			make -s -C $(LIBFTDIR) all > /dev/null;\
			cp $(LIBFTDIR)libft.a ./; \
		fi;

$(OBJDIR)%.o: $(SRCDIR)%.c
		@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
		@printf "\r[%-$(TOTAL)s] $(COUNT)/$(TOTAL)" $$(printf '#%.0s' $$(seq 1 $(COUNT)))
		@mkdir -p $(dir $@) > /dev/null
		@$(CC) $(CCFLAG) $(INCFLAG) -Imlx_Linux -c $< -o $@

progress:
		@if [ ! -f "$(NAME)" ]; then \
			echo "Compilation in progress..." ;\
			printf "\r[%-$(TOTAL)s] 0/$(TOTAL)";\
		fi;

$(NAME): libft $(OBJS)
		@$(CC) $(CCFLAG) $(INCFLAG) $(OBJS) libft.a $(MLXFLAG) -o $@

clean:
		@rm -rf $(OBJDIR)
		@rm -f libft.a
		@echo "$(RED)objet of $(NAME) is removed$(END)"

fclean: clean
		@rm -f $(NAME)
		@make -C $(LIBFTDIR) clean
		@echo "$(RED)objet and exec of $(NAME) is removed$(END)"

re: fclean all
		@make -C $(LIBFTDIR) fclean
		@echo $(NAME) is recompiled

.PHONY: all clean fclean re progess
