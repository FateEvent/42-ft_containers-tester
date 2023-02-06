# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swalter <swalter@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 15:13:32 by swalter           #+#    #+#              #
#    Updated: 2022/10/30 10:40:28 by swalter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME				= ft_containers-tester

CLIENT2				= ft_vector
CLIENT1				= std_vector
CLIENT3				= ft_map
CLIENT4				= std_map
CLIENT5				= ft_stack
CLIENT6				= std_stack
CLIENT7				= ft_set
CLIENT8				= std_set

LOGS_PATH			= logs/



define NL

endef
TARGET = 1 2 3 4 5 6 7 8 9

CLIENT9				= test_container

INCLUDE				= -I./includes/

SRC_CLIENT1			= vector_tests_std.cpp
OBJ_CLIENT1			= $(SRC_CLIENT1:.cpp=.o)

SRC_CLIENT2			= vector_tests_ft.cpp
OBJ_CLIENT2			= $(SRC_CLIENT2:.cpp=.o)

SRC_CLIENT3			= map_tests_ft.cpp
OBJ_CLIENT3			= $(SRC_CLIENT3:.cpp=.o)

SRC_CLIENT4			= map_tests_std.cpp
OBJ_CLIENT4			= $(SRC_CLIENT4:.cpp=.o)

SRC_CLIENT5			= stack_tests_ft.cpp
OBJ_CLIENT5			= $(SRC_CLIENT5:.cpp=.o)

SRC_CLIENT6			= stack_tests_std.cpp
OBJ_CLIENT6			= $(SRC_CLIENT6:.cpp=.o)

SRC_CLIENT7			= stack_tests_std.cpp
OBJ_CLIENT7			= $(SRC_CLIENT7:.cpp=.o)

SRC_CLIENT8			= stack_tests_std.cpp
OBJ_CLIENT8			= $(SRC_CLIENT8:.cpp=.o)

SRC_CLIENT9			= main.cpp \
					comparator.cpp \
					timer.cpp  \
					files.cpp
OBJ_CLIENT9			= $(SRC_CLIENT9:.cpp=.o)


CC					= c++
CFLAGS				= -Wall -Wextra -Werror -std=c++98
RM					= rm -rf

all: $(NAME)


$(NAME): $(foreach n, $(TARGET), $(CLIENT$(n)))

$(CLIENT1): $(OBJ_CLIENT1)
	$(CC) $(CFLAGS) -o $(CLIENT1) $(OBJ_CLIENT1) -g3 -fsanitize=address

$(CLIENT2): $(OBJ_CLIENT2)
	$(CC) $(CFLAGS) -o $(CLIENT2) $(OBJ_CLIENT2) -g3 -fsanitize=address

$(CLIENT3): $(OBJ_CLIENT3)
	$(CC) $(CFLAGS) -o $(CLIENT3) $(OBJ_CLIENT3) -g3 -fsanitize=address

$(CLIENT4): $(OBJ_CLIENT4)
	$(CC) $(CFLAGS) -o $(CLIENT4) $(OBJ_CLIENT4) -g3 -fsanitize=address

$(CLIENT5): $(OBJ_CLIENT5)
	$(CC) $(CFLAGS) -o $(CLIENT5) $(OBJ_CLIENT5) -g3 -fsanitize=address

$(CLIENT6): $(OBJ_CLIENT6)
	$(CC) $(CFLAGS) -o $(CLIENT6) $(OBJ_CLIENT6) -g3 -fsanitize=address

$(CLIENT9): $(OBJ_CLIENT9)
	$(CC) $(CFLAGS) -o $(CLIENT9) $(OBJ_CLIENT9) -g3 -fsanitize=address

$(CLIENT7): $(OBJ_CLIENT7)
	$(CC) $(CFLAGS) -o $(CLIENT7) $(OBJ_CLIENT7) -g3 -fsanitize=address

$(CLIENT8): $(OBJ_CLIENT8)
	$(CC) $(CFLAGS) -o $(CLIENT8) $(OBJ_CLIENT8) -g3 -fsanitize=address

clean:
	$(RM) $(OBJ_CLIENT1) $(OBJ_CLIENT2) $(OBJ_CLIENT3) $(OBJ_CLIENT4) $(OBJ_CLIENT5) $(OBJ_CLIENT6)  $(OBJ_CLIENT9) #$(OBJ_CLIENT7) $(OBJ_CLIENT8)

fclean: clean
	$(RM) $(LOGS_PATH) $(CLIENT1) $(CLIENT2) $(CLIENT3) $(CLIENT4) $(CLIENT5) $(CLIENT6) $(CLIENT9) #$(CLIENT7) $(CLIENT8)

re:	fclean all

.PHONY:	all clean fclean re