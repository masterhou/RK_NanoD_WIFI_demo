/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis 'TREMOR' CODEC SOURCE CODE.   *
 *                                                                  *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis 'TREMOR' SOURCE CODE IS (C) COPYRIGHT 1994-2002    *
 * BY THE Xiph.Org FOUNDATION http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: basic shared codebook operations

 ********************************************************************/

#ifndef _V_CODEBOOK_H_
#define _V_CODEBOOK_H_

#include "ogg.h"

typedef struct codebook{
  long  dim;             /* codebook dimensions (elements per vector) 码书维数 8、4、2、1*/
  long  entries;         /* codebook entries */
  long  used_entries;    /* populated codebook entries 粒子数增加的*/

  int   dec_maxlength;
  void *dec_table;
 // char dec_table[1760];		//1760  s->used_entries*(s->dec_leafw+1)-2)* s->dec_nodeb
                            //其中used_entries最大值为441因此((441*2-2))*2 = 1760
                            //used_entries*2-2   应该为这些个，但是有可能是int16，因此要再乘2
  int   dec_nodeb;
  int   dec_leafw;
  int   dec_type;        /* 0 = entry number
			    1 = packed vector of values
			    2 = packed vector of column offsets, maptype 1
			    3 = scalar offset into value array,  maptype 2  */

  ogg_int32_t q_min;
  int         q_minp;
  ogg_int32_t q_del;
  int         q_delp;
  int         q_seq;
  int         q_bits;
  int         q_pack;
  void       *q_val;

} codebook;

extern void vorbis_book_clear(codebook *b);
extern int  vorbis_book_unpack(oggpack_buffer *b,codebook *c);

extern long vorbis_book_decode(codebook *book, oggpack_buffer *b);
extern long vorbis_book_decodevs_add(codebook *book, ogg_int32_t *a,
				     oggpack_buffer *b,int n,int point);
extern long vorbis_book_decodev_set(codebook *book, ogg_int32_t *a,
				    oggpack_buffer *b,int n,int point);
extern long vorbis_book_decodev_add(codebook *book, ogg_int32_t *a,
				    oggpack_buffer *b,int n,int point);
extern long vorbis_book_decodevv_add(codebook *book, ogg_int32_t **a,
				     long off,int ch,
				    oggpack_buffer *b,int n,int point);

extern int _ilog(unsigned int v);


#endif
