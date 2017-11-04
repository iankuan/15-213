/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */

    queue_t queue = {
        .head = NULL,
        .tail = NULL,
        .size = 0,
        };

    if (q) *q = queue;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (!q) return;
    /* How about freeing the list elements? */
    list_ele_t *cur = q->head, *prev;
    while (cur) {
        prev = cur;
        cur = cur->next;
        free(prev);
    }
    /* Free queue structure */
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    if (!q) goto err;

    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    newh = malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
    if (!newh) goto err;

    newh->value = v;
    newh->next = q->head;
    q->head = newh;
    q->tail = q->tail? q->tail: q->head;
    q->size++;
    return true;
err:
    return false;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    if (!q) goto err;
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    list_ele_t *newt;
    newt = malloc(sizeof(list_ele_t));
    if (!newt) goto err;

    newt->value = v;
    newt->next = NULL;
    q->head = q->head? q->head: newt;
    q->tail = q->tail? (q->tail->next = newt): newt;
    q->size++;
    return true;
err:
    return false;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    if (!q) goto err;
    /* You need to fix up this code. */
    if (!q->head) goto err;

    list_ele_t *prev = q->head;
    q->tail = q->head == q->tail? NULL: q->tail;
    q->head = q->head->next;
    if (vp) *vp = prev->value;
    free(prev);
    q->size--;
    return true;
err:
    return false;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (!q) return 0;
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    return q->size;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    if (!q || !q->head || !q->head->next) return;

    list_ele_t *cur = q->head->next, *prev = q->head, *next;
    for (int i = 0; i < q->size -1; i++) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    /* Modify head pointer to NULL */
    q->head->next = NULL;

    list_ele_t *tmp;
    tmp = q->head;
    q->head = q->tail;
    q->tail = tmp;
}

