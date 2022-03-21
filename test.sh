#!/bin/bash
make re -C libft/
make re
gcc libftprintf.a libft/libft.a main.c
./a.out
