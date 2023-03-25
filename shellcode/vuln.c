#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFSIZE 148

void vuln(char *buf){
  gets(buf);
  puts(buf);
}

int main(int argc, char **argv){
  setvbuf(stdout, NULL, _IONBF, 0);

  /* gid_t gid = getegid(); */
  /* setresgid(gid, gid, gid); */

  char buf[BUFSIZE];
  puts("Enter your shellcode:");
  vuln(buf);
  puts("Thanks! Executing now...");
  ((void (*)())buf)();
  puts("Finishing Executing Shellcode. Exiting now...");
  return 0;
}
