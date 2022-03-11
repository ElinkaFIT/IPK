/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
    char str[] ="GET http://servername:12345/cpu-name";

    char *get = strtok (str, " /");
    char *trash = strtok (NULL, " /");
    trash = strtok (NULL, " /");
    char *command = strtok (NULL, " /");
    printf ("%s %s %s\n", get, trash, command);
  
    return 0;
}