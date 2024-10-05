#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
    int i = 8; //счетчик цикла для отслеживания итераций, 8 , тк в одном байте 8 бит
    unsigned char res = 0; // результат

    while(i > 0) //идем пока i > 0
    {
        res = res * 2 + (octet % 2); // извлекаем последний бит числа octet и добавляем к результату
        octet = octet / 2; //сдвигаем исходное число на один бит вправо, чтобы дальше извлекать уже след бит
        i--; //уменьшаем счетчик итераций после каждой итерации, чтобы цикл завершился после обработки 8 битов
    }
    return(res); //возвращаем результат 
}