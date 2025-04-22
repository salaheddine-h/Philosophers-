#include <stdio.h>
#include <unistd.h>

void	make_cool(char *str)
{
	printf("%s Can u stay here a 5min !!\n", str);
	sleep(5);
	printf("%s Now You can Gooo $\n", str);
}
int	main()
{
	make_cool("salaheddine");
	make_cool("adam");
}
