#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_photo
{
	int		id;
	int		used;
	char	orient;
	int		ntags;
	char	**tags;
}				t_photo;


extern t_photo	**photos;
extern int		n_photos;
int				get_occurrence(t_photo *a, t_photo *b);

int	read_input();

#endif
