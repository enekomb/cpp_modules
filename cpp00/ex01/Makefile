# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 20:44:47 by eneko             #+#    #+#              #
#    Updated: 2025/03/04 11:42:52 by emunoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

CC		=	g++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp		\
			Contact.cpp		\
			PhoneBook.cpp	\

INC		= 	Contact.hpp		\
			PhoneBook.hpp	\
 
OBJS	=	$(SRC:.cpp=.o)

# Colors
YELLOW	=	\033[1;33m
CYAN	=	\033[1;36m
GREEN	=	\033[1;32m
RESET	=	\033[0m

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Program $(NAME) compiled successfully!$(RESET)"
	@echo "$(CYAN)"	
	@echo "   ____  _____ _____ _____  ______    "
	@echo "  / ___||  __ |  __  \ __ \|  __  \   "
	@echo " | |    | |__) | |__) |  | | |  | |   "
	@echo " | |___ |  ___/|  ___/|__| | |__| |   "
	@echo "  \____||_|    |_|  |______|______|   "      
	@echo "                                      "
	@echo "               by emunoz              "
	@echo "	$(RESET)"

%.o: %.cpp
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(CYAN)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)Program $(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
