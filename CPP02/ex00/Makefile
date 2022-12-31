NAME 		= a.out

CC			= c++
FLAGS		= -std=c++98 -Wall -Wextra -Werror

SRCS		= \
			main.cpp \
			Fixed.cpp

OBJS_DIR	= objs
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir $@

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
