//----------------------------------------------------------------
//
//  4190.307 Operating Systems (Spring 2026)
//
//  Project #2: System calls
//
//  March 19, 2026
//
//  Jin-Soo Kim (jinsoo.kim@snu.ac.kr)
//  Systems Software & Architecture Laboratory
//  Dept. of Computer Science and Engineering
//  Seoul National University
//
//----------------------------------------------------------------

#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

char *xlen[] = {"invalid", "32-bit", "64-bit", "reserved"};

int
main(int argc, char *argv[])
{
  uint64 isa;
  int ret;

  if ((ret = misa(&isa)) != 0)
  {
    printf("%s: misa() failed.\n", argv[0]);
    exit(ret);
  }
 
  printf("misa: %lx ", isa);
  for (char i = 'A'; i <= 'Z'; i++)
    printf("%c", (isa & (1 << (i - 'A')))? i : ' ');
  printf(" (%s)\n", xlen[isa >> 62]);
  exit(0);
}

