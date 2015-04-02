CXX		=	g++

CXXFLAGS=	-I./include

SRCDIR	=	./src

SRC		=	$(SRCDIR)/GPIO.cpp \
			$(SRCDIR)/main.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	rpi-gpio

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
