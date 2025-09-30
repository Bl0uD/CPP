NAME = PhoneBook
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = main.cpp\
	PhoneBook_class.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

dev : fclean
	git add .; git commit -m "CPP00/ex01 - auto/dev"; git push --force

.PHONY: all clean fclean re