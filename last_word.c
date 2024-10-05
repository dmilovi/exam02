#include <unistd.h>

void last_word(char *str) //  функция чтобы найти начало послед слова
{
    int i = 0; //для общего цикла
    int j = 0; //для сохранения индекса первой буквы нового слова

    while(str[i]) //идем по строке
    {
        if(str[i] == ' ' && str[i+1] >= 33 && str[i+1] <= 126) //если встретили пробел и след символ печатный (они в аски между 33 и 126)
            j = i + 1; //тогда сохраняем индекс этого след символа (те первой буквы слова в) в j
        i++; // переходим дальше, таким образом это j постоянно обновляется, пока в ней не останется в итоге индекс первой буквы послед слова
    }
    while(str[j] >= 33 && str[j] <= 127) //теперь идем по этому послед слову, если оно в пределах печатных символов
    {
        write(1, &str[j], 1); //выводим его
        j++;
    }
}

int main(int ac, char *av[]) //главная функция
{
    if(ac == 2) //проверили что два аргумента
        last_word(av[1]); //вывели функцию и в ней строку
    write(1, "\n", 1);
    return(0);
}