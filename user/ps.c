#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "kernel/pstat.h"
#include "user/user.h"


int main(int argc, char* argv[]) {
  struct pstat p = { 0 };
  printf("Struct p: %lu\n", (uint64)&p);
  int result = getpinfo(&p);
  if (result < 0) {
    printf("Failed to fetch proc info\n");
    exit(1);
  }
  for (int i = 0; i < NPROC; ++i) {
    if (p.inuse[i]) {
      printf("PID %d | Tickets: %d | Ticks: %d\n",
             p.pid[i], p.tickets[i], p.ticks[i]);
    }
  }
  exit(0);
}
