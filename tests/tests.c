/**
 * @file tests.c
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-05
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <criterion/criterion.h>
#include <signal.h>

#include "header.h"

TestSuite(count_word);

Test(count_word, count_word_basic)
{
    const char *str = "salut bonsoir au revoir";
    size_t nb = count_word(str, ' ');

    cr_assert_eq(nb, 4, "Got: %d", nb);
}

Test(count_word, count_word_multiple_delimiter)
{
    const char *str = "   salut     bonsoir au    revoir";
    size_t nb = count_word(str, ' ');

    cr_assert_eq(nb, 4, "Got: %d", nb);
}

Test(count_word, count_word_delimiter_at_the_end)
{
    const char *str = "   salut     bonsoir au    revoir    ";
    size_t nb = count_word(str, ' ');

    cr_assert_eq(nb, 4, "Got: %d", nb);
}

Test(count_word, count_word_empty)
{
    const char *str = "";
    size_t nb = count_word(str, ' ');

    cr_assert_eq(nb, 0, "Got: %d", nb);
}

Test(count_word, count_word_one)
{
    const char *str = "salut";
    size_t nb = count_word(str, ' ');

    cr_assert_eq(nb, 1, "Got: %d", nb);
}

Test(count_word, null_ptr, .signal = SIGSEGV)
{
    const char *str = NULL;

    count_word(str, ' ');
}
