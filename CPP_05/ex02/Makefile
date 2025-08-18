# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 23:28:02 by aoo               #+#    #+#              #
#    Updated: 2025/08/19 06:04:50 by aoo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat
CXX = c++
CXXFLAGS =  -std=c++98 #-Wall -Wextra -Werror
RM = rm -rf

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentalPardonForm.cpp


OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
