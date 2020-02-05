INC_DIR =	include

SRC_DIR =	src

SRC =		$(SRC_DIR)/printer.c \
			$(SRC_DIR)/count_word.c

SRC_MAIN =	$(SRC_DIR)/main.c

TEST_DIR =	tests

TEST =		$(TEST_DIR)/count_word.c \
			$(TEST_DIR)/printer.c

OBJ =		$(SRC:.c=.o)

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

OBJ_TEST =	$(TEST:.c=.o)

CFLAGS +=	-I $(INC_DIR)

TEST_BIN =	unit-tests

BIN =		bin

all:		$(OBJ) $(OBJ_MAIN)
	$(CC) -o $(BIN) $(OBJ) $(OBJ_MAIN)

tests_run:	$(OBJ) $(OBJ_TEST)
	$(CC) -o $(TEST_BIN) $(OBJ) $(OBJ_TEST) --coverage -lcriterion
	./$(TEST_BIN)

clean:
	$(RM) $(OBJ) $(OBJ_TEST) $(OBJ_MAIN)
	$(RM) $(SRC:.c=.gcno)
	$(RM) $(SRC:.c=.gcda)
	$(RM) $(TEST:.c=.gcno)
	$(RM) $(TEST:.c=.gcda)

fclean:		clean
	$(RM) $(TEST_BIN)
	$(RM) $(BIN)

re:			fclean all
