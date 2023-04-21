NAME		:= ex02

CXX			:= c++ -fsanitize=address
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98

SRCS		:= main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \
				Brain.cpp

HEADER		:= Animal.hpp \
				Dog.hpp \
				Cat.hpp \
				WrongAnimal.hpp \
				WrongCat.hpp \
				Brain.hpp

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