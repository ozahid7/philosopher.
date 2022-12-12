NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I ./inc
BUILD = build_bonus

FILES = main time utilis parsing check_death check_meals\
		create_process semaphores routine

OBJ = $(addprefix $(BUILD)/, $(FILES:=.o))

all = $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(OBJ) -o $(NAME)
$(BUILD)/%.o : src/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@ $(INC)
clean :
		rm -rf $(BUILD)
fclean : clean
		rm -rf $(NAME)
re : fclean all

.PHONY : re fclean clean all