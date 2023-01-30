# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: carlo <carlo@student.42.fr>                  +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 09:28:26 by cwesseli      #+#    #+#                  #
#    Updated: 2023/01/27 09:58:53 by cwesseli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

NAME		= so_long
CC			?= gcc
CFLAGS		= -Wall -Wextra -Werror

LIBMLX		= ./lib/MLX42
LIBFT		= ./lib/libft
LIBS		= $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a 
HEADERS		= -I $(LIBFT) -I $(LIBMLX)/include/MLX42/ -I ./include
OBJ_FILES	= $(addprefix obj/, so_long.o level_mgt.o utils.o init.o hooks.o\
				 put_img.o player_move.o check_move.o check_grid.o load.o flood_check.o\
				 load_player.o load_enemy.o enemy_move_vert.o enemy_move_hori.o\
				 put_bg.o step_counter.o delete_data.o error_exit.o utils_2.o)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	ARCFLAGS = -ldl -lglfw -pthread -lm
else
	ARCFLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
endif
		
all: libmlx libft $(NAME)

bonus: all

libmlx:
	$(MAKE) -C $(LIBMLX)

libft:
	$(MAKE) -C $(LIBFT)
	
$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LIBS) $(HEADERS) $(ARCFLAGS) -o $(NAME)

$(OBJ_FILES): obj/%.o: src/%.c 
	@mkdir -p $(dir $@)
	@echo "$(GREEN)$(BOLD)Compiling:$(RESET) $(notdir $<)"
	@$(CC) -c $(CFLAGS) $(HEADERS) -o $@ $< 

clean:
	@echo "$(RED)Cleaning$(RESET)"
	@rm -rf obj/
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFT) clean
	
fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY:	all bonus clean fclean re libmlx libft
