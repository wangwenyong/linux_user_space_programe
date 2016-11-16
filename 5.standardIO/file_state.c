#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	char *ptr;
	
	printf("argc = %d ", argc);
	for(i=1; i<argc; i++){
		printf("%s:", argv[i]);
		if(lstat(argv[i], &buf) < 0){
			printf("lstae error!\n");
			continue;
		}
		
		if(S_ISREG(buf.st_mode)) ptr = "regular";
		else if(S_ISDIR(buf.st_mode)) ptr = "directory";
		else if(S_ISCHR(buf.st_mode)) ptr = "character special";

		printf("%s\n", ptr);
	}
	
	exit(0);
}
