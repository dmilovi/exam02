#include <unistd.h>

typedef struct  s_point
{
    int           x; //координата по горизонтали
    int           y; //по вертикали
}               t_point; //тип данных, представляющий точку на плоскости

void fill(char **tab, t_point size, t_point cur, char to_fill)
{
    if(cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill) //проверка выхода за пределы массива
        return;
    tab[cur.y][cur.x] = 'F'; //заполняем клетку символом F
    fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill); //рекурсивно функция вызывает саму себя для четырех соседних клеток
    fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
    fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
    fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void  flood_fill(char **tab, t_point size, t_point begin) //инициализирует процесс заливки
{
    fill(tab, size, begin, tab[begin.y][begin.x]); //передаем координаты начала 
}

/*
char **tab — это двумерный массив (или матрица), представляющий поле для заполнения. Каждый элемент массива — это строка, содержащая символы.
t_point size — структура, представляющая размеры массива: size.x — это ширина (количество столбцов), size.y — это высота (количество строк).
t_point cur — текущая точка (координаты), в которой находимся при выполнении алгоритма.
char to_fill — символ, который мы собираемся заменить (то есть область, которая должна быть заполнена).
t_point begin — начальная точка, откуда начинается заливка.
*/