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


chmod 777 ft_test
chmod 777 std_test
./ft_test
./std_test

./test_container

printf "${EOC}${BOLD}${DBLUE}\
# ****************************************************************************** #

#                          Copyright Fabio et Stephane                           #

# ****************************************************************************** #
${EOC}"