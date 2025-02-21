NAME = server

NAME2 = client

NAMEB = server_bonus

NAMEB1 = client_bonus

SRC = printf/ft_countnbr.c printf/ft_putnbr_base.c libft/ft_strlen.c \
      printf/ft_nbr.c printf/ft_putadress.c printf/ft_putone.c printf/ft_unint.c\
      printf/ft_printf.c printf/ft_putchar.c printf/ft_putstr.c libft/ft_atoi.c

BNS = utils.c

SE = server.c

CL = client.c

SEB = server_bonus.c

CLB = client_bonus.c

NAME1B = $(SEB:.c=.o)

NAME2B = $(CLB:.c=.o)

OBJS = $(BNS:.c=.o)

OBJ = $(SRC:.c=.o)

NAMEO1 = $(SE:.c=.o)

NAMEO2 = $(CL:.c=.o)

all : $(OBJ) $(NAMEO1) $(NAMEO2) $(NAME)

$(NAME) : 
	cc -Wall -Wextra -Werror $(NAMEO1) $(OBJ) -o $(NAME)
	cc -Wall -Wextra -Werror $(NAMEO2) $(OBJ) -o $(NAME2)

bonus : $(NAME1B) $(NAME2B) $(OBJ) $(OBJS) $(NAMEB)

$(NAMEB) :
	cc -Wall -Wextra -Werror $(NAME1B) $(OBJ) -o $(NAMEB)
	cc -Wall -Wextra -Werror $(NAME2B) $(OBJS) $(OBJ)  -o $(NAMEB1)

clean : 
	@rm -f $(OBJ) $(NAMEO1) $(NAMEO2) $(NAME2B) $(NAME1B) $(OBJS)

fclean : clean
	@rm -f $(NAME) $(NAME2)  $(NAMEB) $(NAMEB1)

re : fclean all

.PHONY : re all clean fclean
