typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if(begin_list == NULL || *begin_list == NULL) //проверяем что указатель на список и сам список не равны НУЛЬ
        return; 
    t_list *cur = *begin_list; //cur для хранения текущ элемента списка кот будет анализироваться и возможно будет удален

    if(cmp(cur->data, data_ref)==0) //если данные текущ элемента списка совпадают с эталонными данными, функция вернет 0 и текущ элемент будет удален
    {
        *begin_list = cur->next; //список перескакивает через удаляемый элемент, меняя указатель на начало списка на след элемент
        free(cur); //особождается память, выделенная под удаляемый элемент
        ft_list_remove_if(begin_list, data_ref, cmp); //рекурсивно вызываем ту же функцию, чтобы проверить и возможно удалить след элемент списка
    }
    else //если не надо удалять то
    {
        cur = *begin_list; //cur обновляется 
        ft_list_remove_if(&cur->next, data_ref, cmp); //рекурсивно вызываем функци с указателем на след элемент списка, чтобы пройти по всем элементам списка
    }
}

/*
t_list **begin_list — указатель на указатель на первый элемент списка. Это позволяет изменять сам список, включая возможность изменить первый элемент списка (если он будет удален).

void *data_ref — эталонные данные, с которыми будут сравниваться данные в элементах списка.

int (*cmp)() — указатель на функцию сравнения. Эта функция принимает два аргумента: данные текущего элемента списка и эталонные данные (data_ref). Возвращает 0, если данные совпадают (то есть элемент должен быть удален), и ненулевое значение, если данные не совпадают.
*/