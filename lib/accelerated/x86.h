/*
 * Copyright (C) 2011 Free Software Foundation, Inc.
 *
 * Author: Nikos Mavrogiannopoulos
 *
 * This file is part of GnuTLS.
 *
 * The GnuTLS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <config.h>

#if defined(ASM_X86_32) || defined(ASM_X86_64)

void _gnutls_cpuid(unsigned int func, unsigned int *ax, unsigned int *bx, unsigned int *cx, unsigned int* dx);

# ifdef ASM_X86_32
unsigned int _gnutls_have_cpuid(void);
# else
#  define _gnutls_have_cpuid() 1
# endif /* ASM_X86_32 */

#endif

