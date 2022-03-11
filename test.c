/* strtok example */
#include <stdio.h>
#include <string.h>

void get_cpu(char *cpu);

int main ()
{
    char *text;
    get_cpu(text);
    printf("%s\n", text);

  
    return 0;
}

void get_cpu(char *cpu){
    FILE *fc = fopen("/proc/cpuinfo", "r");
    char trash[1024];

    for(int i = 0; i < 4; i++){
        fgets(trash, 1024, fc);
    }
    fscanf(fc, "%s %s %s  ", trash, trash, trash);
    fgets(cpu, 1024, fc);
    fclose(fc);
}