NAME = PhoneBook
CXX = g++
OBJDIR = objects

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = src/main.cpp \
			src/PhoneBook_class.cpp \
			src/Contact_class.cpp

OBJECTS = $(SOURCES:src/%.cpp=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

dev : fclean
	git add .; git commit -m "CPP00/ex01 - auto/dev"; git push --force

.PHONY: all clean fclean re