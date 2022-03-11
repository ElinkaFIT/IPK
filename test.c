#include <stdio.h>

void spel(char *tet){
    *tet = "kolo";
}

int main()
{
    char *tets;
    spel(tets);
    printf("%s", tets);
    return 0;
}
