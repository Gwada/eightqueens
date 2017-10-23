#include <stdio.h>

int		ft_print_result(int *tab)
{
	int		i;

	i = 0;
	while (i < 8)
		printf("%d ", tab[i++]);
	printf("\n");
	return (1);
}

int		ft_is_safe(int *tab, int Q)
{
	int		i;
	int		poss;

	i = -1;
	poss = 0;
	tab[Q] = 1;
	if (Q == 8)
		return (ft_print_result(tab));
	while (tab[Q] <= 8)
	{
		if (++i == Q)
		{
			poss += ft_is_safe(tab, Q + 1);
			tab[Q]++;
			i = -1;
		}
		else if ((tab[Q] == tab[i])
		|| (tab[Q] == tab[i] - (Q - i))
		|| (tab[Q] == tab[i] + (Q - i)))
		{
			tab[Q]++;
			i = -1;
		}
	}
	return (poss);
}

int		ft_eight_queens_puzzle(void)
{
	int		tab[8];

	return (ft_is_safe(tab, 0));
}

int		main(void)
{
	printf("il y a %d possibilites\n", ft_eight_queens_puzzle());
	return (0);
}
