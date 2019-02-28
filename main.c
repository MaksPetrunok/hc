#include "head.h"

int main()
{
	if (!read_input())
		return (1);

	printf("===== INPUT =====\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
