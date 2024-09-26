#include <unistd.h>

int ft_atoi(char *str) //преобразует строку в наст число
{
    int sign = 1; //для проверки знака числа
    int result = 0;

    while(*str == ' ' || (*str >= 9 && *str <= 13)) // пока знак пробел или пробельн символ
        str++; //идем дальше
    if(*str == '-') // если знак -
        sign = -1; //меняем значение sign на минус
    if(*str == '-' || *str == '+') //если был - или + просто идем дальше
        str++;
    while(*str >= '0' && *str <= '9') // пока символ от 0 до 9
    {
        result = result * 10 + *str - '0'; // преобразов символы в реальное число и сохр в результат
        str++; // идем к след символу
    }
    return(sign * result);    //выводим знак на результат, чтобы показать - если он будет в числе
}