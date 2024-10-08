#include <unistd.h>

void	print_bits(unsigned char octet) //функция приним аргумент и выводит его двоичное представление
{
    int i = 8; // байт состоит из 8 битов
    unsigned char bit; 

    while(i--) // цикл выполняется 8 раз, начинается с i=7 и идет до 0
    {
        bit = (octet >> i & 1) + '0'; // извлекаем бит, сдвигаем биты перемен octet на i позиций, операция &1 извлекает только самый младший бит результата сдвига и добавляем 0, чтобы преобразовать в символ
        write(1, &bit, 1); // выводим результат
    }
}