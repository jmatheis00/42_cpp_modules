# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 10:57:42 by jmatheis          #+#    #+#              #
#    Updated: 2023/01/11 10:57:50 by jmatheis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= myphonebook

CXX			:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98

SRCS		:= 	PhoneBook.cpp \
				main.cpp \
				Contact.cpp

HEADER		:= PhoneBook.hpp \
				Contact.hpp

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

$(NAME) : $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@printf "$(GREEN)Successful compilation\n$(RESET)"
#@printf "$(_SUCCESS) $(GREEN)Successful compilation\n$(RESET)"

%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all