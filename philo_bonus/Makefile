PHILOSOPHER = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I ./inc
BUILD = build_bonus

FILES = philo_bonus time_bonus philo_utilis_fun_bonus parcing_function_bonus\
		create_process

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