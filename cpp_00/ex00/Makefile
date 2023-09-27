# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 00:06:41 by jmatheis          #+#    #+#              #
#    Updated: 2023/09/28 00:06:50 by jmatheis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= megaphone

CXX			:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98

SRCS		:= megaphone.cpp

OBJS		:= $(SRCS:%.cpp=%.o)

# ************************************** #
#   COLORS                               #
# ************************************** #
RED			=	\e[91;5;118m
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m

# ************************************** #
#   RULES                                #
# ************************************** #

.PHONY: all clean fclean re

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@printf "$(GREEN)Successful compilation\n$(RESET)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all