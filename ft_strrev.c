#include <unistd.h>

char *ft_strrev(char *str) //разворачивает строку, делит ее попалам и 1 знак стоновится последним, последний первым и так все
{
    int i = -1; // -1 тк в цикле вайл переходим сразу к след значению, а это должен быть 0
    int lenght = 0; // для подсчета символов в строке
    int temporary; //временный для обмена значений

    while(str[lenght]) //считаем символы в строке
        lenght++;
    while(++i < lenght/2) // если символ меньше длина / 2, то меняем символы местами
    {
        temporary = str[i]; //записываем символ начала строки во временную
        str[i] = str[lenght - 1 - i]; //затем в символ начала строки записываем символ конца
        str[lenght - 1 - i] = temporary; // потом в символ конца записываем из временной символ начала
    }
    return(str); //возвращаем указатель на измененную строку
}