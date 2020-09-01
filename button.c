#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
struct event {
	struct timeval time;
	unsigned short type;
	unsigned short code;
	unsigned int value;

};
int main()
{
	
	int fd;
	struct input_event event;
	fd = open("/dev/input/event3", O_RDWR);
	if(fd<0)
	{
		printf("open error!\n");
	}
	while(1)
	{	
		read(fd, &event, sizeof(event));
		if(event.type == EV_KEY)
		{
			printf("value: %d\n",event.value);
		}

        }
        close(fd);
        return 0;
}
