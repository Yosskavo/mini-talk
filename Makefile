NAME = server

NAME2 = client

SE = server.c

CL = client.c

SRC = printf/ft_countnbr.c printf/ft_putadress.c printf/ft_putone.c printf/ft_unint.c \
      printf/ft_putchar.c printf/ft_putstr.c printf/ft_printf.c printf/ft_putnbr_base.c \
	  printf/ft_nbr.c \
	  libft/ft_atoi.c libft/ft_strlen.c 

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
	@rm -f server $(NAME) $(NAME2)

re : fclean all

.PHONY : re all clean fclean
