#include "head.h"
#include <string.h>

t_photo **photos;
int		n_photos;

int	read_input()
{
	char tmp[4000];

	if (scanf("%d\n", &n_photos) < 1)
		return (0);

	if ((photos = malloc(sizeof(t_photo **) * (n_photos + 1))) == NULL) {
		printf("mem allocation error\n");
		return (0);
	}

	for (int i = 0; i < n_photos; i++) {
		if ((photos[i] = malloc(sizeof(t_photo))) == NULL) {
			printf("mem allocation error\n");
			return (0);
		}
		photos[i]->id = i;
		photos[i]->used = 0;
		scanf("%c %d ", &(photos[i]->orient), &(photos[i]->ntags));
		if ((photos[i]->tags = malloc(sizeof(char **) * (photos[i]->ntags + 1))) == NULL) {
			printf("mem allocation error\n");
			return (0);
		}

		int j = 0;
		for (j = 0; j < photos[i]->ntags; j++)
		{
			scanf("%s ", tmp);
			photos[i]->tags[j] = strdup(tmp);
		}
		photos[i]->tags[j] = NULL;
	}
	return (1);
}
