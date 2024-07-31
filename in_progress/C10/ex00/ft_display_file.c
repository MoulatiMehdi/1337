#include <unistd.h>
#include <fcntl.h>

int read_file(char *filename)
{
	int fd;
	int bytes;
	unsigned char buffer[1024];

	fd = open(filename,O_RDONLY);
	if(fd < 0)
		return -1;

	bytes = 1 ; 
	while(bytes > 0)
	{
		bytes = read(fd,buffer,1024);
		write(1,buffer,bytes);
	}
	close(fd);
	return 0;
}

int main(int argc,char **argv)
{
	if(argc == 1)
	{
		write(2,"File name missing.\n",19);
		return 1;
	}
	else if(argc > 2)
	{
		write(2,"Too many arguments.\n",20);
		return 1;
	}
	
	if(read_file(argv[1]) < 0)
	{
		write(2,"Cannot read file.\n",18);
		return 1;
	}
	return 0;
}
