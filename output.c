#include "head.h"

void output(void/* array */)
{
	int h;
	int v;
	int i;

	i = 0;
	while (var[i] != NULL)
	{
		h = v = 0;
		if (var->orient == 'H')
			printf("%d\n", var.id);
		else if (var[i]->orient == 'V' && var[i + 1]->orient == 'V')
		{
			printf("%d %d\n", var[i]->id, var[i + 1]->id);
			v = 1;
		}
		if (v)
			i += 2;
		else
			i++;
	}
}