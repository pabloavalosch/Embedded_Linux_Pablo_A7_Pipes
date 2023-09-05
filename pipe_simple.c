#include "unistd.h"
#include "stdio.h"

#define LEN 50U

int main(int argc, char * argv[])
{
	int fds[2];
	
	char buffer[LEN];
	char bufferOut[LEN];
	int ret = pipe(fds);

	char * str = fgets(buffer, LEN, stdin);

	write(fds[1], buffer, LEN);

	read(fds[2],bufferOut,LEN);

	printf("%s\n", bufferOut);

	return 0;
}
