NAME = minishell
FILES = sh_ps_ischar sh_ps_isnum sh_ps_isdelimeter \
	sh_ps_isquate sh_ps_isspechar sh_ps_lexcheck \
	main

CC = gcc
FLAGS = -Wall -Werror -Wextra

RM = rm -f
#SRCDIR = ./srcs/parser/
SRCDIR = ./srcs/

SRC = $(addprefix $(SRCDIR), $(addsuffix .c , $(FILES)))


$(NAME): 
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)
