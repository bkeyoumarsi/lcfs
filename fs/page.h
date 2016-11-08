#ifndef _PAGE_H_
#define _PAGE_H_

#include "includes.h"

#define DFS_PAGE_HOLE       ((uint64_t)-1)
#define DFS_PAGE_NOBLOCK    ((uint64_t)-2)

/* Initial size of the page hash table */
/* XXX This needs to consider available memory */
#define DFS_PCACHE_SIZE (1024 * 1024)

/* Page cache header */
struct pcache {

    /* Lock protecting the hash chain */
    pthread_mutex_t pc_lock;

    /* Page hash chains */
    struct page *pc_head;

    /* Count of pages in use */
    uint64_t pc_pcount;
};


/* Page structure used for caching a file system block */
struct page {

    /* Data associated with page of the file */
    char *p_data;

    /* Block mapping to */
    uint64_t p_block;

    /* Next page in block hash table */
    struct page *p_cnext;

    /* Lock protecting operations on the page */
    pthread_rwlock_t p_lock;
} __attribute__((packed));

#endif