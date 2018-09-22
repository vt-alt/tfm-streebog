/* SPDX-License-Identifier: GPL-2.0+ OR BSD-2-Clause */
/*
 * Copyright (c) 2013, Alexey Degtyarev <alexey@renatasystems.org>. 
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#ifndef _STREEBOG_H_
#define _STREEBOG_H_

#include <linux/types.h>

#define STREEBOG256_DIGEST_BYTES	32
#define STREEBOG512_DIGEST_BYTES	64
#define STREEBOG_BLOCK_BYTES		64

union uint512_u {
	unsigned long long QWORD[8];
} __aligned(16);

struct streebog_state {
	unsigned char buffer[64] __aligned(16);
	union uint512_u hash;
	union uint512_u h;
	union uint512_u N;
	union uint512_u Sigma;
	size_t bufsize;
};

#endif /* !_STREEBOG_H_ */
