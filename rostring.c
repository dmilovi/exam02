#include <unistd.h>

void write_word(char *start, char *end) //функция для вывода слова
{
    while(start < end)
    {
        write(1, start, 1);
        start++;
    }
}

int main(int ac, char *av[])
{
    char *str; //для указателя на текущцю позицию в строке
    char *first_word_start; // для хранения начала первого слова
    char *first_word_end; // для хран конца перв слова

    if(ac > 1)
    {
        str = av[1]; // получаем указатель на строку
        while(*str == ' ' || *str == '\t') //пропускаем все начальные пробелы и табуляции
            str++;
        first_word_start = str; //сохраняем указатель на начало первого слова
        while(*str && *str != ' ' && *str != '\t') // ищем конец первого слова
            str++;
        first_word_end = str; //сохраняем указатель на конец перв слова
        while(*str == ' ' || *str == '\t') //пропускаем пробелы после первого слова
            str++;
        if(*str) //вываодим остальные слова 
        {
            while(*str)
            {
                if(*str == ' ' || *str == '\t')
                {
                    while(*str == ' ' || *str == '\t')
                        str++;
                    if(*str)
                        write(1, " ", 1);
                }
                else
                {
                    write(1, str, 1);
                    str++;
                }
            }
            write(1, " ", 1);
        }
        write_word(first_word_start, first_word_end); // после вывода всех остальных слов и добавления пробела, выводим первое слово в конце
    }
    write(1, "\n", 1);
    return 0;
}