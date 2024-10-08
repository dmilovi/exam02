#include <unistd.h>
#include "ft_list.h"

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                t_list;

int	ft_list_size(t_list *begin_list) //показывает кол-во элементов в списке, функция рекурсивная
{
    if(begin_list == 0)
        return(0);
    else
        return(1 + ft_list_size(begin_list->next)); //через рекурсию проходим по списку и возвращаем его потом в обратном подрядке с добавлением 1 (текущ элемент)
}