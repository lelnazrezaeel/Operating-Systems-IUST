#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
struct proc_info
{
  int pid;
  int memsize;
};
int main(int argc, char *argv[])
{
  struct proc_info ptable[NPROC];
  struct proc_info *p;
  int p1 = fork();
  int p2 = fork();

  if (p1 > 0 && p2 > 0)
  {
    malloc(1200);
    proc_dump(NPROC * sizeof(struct proc_info), &ptable);
    int idx = 0;
    p = &ptable[idx];
    while (idx < NPROC)
    {
      if (p->memsize > 0)
      {
        wait();
        printf(1, "SIZE: %d | PID: %d\n", p->memsize, p->pid);
      }

      p = &ptable[idx++];
    }
  }
  else if (p1 == 0 && p2 > 0)
    malloc(200);
  else if (p1 > 0 && p2 == 0)
  {
    malloc(400);
  }
  else
    malloc(800);

  exit();
}