#include <stdio.h>

int			ft_print_result(int *tab)
{
	int		i;

	i = 0;
	while (i < 8)
		printf("%d ", tab[i++]);
	printf("\n");
	return (1);
}

int			ft_is_safe(int *tab, int Q, int i, int poss)
{
	tab[Q] = 1;
	if (Q == 8)
		return (ft_print_result(tab));
	while (tab[Q] <= 8)
	{
		if (++i == Q)
		{
			poss += ft_is_safe(tab, Q + 1, -1, 0);
			tab[Q]++;
			i = -1;
		}
		else if (tab[Q] == tab[i] || tab[Q] == tab[i] - (Q - i)
		|| tab[Q] == tab[i] + (Q - i))
		{
			tab[Q]++;
			i = -1;
		}
	}
	return (poss);
}

int			main(void)
{
	int		tab[8];

	printf("il y a %d possibilites\n", ft_is_safe(tab, 0, -1, 0));
	return (0);
}
