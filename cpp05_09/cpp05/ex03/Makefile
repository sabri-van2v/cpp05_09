SRCS = main.cpp Bureaucrat.cpp Form.cpp \
ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
PresidentialPardonForm.cpp Intern.cpp

OBJS = 	${SRCS:%.cpp=%.o}

NAME =	Intern

CC 	= 	c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = Bureaucrat.hpp Form.hpp \
ShrubberyCreationForm.hpp RobotomyRequestForm.hpp \
PresidentialPardonForm.hpp Intern.hpp

%.o: %.cpp ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@ -I.

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	 rm -rf ${OBJS}

fclean: clean
	 ${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re