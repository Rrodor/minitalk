NAMECLI= client
NAMESERV= server
SRCCLI= mt_client.c mt_client2.c
SRCSERV= mt_server.c
SRCPATH= ./cfiles/
OBJCLI= $(SRCCLI:.c=.o)
OBJSERV= $(SRCSERV:.c=.o)
OBJSCLI= $(addprefix $(OBJPATH), $(OBJCLI))
OBJSSERV= $(addprefix $(OBJPATH), $(OBJSERV))
SRCSCLI= $(addprefix $(SRCPATH), $(SRCCLI))
SRCSSERV= $(addprefix $(SRCPATH), $(SRCSERV))
OBJPATH= ./ofiles/

CC= gcc

all: makelib $(NAMECLI) $(NAMESERV)

makelib:
	make -C ./ft_printf

%.o: $(SRCPATH)%.c
	mkdir -p ofiles
	$(CC) -I./hfiles -I./ft_printf  -o $(OBJPATH)$@ -c $<

$(NAMECLI): $(OBJCLI)
	$(CC) $(OBJSCLI) -o $(NAMECLI) -Lft_printf -lftprintf -I./ft_printf -I./hfiles

$(NAMESERV): $(OBJSERV)
	$(CC) $(OBJSSERV) -o $(NAMESERV) -Lft_printf -lftprintf -I./ft_printf -I./hfiles

clean:
	rm -f $(OBJSCLI)
	rm -f $(OBJSSERV)
	rmdir ofiles
	make clean -C ./ft_printf

fclean: clean
	rm -f $(NAMECLI)
	rm -f $(NAMESERV)
	make fclean -C ./ft_printf

re: fclean all
