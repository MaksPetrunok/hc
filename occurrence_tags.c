#include "head.h"

int	occurrence_tags_common(t_photo *a, t_photo *b)
{
	int	res = 0;

	for (int i = 0; i < a->ntags; i++)
	{
		for (int j = 0; j < b->ntags; j++)
		{
			if (!strcmp(a->tags[i], b->tags[j]))
				res++;
		}
	}
	return (res);
}

int	occurrence_tags_a_diff_b(t_photo *a, t_photo *b)
{
	int	res = 0;
	int temp;

	for (int i = 0; i < a->ntags; i++)
	{
		temp = 0;
		for (int j = 0; j < b->ntags; j++)
		{
			if (!strcmp(a->tags[i], b->tags[j]))
				temp++;
		}
		if (temp == 0)
			res++;
	}
	return (res);
}

int	get_occurrence(t_photo *a, t_photo *b)
{
	int	tmp;
	int	res;

	tmp = occurrence_tags_common(a, b);
	res = occurrence_tags_a_diff_b(a, b);
	if (tmp < res)
		res = tmp;
	tmp = occurrence_tags_a_diff_b(b, a);
	if (tmp < res)
		return (tmp);
	return (res);
}
