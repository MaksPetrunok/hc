#include "head.h"

void sort_by_number()
{

}

static void swap(int a, int b)
{
	t_photo *buf;

	// printf("swap\n");
	buf = photos[a];
	photos[a] = photos[b];
	photos[b] = buf;
}

static int partition (int low, int high) 
{ 
	int pivot = photos[high]->ntags;
	int i = (low - 1); 
	// printf("par ");
	for (int j = low; j <= high- 1; j++) 
	{ 
		if (photos[j]->ntags >= pivot) 
		{ 
			i++;
			swap(i, j); 
		} 
	} 
	swap(i + 1, high); 
	return (i + 1); 
} 

void sort_by_tags(int low, int high)
{ 
	if (low < high) 
	{ 
		int pi = partition(low, high); 
		quickSort(low, pi - 1); 
		quickSort(pi + 1, high); 
	} 
} 