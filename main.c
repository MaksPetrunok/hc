#include "head.h"

int main()
{
	if (!read_input())
		return (1);
printf(".................\n");
	printf("===== INPUT =====\n");
	for (int i = 0; i < n_photos; i++) {
		printf("ID	%d: %c, %d tags: ",
			photos[i]->id,
			photos[i]->orient,
			photos[i]->ntags);
		for (int j=0; j<photos[i]->ntags; j++)
			printf("%s ", photos[i]->tags[j]);
		printf("\n");
	}
	return 0;
}
