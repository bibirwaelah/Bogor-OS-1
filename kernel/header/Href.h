#define _HREF_H_

struct pcpu_freelist_head {
	struct pcpu_freelist_node *first;
	raw_spinlock_t lock;
};

struct pcpu_freelist {
	struct pcpu_freelist_head __percpu *freelist;
};

struct pcpu_freelist_node {
	struct pcpu_freelist_node *next;
};

void pcpu_freelist_push(struct pcpu_freelist *, struct pcpu_freelist_node *);
struct pcpu_freelist_node *pcpu_freelist_pop(struct pcpu_freelist *);
void pcpu_freelist_populate(struct pcpu_freelist *s, void *buf, u32 elem_size,
			    u32 nr_elems);
int pcpu_freelist_init(struct pcpu_freelist *);
void pcpu_freelist_destroy(struct pcpu_freelist *s);
#endif
