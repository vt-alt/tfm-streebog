/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright (c) 2013, Alexey Degtyarev <alexey@renatasystems.org>. 
 * All rights reserved.
 *
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
