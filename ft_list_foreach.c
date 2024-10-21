typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while(begin_list) //пока не дошел до конца
    {
        (*f)(begin_list->data); //применяем функцию к текущему элементу списка
        begin_list = begin_list->next; //перемещаемся к след элементу
    }
}

/*
Функция принимает два параметра:

    t_list *begin_list — указатель на первый элемент односвязного списка.
    void (*f)(void *) — указатель на функцию, которая будет применена к данным каждого элемента списка. Эта функция принимает в качестве параметра указатель на данные типа void * (генерализованные данные).
*/