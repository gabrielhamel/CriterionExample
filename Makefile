SRC = printer.c \
	  str_to_word_array.c

TEST =	tests/tests_printer.c \
		tests/tests.c

OBJ = $(SRC:.c=.o)

OBJ_TEST = $(TEST:.c=.o)

CFLAGS += -I .
LDLIBS += -lcriterion --coverage

TEST_BIN = unit-tests

tests_run: $(OBJ) $(OBJ_TEST)
	$(CC) -o $(TEST_BIN) $(OBJ) $(OBJ_TEST) $(LDLIBS)
	./$(TEST_BIN)

clean:
	rm -f $(OBJ) $(OBJ_TEST)
	rm -rf *.gc*

fclean: clean
	rm -f $(TEST_BIN)

%.o : %.c
	$(CC) -c -o $@ $^ $(LDLIBS)
