# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 23:19:50 by bmangin           #+#    #+#              #
#    Updated: 2021/09/28 15:39:13 bmangin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******************************************************* #
# *********************   VARIABLES   ******************* #
# ******************************************************* #

NAME		:= push_swap

PATH_L		:= libft
PATH_I		:= includes
PATH_S		:= srcs
PATH_B		:= .bin

VPATH		= ${PATH_I} ${PATH_S} ${PATH_B} ${PATH_L}

FILES		= main.c get_array.c init_global.c tools.c \
			tools_instr.c push.c swap.c rotate.c reverse.c \
			tools_sort.c big_sort.c small_sort.c search_num.c \
			test.c

C_FILES		= get_array.c init_global.c tools_sort.c tools.c \
			tools_instr.c checker.c push.c swap.c rotate.c \
			reverse.c

SRCS		= ${addprefix ${PATH_S}/, ${FILES}}
C_SRCS		= ${addprefix ${PATH_S}/, ${C_FILES}}
OBJS		= ${FILES:.c=.o}
C_OBJS		= ${C_FILES:.c=.o}
BIN			= ${addprefix ${PATH_B}/, ${OBJS}}
C_BIN		= ${addprefix ${PATH_B}/, ${C_OBJS}}

H_FILES		= push_swap.h instruction.h checker.h
HEADER		= ${addprefix ${PATH_I}/, ${H_FILES}}

LIBFT_NAME	:= ${PATH_L}.a
LIBFT		= ${addprefix ${PATH_L}/, ${LIBFT_NAME}}

# ******************************************************* #
# *******************   COMMANDES   ********************* #
# ******************************************************* #

CC			:= clang
FLAGS		:= -Wall -Wextra -Werror
CCF			:= ${CC} ${FLAGS} -glldb
CFFS		:= ${CCF} -fsanitize=address
INC			:= -I${PATH_I} -I${PATH_L}/${PATH_I}
FLIB		:= -L${PATH_L}
LFT			:= -lft
MAKE		:= make -C
CP			:= cp 
MKDIR		:= mkdir -p
RM			:= rm -rf
NORM		:= norminette

# ******************************************************* #
# *******************   MAKE SHIT   ********************* #
# ******************************************************* #

all:	${NAME}
	echo ${INC}

lib:		crea_b
		${MAKE} ./${PATH_L}/

${PATH_B}/%.o:	${PATH_S}/%.c ${HEADER}
		${CCF} ${INC} -c $< -o $@

${NAME}:	lib ${BIN} ${C_BIN} ${HEADER}
		${CCF} ${FLIB} ${BIN} -o $@ ${LFT}
		${CCF} ${FLIB} ${C_BIN} -o checker ${LFT}

fs:			lib ${BIN} ${C_BIN} ${HEADER}
		${CFFS} ${FLIB} ${BIN} -o ${NAME} ${LFT}
		${CFFS} ${FLIB} ${C_BIN} -o checker ${LFT}

crea_b :
	${shell mkdir -p ${PATH_B}}

clean:
	$(MAKE) ./$(PATH_L)/ clean
	$(RM) $(PATH_B)

fclean: clean
	$(MAKE) ./$(PATH_L)/ fclean
	$(RM) $(NAME) $(NAME).dSYM checker checker.dSYM

re: fclean all

seg: fclean fs

norm:
	${NORM} ${SRCS} ${C_SRCS} ${HEADER}
	$(MAKE) ./$(PATH_L) norm
	
.PHONY:		all lib crea_b bonus clean fclean re seg norm

#NAME = push_swap
#
#override L_PATH		:= libft
#override I_PATH		:= includes
#override S_PATH		:= srcs
#override B_PATH		:= .bin
#
#VPATH		= libft
#			includes
#			srcs
#			bin
#
#FILES		= main.c reverse.c rotate.c push.c swap.c tools.c test.c
#
#SRCS		= ${addprefix ${S_PATH}/, ${FILES}}
#OBJS		= ${addprefix ${B_PATH}/, ${notdir ${SRCS:.c=.o}}}
#
#INC_FILES 	= push_swap.h instruction.h
#INC			= ${addprefix ${I_PATH}/, ${INC_FILES}}
#
#LIBFT_NAME	= libft.a
#LIBFT		= ${addprefix ${L_PATH}/, ${LIBFT_NAME}}
#
#CC			:= clang
#FLAGS		:= -Wall -Wextra -Werror 
#FLAGS_FS	:= -Wall -Wextra -Werror -g3 -fsanitize=address
#MAKE		:= make -C
#CP			:= cp 
#RM			:= rm -rf
#
#all:		lib ${NAME}
#
#lib:		crea_b
#		${MAKE} ${L_PATH}
#		${CP} ${LIBFT} .
#
#${B_PATH}/%.o:	%.c ${INC} 
#		${CC} ${FLAGS} -I ${I_PATH} ${LIBFT} -c $< -o $@
#
#${NAME}:	${OBJS} ${INC}
#		${CC} ${FLAGS} -I ${M_PATH} -I ${I_PATH} ${MLX} ${LIBFT} ${OBJS} -o $@
#
#fs:			${SRCS} ${INC}
#		${CC} ${FLAGS_FS} -I ${I_PATH} ${LIBFT} ${SRCS} -o ${NAME}
#
#crea_b :
#		${shell mkdir -p ${B_PATH}}
#	
#clean:
#		${RM} ${B_PATH}
#
#fclean:		clean
#		${MAKE} ${L_PATH} fclean
#		${RM} ${LIBFT_NAME}
#		${RM} ${NAME}
#
#re:			fclean all
#
#seg:		fclean lib fs
#
#.PHONY: all lib op opti fsanit fs clean fclean re bonus