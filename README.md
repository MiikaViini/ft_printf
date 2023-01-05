# ft_printf
Implementation of C library printf() functions

First project of Algorithm -branch.

Task was to recreate standard library function printf.
This project thaught me about parsing, floating points and
variadic functions. Also i got really familiar with `LLDB`
https://lldb.llvm.org/

Major struggle was to find all possible edge cases and cover them.
These were found by unittest made by other peers in Hive Helsinki fe.:
https://github.com/satukoskinen/printf_test
This tests for various cases and also for possible memory leaks.

I managed cover most of the cases, there is few things left to improve
with long double.

Usage:

1. Clone the repository
```
git clone https://github.com/MiikaViini/ft_printf.git
```
2. Compile the project (run command in project directory)
```
make
```
3. Call the function in your .c file fe.
```
int main() 
{
  char *string = "Wollo Herld";
  int x = 5 + 6;
  
  ft_printf("This is the string %s and this is the integer %d", string, x);
  
  return 0;
}
```
4. You have static library and you can compile it with your main.c fe.
```
gcc libftprintf.a main.c
```
