INC_DIR =	include

SRC_DIR =	src

SRC =		$(SRC_DIR)/printer.c \
			$(SRC_DIR)/count_word.c

SRC_MAIN =	$(SRC_DIR)/main.c

TEST_DIR =	tests

TEST =		$(TEST_DIR)/tests_count_word.c \
			$(TEST_DIR)/tests_printer.c

OBJ =		$(SRC:.c=.o)

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

CFLAGS +=	-I $(INC_DIR) -Wall -Wextra

LDFLAGS +=

TEST_BIN =	unit-tests

BIN =		bin

all:		$(OBJ) $(OBJ_MAIN)
	$(CC) -o $(BIN) $(OBJ) $(OBJ_MAIN) $(LDFLAGS)

debug:
	$(CC) -o $(BIN) $(SRC) $(SRC_MAIN) $(CFLAGS) $(LDFLAGS) -g

tests_run:
	$(CC) -o $(TEST_BIN) $(SRC) $(TEST) $(CFLAGS) --coverage -lcriterion $(LDFLAGS)
	./$(TEST_BIN)

clean:
	$(RM) $(OBJ) $(OBJ_MAIN)
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

fclean:		clean
	$(RM) $(TEST_BIN)
	$(RM) $(BIN)

re:			fclean all
