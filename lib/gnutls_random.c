/*
 * Copyright (C) 2004 Simon Josefsson
 * Copyright (C) 2001,2003 Nikos Mavroyanopoulos
 * Copyright (C) 2004 Free Software Foundation
 *
 * This file is part of GNUTLS.
 *
 *  The GNUTLS library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 */

/* Functions to return random bytes.
 */

#include <gnutls_int.h>
#include <gnutls_random.h>
#include <gnutls_errors.h>

/* fills the buffer 'res' with random bytes of 'bytes' long.
 * level is WEAK, STRONG, or VERY_STRONG (libgcrypt)
 */
int _gnutls_get_random(opaque * res, int bytes, int level)
{
  int err;

  switch (level)
    {
    case GNUTLS_WEAK_RANDOM:
      err = gc_nonce ((char*) res, (size_t) bytes);
      break;

    case GNUTLS_STRONG_RANDOM:
      err = gc_pseudo_random ((char*) res, (size_t) bytes);
      break;

    default: /* GNUTLS_VERY_STRONG_RANDOM */
      err = gc_random ((char*) res, (size_t) bytes);
      break;
    }

  if (err != GC_OK)
    return GNUTLS_E_RANDOM_FAILED;

  return GNUTLS_E_SUCCESS;
}
