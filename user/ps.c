#include "kernel/proc.c"
#include "kernel/pstat.h"
#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"


int main(int argc, char* argv[]) {
  struct pinfo p = { 0 };
  int result = getpinfo(&p);
  if (result < 0) {
    printf("Failed to fetch proc info!\n");
    exit(1);
  }
  for (int i = 0; i < NPROC; ++i) {
    if (p.in_use[i]) {
      printf("PID %d | Tickets: %d | Ticks: %d\n",
             p.pid[i], p.tickets[i], p.ticks[i]);
    }
  }
  p.tickets
  exit(0);
}
