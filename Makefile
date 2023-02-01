
NAME = ft_containers
FT_TESTER_NAME = ft_test
STD_TESTER_NAME = std_test
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
LINKS = test.a
LIBLINKS = -I./includes -I./test/includes
SRC_PATH = srcs/
OBJ_PATH = bin/
C_EXTENSION = .cpp



MAIN_PATH	=
MAIN_FILES 	= 	main
SRCS_FILES	+=	$(addprefix $(MAIN_PATH), $(MAIN_FILES))

SRCS_FILES_EXT 		+= 	$(addsuffix $(C_EXTENSION), $(SRCS_FILES))
SRCS 				+= 	$(addprefix $(SRC_PATH), $(SRCS_FILES_EXT))
OBJS 				= 	$(addprefix $(OBJ_PATH), $(SRCS_FILES_EXT:cpp=o))

FT_TESTER_MAIN_PATH		=
FT_TESTER_MAIN_FILES 	= 	main_ft
FT_TESTER_SRCS_FILES	+=	$(addprefix $(FT_TESTER_MAIN_PATH), $(FT_TESTER_MAIN_FILES))

FT_TESTER_SRCS_FILES_EXT 	+= 	$(addsuffix $(C_EXTENSION), $(FT_TESTER_SRCS_FILES))
FT_TESTER_SRCS 				+= 	$(addprefix $(SRC_PATH), $(FT_TESTER_SRCS_FILES_EXT))
FT_TESTER_OBJS 				= 	$(addprefix $(OBJ_PATH), $(FT_TESTER_SRCS_FILES_EXT:cpp=o))

STD_TESTER_MAIN_PATH	=
STD_TESTER_MAIN_FILES 	= 	main_std
STD_TESTER_SRCS_FILES	+=	$(addprefix $(STD_TESTER_MAIN_PATH), $(STD_TESTER_MAIN_FILES))

STD_TESTER_SRCS_FILES_EXT 		+= 	$(addsuffix $(C_EXTENSION), $(STD_TESTER_SRCS_FILES))
STD_TESTER_SRCS 				+= 	$(addprefix $(SRC_PATH), $(STD_TESTER_SRCS_FILES_EXT))
STD_TESTER_OBJS 				= 	$(addprefix $(OBJ_PATH), $(STD_TESTER_SRCS_FILES_EXT:cpp=o))


RM = rm -rf



NONE = \033[0m
HIRED = \033[31m
HIGREEN = \033[92m
HIBLUE = \033[94m
CURSIVE = \033[3m



all: $(NAME)

$(NAME):  $(OBJS) $(FT_TESTER_OBJS) $(STD_TESTER_OBJS)
	@echo "$(HIRED)Compiling ...$(NONE)"
	@$(MAKE) -sC ./test
	@mv ./test/test.a .
	@$(CC) $(LINKS) $(CFLAGS) -o $(NAME) $(OBJS)
	@$(CC) $(LINKS) $(CFLAGS) -o $(FT_TESTER_NAME) $(FT_TESTER_OBJS)
	@$(CC) $(LINKS) $(CFLAGS) -o $(STD_TESTER_NAME) $(STD_TESTER_OBJS)
	@echo "$(HIGREEN)Done.$(NONE)"

.c.o:
	@$(CC) $(FLAGS) -c ${LIBLINKS} $< -o ${<:.cpp=.o}

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} $(LIBLINKS) -c $< -o $@

clean:
	@$(RM) -r test.a $(OBJ_PATH)
	@$(MAKE) clean -C ./test

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(STD_TESTER_NAME)
	@$(RM) $(FT_TESTER_NAME)
	@$(RM) logs
	@$(MAKE) fclean -C ./test

re: fclean all

.phony: all clean fclean re