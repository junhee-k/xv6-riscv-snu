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


int
main(int argc, char *argv[])
{
  reset();
  printf("%s: reset() failed.\n", argv[0]);
  exit(-1);
}

