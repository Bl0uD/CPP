NAME = megaphone
OBJDIR = objects

FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = megaphone.cpp

OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	g++ $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	g++ $(FLAGS) -o $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

dev : fclean
	git add .; git commit -m "CPP00/ex00 - auto/dev"; git push --force

.PHONY: all clean fclean re