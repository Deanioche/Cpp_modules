NAME 		= ex02

CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS    	= \
			main.cpp        			\
			Bureaucrat.cpp  			\
			AForm.cpp 					\
			PresidentialPardonForm.cpp 	\
			RobotomyRequestForm.cpp 	\
			ShrubberyCreationForm.cpp

OBJS_DIR	= objs
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir $@

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f green_shrubbery

re: fclean all

.PHONY:	all clean fclean re
