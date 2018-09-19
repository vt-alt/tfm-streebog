/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright (c) 2013, Alexey Degtyarev <alexey@renatasystems.org>. 
 * All rights reserved.
 *
 * $Id$
 */

#include <string.h>
#include "streebog-config.h"
#include "streebog-ref.h"

union uint512_u
{
    unsigned long long QWORD[8];
} __attribute__((__aligned__(16)));

#include "streebog-const.h"
#include "streebog-precalc.h"

typedef struct GOST34112012Context
{
    unsigned char buffer[64];
    union uint512_u hash;
    union uint512_u h;
    union uint512_u N;
    union uint512_u Sigma;
    size_t bufsize;
    unsigned int digest_size;
} GOST34112012Context;

void GOST34112012Init(GOST34112012Context *CTX,
        const unsigned int digest_size);

void GOST34112012Update(GOST34112012Context *CTX, const unsigned char *data,
        size_t len); 

void GOST34112012Final(GOST34112012Context *CTX, unsigned char *digest); 

void GOST34112012Cleanup(GOST34112012Context *CTX);
