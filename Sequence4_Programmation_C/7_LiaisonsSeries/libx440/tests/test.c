#include <stdio.h>
#include "../libx440.h"

int main(int argc, char *argv[])
{
  printf("Version %s\n",
         serial_get_version());
  return 0;
}
