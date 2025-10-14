NAME = I_don’t_want_to_set_the_world_on_fire
OBJDIR = objects

FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = src/main.cpp \
			src/Animal.cpp \
			src/Cat.cpp \
			src/Dog.cpp \
			src/WrongAnimal.cpp \
			src/WrongCat.cpp \

OBJECTS = $(SOURCES:src/%.cpp=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	g++ $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	g++ $(FLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	g++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

dev : fclean
	@echo "Adding files from current directory only..."
	@git add . && git diff --cached --quiet || (git commit -m "CPP04/ex01 - auto/dev" && git push) || echo "No changes to commit"

.PHONY: all clean fclean re