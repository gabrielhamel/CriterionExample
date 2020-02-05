/**
 * @file tests_printer.c
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-05
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

#include "header.h"

TestSuite(printer);

Test(printer, basic)
{
    cr_redirect_stdout();

    print(STDOUT_FILENO, "salut\n");
    cr_assert_stdout_eq_str("salut\n");
}

Test(printer, print_stderr)
{
    cr_redirect_stderr();

    print(STDERR_FILENO, "salut\n");
    cr_assert_stderr_eq_str("salut\n");
}
