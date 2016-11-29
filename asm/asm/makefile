NAME = asm
LIB = ../libft/libft.a

SRC = main.c
SRC += lexical_analysis.c
SRC += syntax_analysis.c
SRC += hex_generator.c
SRC += data_init.c
SRC += data_del.c

OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Creating Library$(CE)\033[1A";
	-@make -C ../libft
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Compiling ASM ...$(CE)";
	@gcc -o $(NAME) $(FLAG) $(SRC) $(LIB)

%.o: %.c
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Compiling $<$(CE) \033[1A";
	@gcc $(FLAG) -c $< -o $@

clean:
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Cleaning Library ...$(CE)\033[1A";
	-@make clean -C ../libft
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Cleaning ASM objects$(CE)\033[1A";
	@/bin/rm -rf $(OBJ)

fclean: clean
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)FCleaning Library ...$(CE)\033[1A";
	-@make fclean -C ../libft 
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Cleaning 21sh ...$(CE)\033[1A";
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
