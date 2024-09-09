#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

int
main(void)
{
  fprintf(1, "Read count: %d\n", getreadcount());
  exit(0);
}
