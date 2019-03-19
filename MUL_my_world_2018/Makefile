##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAME	=	my_world

SRC	=	main.c\
		src/event.c\
		src/drawmap.c\
		src/vertex.c\
		src/image.c\
		src/rotation.c\
		src/init.c\
		src/alloc_map.c\
		src/check_mouse.c\
		src/secondwindow.c\
		src/reset_bouton.c\
		src/other.c\
		src/boutoncolor.c\
		src/alltext.c\
		src/color.c\
		src/side_vision.c\
		src/lapus.c\

CFLAGS	=	-W -Wall -Wextra -I ./include/

LDFLAGS	=	-lcsfml-system -lcsfml-graphics -lcsfml-window -lm

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS) $(LDFLAGS)

clean	:
	rm -f *~
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re	: fclean all

all	: $(NAME)

.phony	: clean fclean all re