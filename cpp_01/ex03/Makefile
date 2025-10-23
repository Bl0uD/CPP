NAME = Unnecessary_violence
OBJDIR = objects

FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = src/main.cpp \
			src/HumanA.cpp \
			src/HumanB.cpp \
			src/Weapon.cpp \

OBJECTS = $(SOURCES:src/%.cpp=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	c++ $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ $(FLAGS) -o $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

dev : fclean
	@echo "Adding files from current directory only..."
	@git add . && git diff --cached --quiet || (git commit -m "CPP01/ex03 - auto/dev" && git push) || echo "No changes to commit"

.PHONY: all clean fclean re