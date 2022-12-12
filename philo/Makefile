PHILOSOPHER = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I ./inc
BUILD = build

FILES = main utilis parsing create_threads\
		mutex time routine check_death

OBJ = $(addprefix $(BUILD)/, $(FILES:=.o))

all = $(PHILOSOPHER)

$(PHILOSOPHER) : $(OBJ)
		$(CC) $(OBJ) -o $(PHILOSOPHER)
$(BUILD)/%.o : src/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@ $(INC)
clean :
		rm -rf $(BUILD)
fclean : clean
		rm -rf $(PHILOSOPHER)
re : fclean all

.PHONY : re fclean clean all