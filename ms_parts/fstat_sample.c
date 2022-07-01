#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        struct stat sb;
        int status_num;

   if (argc != 2) 
   {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

        status_num = stat(argv[1], &sb);

   if (status_num == -1) 
   {
        perror("stat");
        exit(EXIT_FAILURE);
    }

   printf("File type:                ");

   if ((sb.st_mode & S_IFMT) == S_IFBLK) // п
       printf("block device\n");
   else if((sb.st_mode & S_IFMT) == S_IFCHR)
       printf("character device\n");
   else if((sb.st_mode & S_IFMT) == S_IFDIR)
       printf("directory\n");
   else if((sb.st_mode & S_IFMT) == S_IFIFO)
       printf("FIFO/pipe\n");
   else if((sb.st_mode & S_IFMT) == S_IFLNK)
        printf("symlink\n");
   else if((sb.st_mode & S_IFMT) == S_IFREG)
        printf("regular file\n");
   else if((sb.st_mode & S_IFMT) == S_IFSOCK)
       printf("socket\n");
   else
       printf("unknown?\n");


   printf("I-node number:            %ld\n", (long) sb.st_ino);

   printf("Mode:                     %lo (octal)\n",
            (unsigned long) sb.st_mode);

   printf("Link count:               %ld\n", (long) sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
            (long) sb.st_uid, (long) sb.st_gid);

   printf("Preferred I/O block size: %ld bytes\n",
            (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",
            (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",
            (long long) sb.st_blocks);

   printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));

    printf("The return value of stat is %d\n", status_num);

   exit(EXIT_SUCCESS);
}