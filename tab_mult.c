#include <unistd.h>

int ft_atoi(char *str)
{
    int result = 0;
    int sign = 1;

    while(*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if(*str == '+')
        str++;
    while(*str >= '0' && *str <= '9')
    {
        result = result * 10 + *str - '0';
        str++;
    }
    return(sign * result);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    if(nb/10 > 0)
        ft_putnbr(nb/10);
    ft_putchar(nb % 10 + '0');
}

int main(int ac, char *av[])
{
    int i; //счетчик для организации цикла с 1 до 9 чтобы выводить таблицу умножения
    int nbr; //для хранения числа

    if(ac != 2)
        write(1, "\n", 1);
    else
    {
        i = 1;
        nbr = ft_atoi(av[1]); //преобразуем строку в целое число
        while(i <= 9 && nbr <= 238609183) //пока i не больше 9 и пока nbr меньше или равно 2386...
        {
            ft_putnbr(i); // выводим текущий множитель
            write(1, " x ", 3); 
            ft_putnbr(nbr); // выводим наше число 
            write(1, " = ", 3);
            ft_putnbr(i * nbr); // выводим результат умножения
            write(1, "\n", 1);
            i = i+1; //увеличиваем i, чтобы повторить цикл для след множителя
        }
    }
    return(0);
}