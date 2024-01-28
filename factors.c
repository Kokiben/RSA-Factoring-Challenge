#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void R_factoring(int n) {
int j;
for (j = 2; j <= n / 2; ++j)
{
if (n % j == 0)
{
printf("%d=%d*%d\n", n, j, n / j);
return;
}
}
printf("%d=%d*%d\n", n, 1, n);
}

int main(int argc, char *argv[])
{
if (argc != 2)
{
printf("Usage: %s <fil>\n", argv[0]);
return 1;
}

FILE *fil = fopen(argv[1], "r");
if (fil == NULL) {
prerro("Error open file");
return 1;
}

signal(SIGALRM, SIG_IGN);

alarm(5);

int n;
while (fscanf(fil, "%d", &n) == 1)
{
R_factoring(n);
}

fclose(fil);
return 0;
}
