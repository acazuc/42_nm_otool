# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/09/21 10:45:49 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_NM = ft_nm

NAME_OTOOL = ft_otool

CFLAGS = -Wall -Wextra -Werror -Ofast -g

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = src/

COM_SRCS_NAME = file_parse.c \
				buffer.c \
				file_error.c \
				archive_parse.c \
				archive_parse_file_header.c \
				archive_parse_symdef.c \
				archive_files_push_back.c \
				object_parse.c \
				object_parse_commands.c \
				object_parse_command_symtab.c \
				object_parse_command_segment.c \
				print_hex.c \
				struct_free.c \
				fat_parse.c \
				fat_header_reverse.c \
				fat_arch_reverse.c \
				fat_files_push_back.c \
				struct_object_header_read.c \
				struct_mach_header_reverse.c \
				struct_symbol_read.c \
				struct_symbol_list_push_back.c \
				struct_symbol_list_reverse.c \
				struct_nlist_reverse.c \
				struct_segment_read.c \
				struct_segment_command_reverse.c \
				struct_segment_list_push_back.c \
				struct_section_read.c \
				struct_section_reverse.c \
				struct_section_list_push_back.c \

COM_SRCS = $(addprefix $(SRCS_PATH), $(COM_SRCS_NAME))

NM_SRCS_NAME = main.c \
			ft_nm.c \
			archive_print.c \
			object_print.c \
			object_print_symbol_value.c \
			object_print_symbol_sect_letter.c \
			get_section_by_index.c \
			get_symbol_letter.c \
			fat_print.c \
			parse_arguments.c \

NM_SRCS = $(addprefix $(SRCS_PATH), $(NM_SRCS_NAME))

OTOOL_SRCS_NAME = main.c \

OTOOL_SRCS = $(addprefix $(SRCS_PATH), $(OTOOL_SRCS_NAME))

OBJS_PATH = obj/

COM_OBJS_NAME = $(COM_SRCS_NAME:.c=.o)

COM_OBJS = $(addprefix $(OBJS_PATH), $(COM_OBJS_NAME))

NM_OBJS_NAME = $(NM_SRCS_NAME:.c=.o)

NM_OBJS = $(addprefix $(OBJS_PATH), $(NM_OBJS_NAME))

OTOOL_OBJS_NAME = $(OTOOL_SRCS_NAME:.c=.o)

OTOOL_OBJS = $(addprefix $(OBJS_PATH), $(OTOOL_OBJS_NAME))

LIBRARY = -L libft/ -lft

all: odir $(NAME_NM) $(NAME_OTOOL)

$(NAME_NM): $(NM_OBJS) $(COM_OBJS)
	@Make -C libft
	@echo " - Making $(NAME_NM)"
	@$(CC) $(CFLAGS) -o $(NAME_NM) $^ $(LIBRARY) -I$(INCLUDES_PATH)

$(NAME_OTOOL): $(OTOOL_OBJS) $(COM_OBJS)
	@Make -C libft
	@echo " - Making $(NAME_OTOOL)"
	@$(CC) $(CFLAGS) -o $(NAME_OTOOL) $^ $(LIBRARY) -I$(INCLUDES_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)
clean:
	@Make clean -C libft/
	@echo " - Clearing objects files"
	@rm -f $(NM_OBJS)
	@rm -f $(OTOOL_OBJS)
	@rm -f $(COM_OBJS)

fclean: clean
	@Make fclean -C libft/
	@echo " - Clearing executables file"
	@rm -f $(NM_NAME)
	@rm -f $(OTOOL_NAME)

re: fclean all

.PHONY: clean fclean re odir
