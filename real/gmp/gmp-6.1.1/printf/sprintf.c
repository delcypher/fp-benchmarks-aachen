#define __GMP_WITHIN_GMP 1
#define HAVE_CONFIG_H 1
/* gmp_sprintf -- formatted output to an unrestricted string.

Copyright 2001 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.  */

#include <stdarg.h>
#include <string.h>    /* for strlen */

#include "gmp.h"
#include "gmp-impl.h"


int
gmp_sprintf (char *buf, const char *fmt, ...)
{
#if WANT_ASSERT
  int      fmtlen = strlen(fmt);
#endif
  va_list  ap;
  int      ret;

  va_start (ap, fmt);

  ret = __gmp_doprnt (&__gmp_sprintf_funs, &buf, fmt, ap);
  va_end (ap);

  ASSERT (! MEM_OVERLAP_P (buf, strlen(buf)+1, fmt, fmtlen+1));

  return ret;
}
