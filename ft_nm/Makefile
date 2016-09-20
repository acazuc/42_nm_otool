# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/09/20 14:02:45 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm

CFLAGS = -Wall -Wextra -Werror -Ofast -g

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = src/

SRCS_NAME = main.c \
			ft_nm.c \
			parse_file.c \
			print_file.c \
			buffer.c \
			file_error.c \
			archive_parse.c \
			archive_parse_file_header.c \
			archive_parse_symdef.c \
			archive_files_push_back.c \
			archive_print.c \
			object_parse.c \
			object_parse_commands.c \
			object_parse_command_symtab.c \
			object_parse_command_segment.c \
			print_hex.c \
			print_object.c \
			struct_free.c \
			fat_parse.c \
			fat_print.c \
			fat_header_reverse.c \
			fat_arch_reverse.c \
			fat_files_push_back.c \
			struct_object_header_read.c \
			struct_mach_header_reverse.c \
			struct_symbol_read.c \
			struct_symbol_list_push_back.c \
			struct_nlist_reverse.c \
			struct_segment_read.c \
			struct_segment_command_reverse.c \
			struct_segment_list_push_back.c \
			struct_section_read.c \
			struct_section_reverse.c \
			struct_section_list_push_back.c \
			get_section_by_index.c \
			get_symbol_letter.c \
			print_object_symbol_value.c \
			print_object_symbol_sect_letter.c \
			parse_arguments.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L ../libft/ -lft

all: odir $(NAME)

$(NAME): $(OBJS)
	@Make -C ../libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) -I$(INCLUDES_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)
clean:
	@Make clean -C ../libft/
	@echo " - Clearing objects files"
	@rm -f $(OBJS)

fclean: clean
	@Make fclean -C ../libft/
	@echo " - Clearing executable file"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
