#include "../../includes/cub3d.h"

bool	ft_isalpha(int c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (true);
  return (false);
}
