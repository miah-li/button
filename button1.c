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
	
	int button_fd,led_fd;
	char *buf1 = "default-on", *buf2 = "none";
	struct input_event event;
	button_fd = open("/dev/input/event3", O_RDWR);
	if(button_fd<0)
	{
		printf("open error!\n");
		return 0
	}
	led_fd = open("/sys/class/leds/red_led/trigger",O_RDWR);
	if(led_fd < 0)
        {
                printf("Open led device faild!\n");
                close(button_fd);
                return 0;
        }
	while(1)
	{	
		read(button_fd, &event, sizeof(event));
		if(event.type == EV_KEY)
               {
			printf("%d\n",event.value);
			if(event.value == 1)
			{
				write(led_fd,buf1,strlen(buf1));
			}
			else
			{
				write(led_fd,buf2,strlen(buf2));
			}
             }
        }
        close(button_fd);
        close(led_fd);
        
        
}

