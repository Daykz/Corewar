# ---------------------------------------------------------------------------- #
# PROJECT DATA
# ---------------------------------------------------------------------------- #

NAME		=	libft.a

# ---------------------------------------------------------------------------- #

SRCS		=	get_next_line.c				\
\
				ft_arr/ft_arrdel.c				\
				ft_arr/ft_arrlen.c				\
				ft_arr/ft_array_dup.c			\
				ft_arr/ft_array_indexof.c		\
				ft_arr/ft_array_push_back.c		\
				ft_arr/ft_array_push_front.c	\
				ft_arr/ft_array_push_index.c	\
\
				ft_count/ft_count_char.c	\
				ft_count/ft_count_word.c	\
\
				ft_is/ft_isalnum.c			\
				ft_is/ft_isalpha.c			\
				ft_is/ft_isascii.c			\
				ft_is/ft_isdigit.c			\
				ft_is/ft_isprint.c			\
				ft_is/ft_isspace.c			\
\
				ft_mem/ft_memdel.c			\
				ft_mem/ft_memset.c			\
				ft_mem/ft_smalloc.c			\
\
				ft_put/ft_putarray.c		\
				ft_put/ft_putarray_fd.c		\
				ft_put/ft_putchar.c			\
				ft_put/ft_putchar_fd.c		\
				ft_put/ft_putendl.c			\
				ft_put/ft_putendl_fd.c		\
				ft_put/ft_putnbr.c			\
				ft_put/ft_putnbr_fd.c		\
				ft_put/ft_putnchar.c		\
				ft_put/ft_putstr.c			\
				ft_put/ft_putstr_fd.c		\
\
				ft_str/ft_str_is.c			\
				ft_str/ft_strcat.c			\
				ft_str/ft_strchr.c			\
				ft_str/ft_strclean.c		\
				ft_str/ft_strclr.c			\
				ft_str/ft_strcmp.c			\
				ft_str/ft_strcpy.c			\
				ft_str/ft_strdel.c			\
				ft_str/ft_strdup.c			\
				ft_str/ft_strequ.c			\
				ft_str/ft_striteri.c		\
				ft_str/ft_strjoin.c			\
				ft_str/ft_strlcat.c			\
				ft_str/ft_strlen.c			\
				ft_str/ft_strncat.c			\
				ft_str/ft_strncmp.c			\
				ft_str/ft_strncpy.c			\
				ft_str/ft_strnequ.c			\
				ft_str/ft_strnew.c			\
				ft_str/ft_strnstr.c			\
				ft_str/ft_strrchr.c			\
				ft_str/ft_strsplit.c		\
				ft_str/ft_strstr.c			\
				ft_str/ft_strsub.c			\
				ft_str/ft_strtrim.c			\
\
				ft_to/ft_tolower.c			\
				ft_to/ft_toupper.c			\
				ft_to/ft_atoi.c				\
				ft_to/ft_itoa.c				\

# ---------------------------------------------------------------------------- #
# PROJECT CONFIGURATION
# ---------------------------------------------------------------------------- #

CFLAGS		=	\
				-g 								\
				-Wall -Wextra -Werror			\

# >>> REQUIRED FOR LIBRARIES >>> THINK ABOUT CHANGING THE *LIBS rules

CPPFLAGS	=	\
				-I $(DIRINC)					\

LDFLAGS		=	\

LDLIBS		=	\

# GLOBAL SETUP
AR			=	ar
CC			=	clang
RM			=	rm
MKDIR		=	mkdir
MAKE		=	make

DIRSRC		=	./srcs/
DIROBJ		=	./.objs/
DIRINC		=	./incs/
DIRLIB		=	./libs/

# EXTRA COLOR
C_DFL		=	\033[0m
C_GRA		=	\033[30m
C_RED		=	\033[31m
C_GRE		=	\033[32m
C_YEL		=	\033[33m
C_BLUE		=	\033[34m
C_MAG		=	\033[35m
C_CYA		=	\033[36m
C_WHI		=	\033[37m

# ============================================================================ #

# ---------------------------------------------------------------------------- #
# SOURCES NORMALIZATION
# ---------------------------------------------------------------------------- #

SRC			=	$(addprefix $(DIRSRC), $(SRCS))
OBJ			=	$(addprefix $(DIROBJ), $(notdir $(SRC:.c=.o)))

# ---------------------------------------------------------------------------- #
# RULES
# ---------------------------------------------------------------------------- #

all			:	libs $(NAME)

$(NAME)		:	$(DIROBJ) $(OBJ)
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) linking objects\n" "$(CC)"
	@$(AR) rc $(NAME) $(OBJ)
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) index project\n" "ranlib"
	@ranlib $(NAME)

# ---------------------------------------------------------------------------- #
# CUSTOMISABLE RULES

libs		:

fcleanlibs	:

# ---------------------------------------------------------------------------- #

clean		:
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) remove objects\n" "$(RM)"
	@$(RM) -rf $(DIROBJ)

fclean		:	fcleanlibs clean
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) remove binaries\n" "$(RM)"
	@$(RM) -f $(NAME)

re			:	fclean all

$(DIROBJ)	:
	@$(MKDIR) -p $(DIROBJ)

depend		:
	@sed -e '/^#start/,/^end/d' Makefile > .mftmp && mv .mftmp Makefile
	@printf "#start\n\n" >> Makefile
	@$(foreach s, $(SRC),													\
		printf '$$(DIROBJ)'										>> Makefile	&& \
		$(CC) -MM $(s) $(CPPFLAGS)								>> Makefile	&& \
																			\
		printf '\t\t@printf "$$(C_GRE)[ $(NAME) ] '				>> Makefile && \
		printf '[ %%-6s ]$$(C_DFL) " "$(CC)"\n'					>> Makefile && \
		printf '\t\t@printf "compiling $(s)\\n"\n'				>> Makefile	&& \
																			\
		printf '\t\t@$$(CC) -c $(s) -o '						>> Makefile	&& \
		printf '$(addprefix $(DIROBJ), $(notdir $(s:.c=.o))) '	>> Makefile	&& \
		printf '$$(CPPFLAGS) $$(CFLAGS) \n\n'					>> Makefile	&& \
																			\
		printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) " "dep"				&& \
		printf "$(s) rule generated\n"										|| \
																			\
		(sed -e '/^#start/,$$d' Makefile > .mftmp && mv .mftmp Makefile		&& \
		printf "#start\n\n"										>> Makefile	&& \
		printf "$(C_RED)[ $(NAME) ] [ %-6s ]$(C_DFL) " "dep"				&& \
		printf "$(s) rule generation failed\n"								) \
	;)
	@printf "\n#end\n" >> Makefile

.PHONY	:	 libs

# ---------------------------------------------------------------------------- #
# AUTO-GENERATED SECTION - do not modify
# ---------------------------------------------------------------------------- #

#start

$(DIROBJ)get_next_line.o: srcs/get_next_line.c incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/get_next_line.c\n"
		@$(CC) -c ./srcs/get_next_line.c -o ./.objs/get_next_line.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_arrdel.o: srcs/ft_arr/ft_arrdel.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_arr/ft_arrdel.c\n"
		@$(CC) -c ./srcs/ft_arr/ft_arrdel.c -o ./.objs/ft_arrdel.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_arrlen.o: srcs/ft_arr/ft_arrlen.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_arr/ft_arrlen.c\n"
		@$(CC) -c ./srcs/ft_arr/ft_arrlen.c -o ./.objs/ft_arrlen.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_array_dup.o: srcs/ft_arr/ft_array_dup.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_arr/ft_array_dup.c\n"
		@$(CC) -c ./srcs/ft_arr/ft_array_dup.c -o ./.objs/ft_array_dup.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_array_indexof.o: srcs/ft_arr/ft_array_indexof.c incs/libft.h \
  incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_arr/ft_array_indexof.c\n"
		@$(CC) -c ./srcs/ft_arr/ft_array_indexof.c -o ./.objs/ft_array_indexof.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_array_push_back.o: srcs/ft_arr/ft_array_push_back.c incs/libft.h \
  incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_arr/ft_array_push_back.c\n"
		@$(CC) -c ./srcs/ft_arr/ft_array_push_back.c -o ./.objs/ft_array_push_back.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_array_push_front.o: srcs/ft_arr/ft_array_push_front.c incs/libft.h \
  incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_arr/ft_array_push_front.c\n"
		@$(CC) -c ./srcs/ft_arr/ft_array_push_front.c -o ./.objs/ft_array_push_front.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_array_push_index.o: srcs/ft_arr/ft_array_push_index.c incs/libft.h \
  incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_arr/ft_array_push_index.c\n"
		@$(CC) -c ./srcs/ft_arr/ft_array_push_index.c -o ./.objs/ft_array_push_index.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_count_char.o: srcs/ft_count/ft_count_char.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_count/ft_count_char.c\n"
		@$(CC) -c ./srcs/ft_count/ft_count_char.c -o ./.objs/ft_count_char.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_count_word.o: srcs/ft_count/ft_count_word.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_count/ft_count_word.c\n"
		@$(CC) -c ./srcs/ft_count/ft_count_word.c -o ./.objs/ft_count_word.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_isalnum.o: srcs/ft_is/ft_isalnum.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_is/ft_isalnum.c\n"
		@$(CC) -c ./srcs/ft_is/ft_isalnum.c -o ./.objs/ft_isalnum.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_isalpha.o: srcs/ft_is/ft_isalpha.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_is/ft_isalpha.c\n"
		@$(CC) -c ./srcs/ft_is/ft_isalpha.c -o ./.objs/ft_isalpha.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_isascii.o: srcs/ft_is/ft_isascii.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_is/ft_isascii.c\n"
		@$(CC) -c ./srcs/ft_is/ft_isascii.c -o ./.objs/ft_isascii.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_isdigit.o: srcs/ft_is/ft_isdigit.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_is/ft_isdigit.c\n"
		@$(CC) -c ./srcs/ft_is/ft_isdigit.c -o ./.objs/ft_isdigit.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_isprint.o: srcs/ft_is/ft_isprint.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_is/ft_isprint.c\n"
		@$(CC) -c ./srcs/ft_is/ft_isprint.c -o ./.objs/ft_isprint.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_isspace.o: srcs/ft_is/ft_isspace.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_is/ft_isspace.c\n"
		@$(CC) -c ./srcs/ft_is/ft_isspace.c -o ./.objs/ft_isspace.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_memdel.o: srcs/ft_mem/ft_memdel.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_mem/ft_memdel.c\n"
		@$(CC) -c ./srcs/ft_mem/ft_memdel.c -o ./.objs/ft_memdel.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_memset.o: srcs/ft_mem/ft_memset.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_mem/ft_memset.c\n"
		@$(CC) -c ./srcs/ft_mem/ft_memset.c -o ./.objs/ft_memset.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_smalloc.o: srcs/ft_mem/ft_smalloc.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_mem/ft_smalloc.c\n"
		@$(CC) -c ./srcs/ft_mem/ft_smalloc.c -o ./.objs/ft_smalloc.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_putarray.o: srcs/ft_put/ft_putarray.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_put/ft_putarray.c\n"
		@$(CC) -c ./srcs/ft_put/ft_putarray.c -o ./.objs/ft_putarray.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_putarray_fd.o: srcs/ft_put/ft_putarray_fd.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_put/ft_putarray_fd.c\n"
		@$(CC) -c ./srcs/ft_put/ft_putarray_fd.c -o ./.objs/ft_putarray_fd.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_putchar.o: srcs/ft_put/ft_putchar.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_put/ft_putchar.c\n"
		@$(CC) -c ./srcs/ft_put/ft_putchar.c -o ./.objs/ft_putchar.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_putchar_fd.o: srcs/ft_put/ft_putchar_fd.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_put/ft_putchar_fd.c\n"
		@$(CC) -c ./srcs/ft_put/ft_putchar_fd.c -o ./.objs/ft_putchar_fd.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_putendl.o: srcs/ft_put/ft_putendl.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_put/ft_putendl.c\n"
		@$(CC) -c ./srcs/ft_put/ft_putendl.c -o ./.objs/ft_putendl.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_putendl_fd.o: srcs/ft_put/ft_putendl_fd.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_put/ft_putendl_fd.c\n"
		@$(CC) -c ./srcs/ft_put/ft_putendl_fd.c -o ./.objs/ft_putendl_fd.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_putnbr.o: srcs/ft_put/ft_putnbr.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_put/ft_putnbr.c\n"
		@$(CC) -c ./srcs/ft_put/ft_putnbr.c -o ./.objs/ft_putnbr.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_putnbr_fd.o: srcs/ft_put/ft_putnbr_fd.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_put/ft_putnbr_fd.c\n"
		@$(CC) -c ./srcs/ft_put/ft_putnbr_fd.c -o ./.objs/ft_putnbr_fd.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_putnchar.o: srcs/ft_put/ft_putnchar.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_put/ft_putnchar.c\n"
		@$(CC) -c ./srcs/ft_put/ft_putnchar.c -o ./.objs/ft_putnchar.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_putstr.o: srcs/ft_put/ft_putstr.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_put/ft_putstr.c\n"
		@$(CC) -c ./srcs/ft_put/ft_putstr.c -o ./.objs/ft_putstr.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_putstr_fd.o: srcs/ft_put/ft_putstr_fd.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_put/ft_putstr_fd.c\n"
		@$(CC) -c ./srcs/ft_put/ft_putstr_fd.c -o ./.objs/ft_putstr_fd.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_str_is.o: srcs/ft_str/ft_str_is.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_str_is.c\n"
		@$(CC) -c ./srcs/ft_str/ft_str_is.c -o ./.objs/ft_str_is.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strcat.o: srcs/ft_str/ft_strcat.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strcat.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strcat.c -o ./.objs/ft_strcat.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strchr.o: srcs/ft_str/ft_strchr.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strchr.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strchr.c -o ./.objs/ft_strchr.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strclean.o: srcs/ft_str/ft_strclean.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strclean.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strclean.c -o ./.objs/ft_strclean.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strclr.o: srcs/ft_str/ft_strclr.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strclr.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strclr.c -o ./.objs/ft_strclr.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strcmp.o: srcs/ft_str/ft_strcmp.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strcmp.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strcmp.c -o ./.objs/ft_strcmp.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strcpy.o: srcs/ft_str/ft_strcpy.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strcpy.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strcpy.c -o ./.objs/ft_strcpy.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strdel.o: srcs/ft_str/ft_strdel.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strdel.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strdel.c -o ./.objs/ft_strdel.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strdup.o: srcs/ft_str/ft_strdup.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strdup.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strdup.c -o ./.objs/ft_strdup.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strequ.o: srcs/ft_str/ft_strequ.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strequ.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strequ.c -o ./.objs/ft_strequ.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_striteri.o: srcs/ft_str/ft_striteri.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_striteri.c\n"
		@$(CC) -c ./srcs/ft_str/ft_striteri.c -o ./.objs/ft_striteri.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strjoin.o: srcs/ft_str/ft_strjoin.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strjoin.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strjoin.c -o ./.objs/ft_strjoin.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strlcat.o: srcs/ft_str/ft_strlcat.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strlcat.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strlcat.c -o ./.objs/ft_strlcat.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strlen.o: srcs/ft_str/ft_strlen.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strlen.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strlen.c -o ./.objs/ft_strlen.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strncat.o: srcs/ft_str/ft_strncat.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strncat.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strncat.c -o ./.objs/ft_strncat.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strncmp.o: srcs/ft_str/ft_strncmp.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strncmp.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strncmp.c -o ./.objs/ft_strncmp.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strncpy.o: srcs/ft_str/ft_strncpy.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strncpy.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strncpy.c -o ./.objs/ft_strncpy.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strnequ.o: srcs/ft_str/ft_strnequ.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strnequ.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strnequ.c -o ./.objs/ft_strnequ.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strnew.o: srcs/ft_str/ft_strnew.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strnew.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strnew.c -o ./.objs/ft_strnew.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strnstr.o: srcs/ft_str/ft_strnstr.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strnstr.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strnstr.c -o ./.objs/ft_strnstr.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strrchr.o: srcs/ft_str/ft_strrchr.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strrchr.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strrchr.c -o ./.objs/ft_strrchr.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strsplit.o: srcs/ft_str/ft_strsplit.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strsplit.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strsplit.c -o ./.objs/ft_strsplit.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strstr.o: srcs/ft_str/ft_strstr.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strstr.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strstr.c -o ./.objs/ft_strstr.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strsub.o: srcs/ft_str/ft_strsub.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strsub.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strsub.c -o ./.objs/ft_strsub.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_strtrim.o: srcs/ft_str/ft_strtrim.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_str/ft_strtrim.c\n"
		@$(CC) -c ./srcs/ft_str/ft_strtrim.c -o ./.objs/ft_strtrim.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_tolower.o: srcs/ft_to/ft_tolower.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_to/ft_tolower.c\n"
		@$(CC) -c ./srcs/ft_to/ft_tolower.c -o ./.objs/ft_tolower.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_toupper.o: srcs/ft_to/ft_toupper.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_to/ft_toupper.c\n"
		@$(CC) -c ./srcs/ft_to/ft_toupper.c -o ./.objs/ft_toupper.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_atoi.o: srcs/ft_to/ft_atoi.c
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_to/ft_atoi.c\n"
		@$(CC) -c ./srcs/ft_to/ft_atoi.c -o ./.objs/ft_atoi.o $(CPPFLAGS) $(CFLAGS)

$(DIROBJ)ft_itoa.o: srcs/ft_to/ft_itoa.c incs/libft.h incs/gnl.h
		@printf "$(C_GRE)[ libft.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/ft_to/ft_itoa.c\n"
		@$(CC) -c ./srcs/ft_to/ft_itoa.c -o ./.objs/ft_itoa.o $(CPPFLAGS) $(CFLAGS)


#end
