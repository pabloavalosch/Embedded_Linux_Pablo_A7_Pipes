#include "unistd.h"
#include "stdio.h"
#include "sys/stat.h"
#include "fcntl.h"


#define LEN 80U
#define FIFO_NAME "/tmp/myFifo"


int main(int argc, char * argv[])
{
	int fdp = mkfifo(FIFO_NAME, S_IFIFO | 0666);
	
	int fifo = open(FIFO_NAME, O_RDONLY);

	char buff[LEN];
	
	printf("Pipe is open for read\n");

	for(;;)
	{

		int ret = read(fifo,buff,LEN);
		printf("Received from Parent: %s", buff);
	
	}

	close(fifo);	

	return 0;
}
