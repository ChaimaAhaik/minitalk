NAME:= server

CLIENT := client

B_SERVER := server_bonus

B_CLIENT := client_bonus

CC := cc

CFLAGS := -Wall -Wextra -Werror

SERVER_SRCS := mandatory/server.c mandatory/ft_printf.c mandatory/sigfunc.c \

CLIENT_SRCS := mandatory/client.c mandatory/ft_printf.c mandatory/sigfunc.c \

SERVER_B_SRCS := bonus/server_bonus.c bonus/ft_printf_bonus.c bonus/sigfunc_bonus.c \

CLIENT_B_SRCS := bonus/client_bonus.c bonus/ft_printf_bonus.c bonus/sigfunc_bonus.c \

SERV_OBJ = $(SERVER_SRCS:.c=.o)

CLT_OBJ = $(CLIENT_SRCS:.c=.o)

SERV_B_OBJ = $(SERVER_B_SRCS:.c=.o)

CLT_B_OBJ = $(CLIENT_B_SRCS:.c=.o)

all : $(NAME) $(CLIENT)

bonus : $(B_SERVER) $(B_CLIENT)

$(NAME) : $(SERV_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SERV_OBJ)

$(CLIENT) : $(CLT_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLT_OBJ)

$(B_SERVER) : $(SERV_B_OBJ)
	$(CC) $(CFLAGS) -o $(B_SERVER) $(SERV_B_OBJ)

$(B_CLIENT) : $(CLT_B_OBJ)
	$(CC) $(CFLAGS) -o $(B_CLIENT) $(CLT_B_OBJ)

mandatory/%.o : mandatory/%.c mandatory/minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c bonus/minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(SERV_OBJ) $(CLT_OBJ) $(SERV_B_OBJ) $(CLT_B_OBJ)

fclean : clean
	rm -f $(NAME) $(CLIENT) $(B_SERVER) $(B_CLIENT)

re : fclean all