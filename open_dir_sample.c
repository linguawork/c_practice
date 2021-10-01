//https://man7.org/linux/man-pages/man3/readdir.3.html


#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *folder;
    struct dirent *entry;
    int files = 0;

    folder = opendir("/bin");
    if(folder == NULL)
    {
        perror("Unable to read directory");
        return(1);
    }
    entry = readdir(folder);
    while (entry)  //изначально условие цикла было таким: while (entry = readdir(folder)), но это не по норме
    // поэтому я вынес условие до входа в цикл и вызвал readdir в конец цикла чтобы он изменил значение после каждой итерации
    {
        
        files++;
        printf("File %3d: %s\n",
                files,
                entry->d_name
              );
        entry = readdir(folder); // изменение значения в итерауции пока не достигли нуля
    }

    closedir(folder);
    return(0);
}