#!/usr/bin/env bash

EOC="\e[0m"
BOLD="\e[1m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
DBLUE="\e[94m"
PURPLE="\e[95m"
CYAN="\e[96m"
DGREY="\e[1;90m"

printf "${EOC}${BOLD}${DBLUE}\
# ****************************************************************************** #
#                                                                                #
#                                                                                #
#                                                                                #
#                          CONTAINER TEST                                        #
#                                                                                #
#                                                                                #
#                                                                                #
#                                                                                #
#                                                                                #
# ****************************************************************************** #
${EOC}"


chmod 755 ft_vector
chmod 755 std_vector
chmod 755 ft_map
chmod 755 std_map
chmod 755 ft_stack
chmod 755 std_stack
#chmod 755 ft_stack
#chmod 755 std_stack

mkdir -p logs

./ft_vector > logs/ft_test_vector_ft.log
./std_vector > logs/ft_test_vector_std.log
./ft_map  > logs/ft_test_map_ft.log
./std_map  > logs/ft_test_map_std.log
./ft_stack > logs/ft_test_stack_ft.log
./std_stack > logs/ft_test_stack_std.log
#./ft_set > logs/ft_test_set_ft.log
#./std_set > logs/ft_test_set_std.log

./test_container

printf "${EOC}${BOLD}${DBLUE}\
# ****************************************************************************** #

#                          Copyright Fabio et Stephane                           #

# ****************************************************************************** #
${EOC}"