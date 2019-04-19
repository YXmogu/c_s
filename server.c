#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define IP "127.0.0.1"
#define PORT 8888

int main()
{
	int lis_fd = socket(AF_INET, SOCK_STREAM, 0);
		printf("%d\n", lis_fd);

	struct sockaddr_in sv;
	sv.sin_family = AF_INET;
	sv.sin_port = htons(PORT);
	sv.sin_addr.s_addr = inet_addr(IP);

	int bd = bind(lis_fd, (struct sockaddr*)&sv, sizeof(sv));
		printf("%d\n", bd);
	int ld = listen(lis_fd, 3);
		printf("%d\n", ld);
	
	struct sockaddr_in ca;
	int size_ca = sizeof(ca);
	int ad = accept(lis_fd, (struct sockaddr*)&ca, &size_ca);
		printf("%d\n", ad);

	close(ad);
	close(lis_fd);

	return 0;
}
