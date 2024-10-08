#include <unistd.h>

void ft_putnbr(int nbr) //рекурсия, чтобы вывести целое число на экран
{
    char digit;
    if(nbr >= 10) // если число больше 10 
        ft_putnbr(nbr/10); // функция вызывает саму себя и делит число на 10, это срезает старшие разряды числа, пока оно не станет меньше 10
    digit = (nbr % 10) + '0'; //с помощью  % находим последнюю цифру числа и прибавл '0' чтобы преобразовать цифру в символ АСки
    write(1, &digit, 1); // выводим эту цифру на экран
}

int main(int ac, char *av[])
{
    (void)av; // преудпреждаем компилятор, что перемен av не используется

    ft_putnbr(ac - 1); // вызываем рекурсию, кот выводит кол-во арг программы, исключая ее имя
    write(1, "\n", 1);
    return(0);
}