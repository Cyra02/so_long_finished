NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MLXFLAGS = -L . -lmlx -framework OpenGL -framework AppKit

FILES = srcs/errors \
		srcs/ft_calloc \
		srcs/ft_split \
		srcs/ft_sstrlen \
		srcs/ft_strdup  \
		srcs/ft_strjoin \
		srcs/map_utils \
		srcs/player \
		srcs/so_long \
		srcs/get_next_line/get_next_line \
		srcs/get_next_line/get_next_line_utils \
		srcs/graficos \
		srcs/extra \
		srcs/initial \

SRCS = $(addsuffix .c,$(FILES))
OBJS = $(addsuffix .o,$(FILES))

all: $(NAME)

.c.o: $(SRCS)
	@$(CC) -I includes/ $(CFLAGS) -c $^ -o $@ >/dev/null

$(NAME):  $(OBJS)
	@printf "\e[32mObjects Compiled✅\e[0m\n"
	@printf "\e[32mCompiling minilibx and printf...⏳\e[0m\n"
	@$(MAKE) -C srcs/minilibx >/dev/null
	@$(MAKE) -C srcs/printf >/dev/null
	@mv srcs/printf/libftprintf.a .
	@mv srcs/minilibx/libmlx.a .
	@$(CC) $(CFLAGS) $(MLXFLAGS) $^ libftprintf.a libmlx.a -o $@
	@printf "\e[32mReady to play 🤖\e[0m\n"

sanitize: #this rule adds the sanitize flag to CFLAGS
	@printf "\e[32mAdding Sanitize to CFLAGS\e[0m\n"
	$(eval CFLAGS += -fsanitize=address -g3)

sani: sanitize all #this rule changes CFLAGS to include sanitize and then compiles the program as usual

clean:
	@make clean -C srcs/printf >/dev/null
	@make clean -C srcs/minilibx >/dev/null
	@rm -rf $(OBJS)
	@printf "\e[31m*.o=>🗑️\e[0m\n"

fclean: clean
	@rm -rf $(NAME) >/dev/null
	@rm -rf libftprintf.a >/dev/null
	@rm -rf libmlx.a >/dev/null
	@printf "\e[31m(so_long && libmlx.a && libftprintf.a)=>🗑️\e[0m\n"

re: fclean all

.PHONY: all clean fclean re



# $(NAME):  $(SOURCE) $(HDRS) $(PRINT)
# gcc $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(PRINT) -o $(NAME)