PHILOSOPHER = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I ./inc
BUILD = build

FILES = philo philo_utilis_fun parcing_function create_threads\
		mutex time 

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