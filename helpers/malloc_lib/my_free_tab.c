#include "malloc_lib.h"

void my_free_tab(void **tab, t_node *node)
{
  size_t i;
  
  i = 0;
  while (tab[i])
  {
    my_free(tab[i], node);
    i++;
  }
  if (tab)
  {
    my_free(tab, node);
    tab = NULL;
  }
}

