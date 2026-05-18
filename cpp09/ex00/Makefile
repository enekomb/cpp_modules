# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 20:03:12 by eneko             #+#    #+#              #
#    Updated: 2025/09/11 10:51:04 by emunoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	btc

CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp			\
			BitcoinExchange.cpp	\

INC		= 	BitcoinExchange.hpp	\

OBJS	=	$(SRC:.cpp=.o)

YELLOW	=	\033[1;33m
CYAN	=	\033[1;36m
GREEN	=	\033[1;32m
RESET	=	\033[0m

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Program $(NAME) compiled successfully!$(RESET)"
	@echo "$(CYAN)"	
	@echo "   ____  _____ _____ _____   _____   "  
	@echo "  / ___||  __  |  __ \ __  \/  _  \  " 
	@echo " | |    | |__) | |__) |  | |  |_| |  " 
	@echo " | |    |  ___/|  ___/|  | |\___  |  "
	@echo " | |___ | |    | |  | |__| |    | |  " 
	@echo "  \____||_|    |_|  |______|    |_|  "
	@echo "										" 
	@echo "               by emunoz             "  
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