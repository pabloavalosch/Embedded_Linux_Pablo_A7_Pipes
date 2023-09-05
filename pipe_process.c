#include "unistd.h"
#include "stdio.h"

#define LEN 50U

static void parent_process(int fd)
{
	char buffer[LEN];

	for(;;)
	{
		char * str = fgets(buffer,LEN,stdin);

		if(str == NULL)
		{
			break;
		}
		write(fd,buffer,LEN);
	}
}

static void child_process(int fd)
{

	char buffer[LEN];

        for(;;)
        {
                
                read(fd,buffer,LEN);
		printf("FRom child: %s\n", buffer);
        }


}

int main(int argc, char * argv[])
{
	int fds[2];
	int ret = pipe(fds);

	int ret_fork = fork();

	if(ret_fork == 0)
	{
		child_process(fds[0]);
	}
	else if (ret_fork > 0)
	{
		parent_process(fds[1]);
	}	

	return 0;
}
