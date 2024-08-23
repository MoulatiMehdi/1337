#include <fcntl.h>
#include <unistd.h>

int read_file(char *filename) {
	int fd;
	char c;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return -1;

	while (read(fd, &c, 1) > 0)
		write(1, &c, 1);

	close(fd);
	return 0;
}

int main(int argc, char **argv) {
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else if (read_file(argv[1]) < 0)
		write(2, "Cannot read file.\n", 18);
	return 0;
}
