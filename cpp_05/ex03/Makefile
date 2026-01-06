NAME = At_least_this_beats_coffee-making
OBJDIR = objects

FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = src/main.cpp \
			src/AForm.cpp \
			src/Bureaucrat.cpp \
			src/PresidentialPardonForm.cpp \
			src/RobotomyRequestForm.cpp \
			src/ShrubberyCreationForm.cpp \
			src/Intern.cpp \

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
	rm -f $(NAME) *_shrubbery

re: fclean all

dev : fclean
	@echo "Adding files from current directory only..."
	@git add . && git diff --cached --quiet || (git commit -m "CPP05/ex03 - auto/dev" && git push) || echo "No changes to commit"

.PHONY: all clean fclean re