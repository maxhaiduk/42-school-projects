#include "../../libft.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define RANDT	512
#define LONG	10000
#define D_ERROR	{ printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__); return (0); }

int					main (void)
{
	char			ctab[11], ctab2[11], ctab3[11];
	int				itab[11], itab2[11], itab3[11];
	unsigned long	ltab[11], ltab2[11], ltab3[11];
	int				i, j;
	size_t			k;
	void			*temp, *temp2, *temp3;


	memcpy(NULL, NULL, 0);
	ft_memcpy(NULL, NULL, 0);

	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				ctab2[j] = 0; ctab3[j] = 0;
				itab[j] = rand();
				itab2[j] = 0; itab3[j] = 0;
				ltab[j] = (unsigned long)rand() * LONG;
				ltab2[j] = 0; ltab3[j] = 0;
				j++;
			}
			memcpy(ctab2, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			temp = ft_memcpy(ctab3, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			memcpy(itab2, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			temp2 = ft_memcpy(itab3, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			memcpy(ltab2, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			temp3 = ft_memcpy(ltab3, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			if ((memcmp(itab2, itab3, sizeof(itab)) != 0 || (temp2 != itab3)))
				D_ERROR
			if (memcmp(ctab2, ctab3, sizeof(ctab)) != 0 || temp != ctab3)
				D_ERROR

			if (memcmp(ltab2, ltab3, sizeof(ltab)) != 0 ||( temp3 != ltab3))
				D_ERROR
			++i;
		}
		++k;
	}
	return (0);
}