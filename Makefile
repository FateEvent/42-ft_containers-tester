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


NAME				= minitalk
CLIENT2				= ft_vector
CLIENT1				= std_vector
CLIENT3				= ft_map
CLIENT4				= std_map

INCLUDE				= ./includes/


#FILES_CLIENT		= vector_tests_std.cpp
#FILES_CLIENT2		= vector_tests_ft.cpp

SRC_CLIENT1			= vector_tests_std.cpp
OBJ_CLIENT1			= $(SRC_CLIENT1:.cpp=.o)

SRC_CLIENT2			= vector_tests_ft.cpp
OBJ_CLIENT2			= $(SRC_CLIENT2:.cpp=.o)

SRC_CLIENT3			= map_tests_ft.cpp
OBJ_CLIENT3			= $(SRC_CLIENT3:.cpp=.o)

SRC_CLIENT4			= map_tests_std.cpp
OBJ_CLIENT4			= $(SRC_CLIENT4:.cpp=.o)

CC					= c++
CFLAGS				= -Wall -Wextra -Werror
RM					= rm -f


all: $(NAME)

$(NAME): $(CLIENT1) $(CLIENT2) $(CLIENT3) $(CLIENT4)

$(CLIENT1): $(OBJ_CLIENT1)

	$(CC) $(CFLAGS) -o $(CLIENT1)  $(OBJ_CLIENT1)

$(CLIENT2): $(OBJ_CLIENT2)

	$(CC) $(CFLAGS) -o $(CLIENT2)  $(OBJ_CLIENT2)

$(CLIENT3): $(OBJ_CLIENT3)

	$(CC) $(CFLAGS) -o $(CLIENT3)  $(OBJ_CLIENT3)

$(CLIENT4): $(OBJ_CLIENT4)

	$(CC) $(CFLAGS) -o $(CLIENT4)  $(OBJ_CLIENT4)

clean:

	$(RM) $(OBJ_CLIENT1) $(OBJ_CLIENT2) $(OBJ_CLIENT3) $(OBJ_CLIENT4)

fclean: clean

	$(RM) $(CLIENT1) $(CLIENT2) $(CLIENT3) $(CLIENT4)

re:	fclean all

.PHONY:	all clean fclean re