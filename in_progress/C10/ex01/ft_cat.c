#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define FUNTION_NAME "./ft_cat: "
#define ERR_DIR "Is a directory\n"
#define ERR_NOT_FOUND "No such file or directory\n"


int is_dir(char *filename)
{
	int fd;

	fd = open(filename,O_RDONLY | O_DIRECTORY);
	if(fd == -1)
	{
		if(errno == ENOTDIR)
			return 0;
		else
			return -1;
	}
	close(fd);
	return 1;

}

void ft_putstr(char * str)
{
	int i;

	i = 0;
	while(str[i])
		i++;

	write(1,str,i);
	return ;
}

int error(char *msg,char*filename)
{
	ft_putstr(FUNCTION_NAME);
	ft_putstr(msg);
	ft_putstr(": ");
	ft_putstr(filename);
	ft_putstr("\n");
}

int read_file(char *filename)
{
	int fd;
	int bytes;
	char buffer[30];

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

int main(int argc,char ** argv)
{
	int i;

	if(argc <= 1)
		return 0;
	i = 0;
	while(i < argc)
	{
		if(is_dir(argv[i]) == 1)
			error(argv[i],ERR_DIR);
		else if(read_file(filename) < 0)
			error(argv[i],FILE_NOT_FOUND);
		i++;
	}
}
