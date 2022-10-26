NAME = minishell
FILES = sh_ps_ischar sh_ps_isnum sh_ps_isdelimeter \
	sh_ps_isquote sh_ps_isspechar sh_ps_lexcheck \
	sh_ps_token sh_ps_quote main 

CC = gcc
FLAGS = -Wall -Werror -Wextra

RM = rm -f
LIBFT = libft.a
LIBFT_DIR  = ./libft/
SRCDIR = ./srcs/

SRC = $(addprefix $(SRCDIR), $(addsuffix .c , $(FILES)))


$(NAME):
#	@cd $(LIBFT_DIR) && make
#	@cp $(LIBFT_DIR)$(LIBFT) .
	$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	@cd $(LIBFT_DIR) && make clean
	$(RM) $(NAME)
re: clean all
