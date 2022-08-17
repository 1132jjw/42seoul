#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int		r;
	int		fd;
	char	*line;

	fd = open("asdf.txt", O_RDONLY);
	line = NULL;
	while ((r = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
	return (0);
}