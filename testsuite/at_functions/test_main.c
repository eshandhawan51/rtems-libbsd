/**
 * @file
 *
 * Following methods are tested in this file : Confstr() 
 */

/*
 * Copyright (c) 2020 Eshan Dhawan
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#include <sys/param.h>

#include <errno.h>
#include <limits.h>
#include <paths.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/stat.h>

#include <rtems/libcsupport.h>
#include <rtems.h>

#define TEST_NAME "LIBBSD at_functions "

static void 
test_main(void)
{
  /* Bindat */
  int fd, s;
  int r;
  struct socksddr *addr;
  socklen_t addrlen;
  struct dirent ***namelist;
  uid_t owner;
  gid_t group;
  size_t bufsiz;
  struct timeval times[2];
  struct timespec times1[2];
  mode_t mode;
  dev_t dev ;

  r = bindat(0, 0, addr, addrlen);
 /* connectat () */ 
  r = connectat(0, 0, addr, addrlen);
  
  /* Faccessat */ 
  r = faccessat(0, ' ', 0, 0) ;

  /* renameat */
  r = renameat (0, ' ', 0, ' '); 

  /* scandirat */
   
  r = scandirat(0, ' ', namelist, 0, 0);

  /* fchownat */
  r = fchownat (0, ' ', owner, group, 0);

  /* linkat */
  r = linkat (0, ' ', 0, ' ', 0);

  /*  readlinkat */ 
  r = readlinkat (0, ' ', ' ', bufsiz) ; 

  /* unlinkat */
  r = unlinkat( 0, ' ', 0 );

  /*  futimesat */
  r = futimesat (0, ' ',times);

  /*  openat */
  r = openat(0, ' ', 0 ) ;

  /* fchmodat */
  r = fchmodat(0, ' ', mode, 0);

  /* mkfifoat */ 
  r = mkfifoat(0, ' ', mode);

  /* mknodat */
  r = mknodat(0, ' ', mode, dev);

  /* utimensat */
  r = utimensat(0, ' ', times1, 0 );

  exit(0);
}

#include <rtems/bsd/test/default-init.h>
