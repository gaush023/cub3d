#include "malloc_lib.h"

void	my_free_tab(void **tab, t_node *node)
{
	size_t	i;

	i = 0;
  (void)node;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}
