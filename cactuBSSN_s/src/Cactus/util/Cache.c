 /*@@
   @file    Cache.c
   @date    Tue Nov 30 08:07:12 1999
   @author  Tom Goodale
   @desc
            Routines dealing with cache alignment.
   @enddesc
   @version $Id: Cache.c 3779 2004-06-21 14:10:36Z tradke $
 @@*/

#include <stdlib.h>

#include "cctk_Cache.h"
#include "cctki_Cache.h"
#include "cctk_Flesh.h"

static const char *rcsid = "$Header$";

CCTK_FILEVERSION(util_Cache_c)

/********************************************************************
 *********************     Local Data   *****************************
 ********************************************************************/

/* Structure to hold cache information. */
static struct s_cache_data
{
  unsigned long cacheline_bytes;
  unsigned long cache_size;
} cache_data;

/* The number of times the size of the cache has been set. */
static int cache_set = 0;

/********************************************************************
 *********************     External Routines   **********************
 ********************************************************************/

 /*@@
   @routine    Util_CacheMalloc
   @date       Tue Nov 30 08:13:03 1999
   @author     Tom Goodale
   @desc
   Allocates memory aligned on the 'index'ed cache line.
   @enddesc

   @var     idx
   @vdesc   cache line index
   @vtype   unsigned int
   @vio     in
   @vcomment
   The cache line to align on
   @endvar
   @var     size
   @vdesc   the amount of memory to allocate
   @vtype   unsigned long
   @vio     in
   @vcomment
   This is the size (in bytes) of memory to allocate.
   @endvar
   @var     realstart
   @vdesc   The real starting address of the memory
   @vtype   void **
   @vio     out
   @vcomment
   On return holds the actual starting address of the memory.
   @endvar

   @returntype void *
   @returndesc
   The cache-aligned memory address.
   @endreturndesc

@@*/
void *Util_CacheMalloc(unsigned int idx,
                       unsigned long size,
                       void **realstart)
{
  char *retval;
  char *data;
  unsigned long cacheline_bytes;
  unsigned long cache_size;
  unsigned long offset;
  unsigned long initial_index;
  unsigned long pad;

  if(Utili_CacheDataGet(&cacheline_bytes, &cache_size))
  {
    cacheline_bytes = cache_size = 0;
  }

  retval = NULL;

  data = malloc((size_t)(size+cache_size));
  if(data)
  {
    pad = 0;
    if(cache_size && cacheline_bytes)
    {
      /* Find how far this memory is into a cache line */
      offset = ((unsigned long)data%cache_size)%cacheline_bytes;
      /* Find which cache line in the cache it is in */
      initial_index = ((unsigned long)data%cache_size)/cacheline_bytes;

      pad = ((idx-initial_index)*cacheline_bytes + cacheline_bytes - offset)%cache_size;
    }

    retval = data + pad;
  }

  *realstart = (void *)data;

  return (void *)retval;
}

/********************************************************************
 *********************   CCTK Local Routines   **********************
 ********************************************************************/

 /*@@
   @routine    Utili_CacheDataSet
   @date       Tue Nov 30 08:12:05 1999
   @author     Tom Goodale
   @desc
   Stores the sizes of the cache.
   @enddesc

   @var     cacheline_bytes
   @vdesc   The size of a cacheline
   @vtype   unsigned long
   @vio     in
   @vcomment
   Number of bytes in a cache line.
   @endvar
   @var     cache_size
   @vdesc   Size of the cache
   @vtype   unsigned long
   @vio     in
   @vcomment
   The size (in bytes) of the cache.
   @endvar

   @returntype int
   @returndesc
   The number of times this function has been called before.
   @endreturndesc

@@*/
int Utili_CacheDataSet(unsigned long cacheline_bytes,
                       unsigned long cache_size)
{
  cache_data.cacheline_bytes = cacheline_bytes;
  cache_data.cache_size      = cache_size;

  cache_set++;

  return cache_set-1;
}

 /*@@
   @routine    Utili_CacheDataGet
   @date       Tue Nov 30 08:12:41 1999
   @author     Tom Goodale
   @desc
   Gets the sizes of the cache.
   @enddesc

   @var     cacheline_bytes
   @vdesc   The size of a cacheline
   @vtype   unsigned long *
   @vio     out
   @vcomment
   Number of bytes in a cache line.
   @endvar
   @var     cache_size
   @vdesc   Size of the cache
   @vtype   unsigned long *
   @vio     out
   @vcomment
   The size (in bytes) of the cache.
   @endvar

   @returntype int
   @returndesc
   0  - success
   -1 - cache sizes have not been set yet.
   @endreturndesc

@@*/
int Utili_CacheDataGet(unsigned long *cacheline_bytes,
                       unsigned long *cache_size)
{
  if(cache_set)
  {
    *cacheline_bytes = cache_data.cacheline_bytes;
    *cache_size      = cache_data.cache_size;
  }

  return (cache_set ? 0 : -1);
}
