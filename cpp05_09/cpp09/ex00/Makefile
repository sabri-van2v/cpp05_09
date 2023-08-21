SRCS = main.cpp BitcoinExchange.cpp

OBJS = 	${SRCS:%.cpp=%.o}

NAME =	btc

CC 	= 	c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = BitcoinExchange.hpp

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