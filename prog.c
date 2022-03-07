#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_SIZE 1024

void get_hostname();
void get_cpu();
void get_load();

int main()
{
    get_hostname();
    get_cpu();
    get_load();
}

// get hostname including domain
void get_hostname(){
    FILE *fh = fopen("/proc/sys/kernel/hostname", "r");
    char hostname[MAX_SIZE];
    fgets(hostname, MAX_SIZE, fh);
    
    printf("%s\n", hostname);

    fclose(fh);
}

// returns information about CPU
void get_cpu(){
    FILE *fc = fopen("/proc/cpuinfo", "r");
    char trash[MAX_SIZE] = {0};
    char cpuname[MAX_SIZE] = {0};

    for(int i = 0; i < 4; i++){
        fgets(trash, MAX_SIZE, fc);
    }
    fscanf(fc, "%s %s %s  ", trash, trash, trash);
    fgets(cpuname, MAX_SIZE, fc);
    
    printf("%s\n", cpuname);

    fclose(fc);
}

// returns current load
void get_load(){

    FILE *fl;
    char trash[4];
    int prev_cpu[10];
    int curr_cpu[10];

    // pull previous data from /proc/stat
    fl = fopen("/proc/stat", "r");
    fscanf(fl, "%s", trash);
    for(int i = 0; i < 10; i++){
        fscanf(fl, "%d", &prev_cpu[i]);
    }
    fclose(fl);

    sleep(1);

    // pull current data from /proc/stat
    fl = fopen("/proc/stat", "r");
    fscanf(fl, "%s", trash);
    for(int i = 0; i < 10; i++){
        fscanf(fl, "%d", &curr_cpu[i]);
    }
    fclose(fl);

    // count cpu percentage
    int prev_a = prev_cpu[0] + prev_cpu[1] + prev_cpu[2]; 
    int curr_a = curr_cpu[0] + curr_cpu[1] + curr_cpu[2];   

    int prev_b = prev_cpu[0] + prev_cpu[1] + prev_cpu[2] + prev_cpu[3]; 
    int curr_b = curr_cpu[0] + curr_cpu[1] + curr_cpu[2] + curr_cpu[3];      

    float cpu_perc = (curr_a - prev_a) / (curr_b - prev_b) * 100;
    printf("CPU: %f\n", cpu_perc);

    // old version
    // int prev_idle = prev_cpu[3] + prev_cpu[4];
    // int idle = curr_cpu[3] + curr_cpu[4];

    // int prev_non_idle = prev_cpu[0] + prev_cpu[1] + prev_cpu[2] + prev_cpu[5] + prev_cpu[6] + prev_cpu[7];
    // int non_idle = curr_cpu[0] + curr_cpu[1] + curr_cpu[2] + curr_cpu[5] + curr_cpu[6] + curr_cpu[7]; 

    // int total = idle + non_idle - prev_idle + prev_non_idle;
    // int idled = idle - prev_idle;

    // int cpu_percentage = (total - idled)/total; 

    // printf("LOAD: %d\n", cpu_percentage);

}
