#include "head.h"
#include "string.h"

t_photo **photos;
int		n_photos;



static	size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static	size_t	word_len(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

static	char	*copy_word(const char *s, size_t len)
{
	char	*dst;

	dst = (char *)malloc(len + 1);
	if (dst == 0)
		return (0);
	strncpy(dst, s, len);
	dst[len] = '\0';
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	**ref;
	size_t	len;

	if (!s)
		return (0);
	while (*s == c)
		s++;
	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char **));
	if (res == 0)
		return (0);
	ref = res;
	while (*s)
	{
		len = word_len(s, c);
		*res = copy_word(s, len);
		if (*res == 0)
			return (0);
		res++;
		s += len;
		while (*s == c)
			s++;
	}
	*res = 0;
	return (ref);
}

int	read_input()
{
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
		scanf("%c %d ", &(photos[i]->orient), &(photos[i]->ntags));
		if ((photos[i]->tags = malloc(sizeof(char **) * (photos[i]->ntags + 1))) == NULL) {
			printf("mem allocation error\n");
			return (0);
		}
printf("<<< %d  %c %d <<<<<<<<< %d <<<<<<<<<<<<\n",
		photos[i]->id,
		photos[i]->orient,
		photos[i]->ntags,
		n_photos);
printf("%p\n", photos[i]->tags[0]);

		int j = 0;
		for (j = 0; j < photos[i]->ntags; j++)
		{
printf("%d %p\n", j, photos[i]->tags[j]);
			char *tmp = NULL;
			scanf("%s\n", tmp);
			photos[i]->tags = ft_strsplit(tmp, ' ');
		}
		photos[i]->tags[j] = NULL;
	}
	return (1);
}
