/*
File: lwippools.h
Desc:
Author: dgl
Date: 2013-11-20
Notes:
*/


LWIP_MALLOC_MEMPOOL_START
LWIP_MALLOC_MEMPOOL(10, 256)
LWIP_MALLOC_MEMPOOL(5, 512)
LWIP_MALLOC_MEMPOOL(5, 1512)
LWIP_MALLOC_MEMPOOL_END

