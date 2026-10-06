##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## lib compiler
##

CC = gcc
EXEC = libmy.a
SRC =	concat_params.c						\
		count_valid_queens_placements.c		\
		display_errno_part_five.c			\
		display_errno_part_four.c			\
		display_errno_part_one.c			\
		display_errno_part_six.c			\
		display_errno_part_three.c			\
		display_errno_part_two.c			\
		get_color.c							\
		my_apply_on_matching_nodes.c		\
		my_apply_on_nodes.c					\
		my_arc_functions.c					\
		my_compute_factorial_it.c			\
		my_compute_factorial_rec.c			\
		my_compute_power_it.c				\
		my_compute_power_rec.c				\
		my_compute_square_root.c			\
		my_concat_list.c					\
		my_delete_nodes.c					\
		my_evil_str.c						\
		my_find_node.c						\
		my_find_prime_sup.c					\
		my_ftoa.c							\
		my_getbase.c						\
		my_getfloat.c						\
		my_getnbr.c							\
		my_isneg.c							\
		my_is_prime.c						\
		my_itoa.c							\
		my_list_size.c						\
		my_memset.c							\
		my_params_to_array.c				\
		my_params_to_list.c					\
		my_print_alpha.c					\
		my_print_comb2.c					\
		my_print_comb.c						\
		my_print_combn.c					\
		my_print_digits.c					\
		my_print_errno.c					\
		my_print_error.c					\
		my_printf.c							\
		my_print_revalpha.c					\
		my_putchar.c						\
		my_put_float.c						\
		my_put_nbr.c						\
		my_put_nbr_to_fd.c					\
		my_putstr.c							\
		my_put_unhandled.c					\
		my_rev_list.c						\
		my_revstr.c							\
		my_show_param_array.c				\
		my_show_word_array.c				\
		my_sort_int_array.c					\
		my_sqrt.c							\
		my_strcapitalize.c					\
		my_strcat.c							\
		my_strcmp.c							\
		my_strcpy.c							\
		my_str_isalpha.c					\
		my_str_islower.c					\
		my_str_isnum.c						\
		my_str_isprintable.c				\
		my_str_isupper.c					\
		my_strlen.c							\
		my_strlowcase.c						\
		my_strncat.c						\
		my_strncmp.c						\
		my_strncpy.c						\
		my_strstr.c							\
		my_str_to_word_array.c				\
		my_strupcase.c						\
		my_swap.c							\
		sub_my_printf.c						\
		swap_endian_color.c					\
		my_strtok.c							\

OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ)
	ar rc $(EXEC) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(EXEC)

re : fclean all
