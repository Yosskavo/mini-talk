NAME = server

NAME2 = client

SRC = ft_printf/ft_countnbr.c       ft_printf/ft_putnbr_base.c  ft_printf/ft_strlen.c \
      ft_printf/ft_nbr.c       ft_printf/ft_putadress.c  ft_printf/ft_putone.c       ft_printf/ft_unint.c\
      ft_printf/ft_printf.c    ft_printf/ft_putchar.c    ft_printf/ft_putstr.c

SE = server.c

CL = client.c

OBJ = $(SRC:.c=.o)

NAMEO1 = $(SE:.c=.o)

NAMEO2 = $(CL:.c=.o)

all : $(OBJ) $(NAMEO1) $(NAMEO2) $(NAME)

$(NAME) : 
	cc -Wall -Wextra -Werror $(NAMEO1) $(OBJ) -o $(NAME)
	cc -Wall -Wextra -Werror $(NAMEO2) $(OBJ) -o $(NAME2)

clean : 
	@rm -f $(OBJ) $(NAMEO1) $(NAMEO2)

fclean : clean
	@rm -f $(NAME) $(NAME2)

re : fclean all

.PHONY : re all clean fclean
