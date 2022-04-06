#!/bin/bash
make re -C libft/
make re
gcc libftprintf.a  main2.c -g
./a.out
