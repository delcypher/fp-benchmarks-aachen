#define __GMP_WITHIN_GMP 1
#define HAVE_CONFIG_H 1
/* mpf_inits() -- Initialize multiple mpf_t variables and set them to 0.

Copyright 2009, 2015 Free Software Foundation, Inc.

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
#include "gmp.h"
#include "gmp-impl.h"

void
mpf_inits (mpf_ptr x, ...)
{
  va_list  ap;

  va_start (ap, x);

  while (x != NULL)
    {
      mpf_init (x);
      x = va_arg (ap, mpf_ptr);
    }

  va_end (ap);
}
