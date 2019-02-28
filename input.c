#include "head.h"

char	**map;
int		rows;
int		cols;

int	read_input()
{
	if (scanf("%d %d\n", &rows, &cols) < 2)
		return (0);
	if ((map = malloc(sizeof(char **) * (rows + 1))) == NULL) {
		printf("mem allocation error\n");
		return (0);
	}
	for (int i = 0; i < rows; i++) {
		if ((map[i] = malloc(sizeof(char **) * (cols + 1))) == NULL) {
			printf("mem allocation error\n");
			return (0);
		}
		scanf("%s\n", map[i]);
	}
	return (1);
}
