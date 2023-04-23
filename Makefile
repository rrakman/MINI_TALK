C_NAME = client
S_NAME = server
C_NAME_B = client_bonus
S_NAME_B = server_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
HEADER_FILE = minitalk.h
PRINTINGLIB = utils/libftprintf.a
C_SRC = client.c utils/ft_atoi.c
S_SRC = server.c
C_OBJ = ${C_SRC:.c=.o}
S_OBJ = ${S_SRC:.c=.o}
C_SRC_B = client_bonus.c utils/ft_atoi.c
S_SRC_B = server_bonus.c
C_OBJ_B = ${C_SRC_B:.c=.o}
S_OBJ_B = ${S_SRC_B:.c=.o}

CLR_RMV:= \033[0m
RED:= \033[1;31m
GREEN:= \033[1;32m
YELLOW:= \033[1;33m
BLUE:= \033[1;34m
CYAN:= \033[1;36m
WHITE:= \033[1;37m

%.o: %.c $(HEADER_FILE)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(C_NAME) $(S_NAME)

$(C_NAME): $(C_OBJ)
	@echo "$(BLUE)Compilation of ${YELLOW}ft_printf 📝$(RED) in progress ⏳ $(CLR_RMV)"
	@make -C utils/
	@echo "$(BLUE)Compilation of ${YELLOW}ft_printf 📝$(RED) ... done ✅$(CLR_RMV)"
	@$(CC) $(C_OBJ) $(PRINTINGLIB) -o $(C_NAME)
	@echo "$(BLUE)Compilation of ${YELLOW}$(C_NAME) 👨$(RED) ... done ✅$(CLR_RMV)"

$(S_NAME): $(S_OBJ)
	@$(CC) $(S_OBJ) $(PRINTINGLIB) -o $(S_NAME)
	@echo "$(BLUE)Compilation of ${YELLOW}$(S_NAME) 🖥 $(RED) ... done ✅"

bonus: $(C_OBJ_B) $(S_OBJ_B)
	@echo "$(BLUE)Compilation of ${YELLOW}ft_printf 📝$(RED) in progress ⏳ $(CLR_RMV)"
	@make -C utils/
	@$(CC) $(S_OBJ_B) $(PRINTINGLIB) -o $(S_NAME_B)
	@$(CC) $(C_OBJ_B) $(PRINTINGLIB) -o $(C_NAME_B)
	@echo "$(BLUE)Compilation of ${YELLOW}$(S_NAME_B) $(C_NAME_B) 🖥 $(RED) ... done ✅"

clean:
	@make clean -C utils/
	@rm -rf $(C_OBJ) $(S_OBJ) $(C_OBJ_B) $(S_OBJ_B)
	@echo "$(BLUE)Cleaning of ${YELLOW}$(C_NAME) $(S_NAME) ft_printf $(RED)dot.o ... done ✅$(CLR_RMV)"

fclean: clean	
	@make fclean -C utils/
	@rm -rf $(C_NAME) $(S_NAME) $(C_NAME_B) $(S_NAME_B)
	@echo "$(BLUE)Cleaning of All ${YELLOW}$(C_NAME) $(S_NAME) ft_printf $(RED)Executables ... done ✅$(CLR_RMV)"

re: fclean all
	@echo "$(RED)Recompilation of All ${YELLOW}$(C_NAME) $(RED)Executables ... done ✅$(CLR_RMV)"
.PHONY: all re clean fclean
	@echo "$(WHITE)All ${YELLOW}$(C_NAME) $(S_NAME) $(RED)files are up to date ✅$(CLR_RMV)"
