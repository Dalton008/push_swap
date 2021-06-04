NAME = push_swap

HEADER = push_swap.h

LIST = ft_atoi.c operations_combo.c operations.c push_swap.c\
	sort.c work_with_lst.c work_with_mas.c get_num1_work.c\
	print_comand.c utils.c if_last_elem_b.c get_count_comands.c\
	work_with_flags.c work_with_m_1h.c 	work_with_m_2h.c ft_split.c\
	check_argv.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(LIST:.c=.o)

.PHONY : all clean fclean re

OPTFLAGS = -O2

all : $(NAME)

${NAME} : ${LIST}
	gcc $(FLAGS) -o $(NAME) ${LIST}

%.o : %.c $(HEADER)
	gcc $(OPTFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all