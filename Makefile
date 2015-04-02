CXX		=	g++

CXXFLAGS=	-I./include

SRCDIR	=	./src

SRC		=	$(SRCDIR)/GPIO.cpp			\
			$(SRCDIR)/Factory.cpp		\
			$(SRCDIR)/main.cpp			\
			$(SRCDIR)/exercise_1.cpp	\
			$(SRCDIR)/exercise_2.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	rpi-gpio

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
