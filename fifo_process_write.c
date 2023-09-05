#include "unistd.h"
#include "stdio.h"
#include "fcntl.h"


#define LEN 80U
#define FIFO_NAME "/tmp/myFifo"


int main(int argc, char * argv[])
{
	char buff[LEN];
	int ret;
	int fifo = open(FIFO_NAME, O_WRONLY);
	
	printf("Pipe is open for write\n");

	for(;;)
	{

		char * str = fgets(buff,LEN,stdin);
		if( str == NULL)
			break;
		int ret = write(fifo,buff,LEN);
	
	}

	close(fifo);	

	return 0;
}
