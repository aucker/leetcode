#include <stdbool.h>

#include "./uthash/src/uthash.h"

struct ListNode {
  int val;
  struct ListNode* next;
};

typedef struct {
  int key;
  struct ListNode* val;
  UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
  HashItem* pEntry = NULL;
  HASH_FIND_INT(*obj, &key, pEntry);
  return pEntry;
}

bool hashAddItem(HashItem** obj, int key, const struct ListNode* val) {
  if (hashFindItem(obj, key)) {
    return false;
  }
  HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
  pEntry->key = key;
  pEntry->val = val;
  HASH_ADD_INT(*obj, key, pEntry);
  return true;
}

bool hashSetItem(HashItem** obj, int key, const struct ListNode* val) {
  HashItem* pEntry = hashFindItem(obj, key);
  if (!pEntry) {
    hashAddItem(obj, key, val);
  } else {
    pEntry->val = val;
  }
  return true;
}

struct ListNode* hashGetItem(HashItem** obj, int key) {
  HashItem* pEntry = hashFindItem(obj, key);
  if (!pEntry) {
    return NULL;
  }
  return pEntry->val;
}

void hashFree(HashItem** obj) {
  HashItem *curr = NULL, *tmp = NULL;
  HASH_ITER(hh, *obj, curr, tmp) {
    HASH_DEL(*obj, curr);
    free(curr);
  }
}

struct ListNode* createListNode(int val) {
  struct ListNode* obj = (struct ListNode*)malloc(sizeof(struct ListNode));
  obj->val = val;
  obj->next = NULL;
  return obj;
}

struct ListNode* removeZeroSumSublists(struct ListNode* head) {
  struct ListNode* dummy = createListNode(0);
  dummy->next = head;
  int prefix = 0;
  HashItem* seen = NULL;
  for (struct ListNode* node = dummy; node; node = node->next) {
    prefix += node->val;
    hashSetItem(&seen, prefix, node);
  }
  prefix = 0;
  for (struct ListNode* node = dummy; node; node = node->next) {
    prefix += node->val;
    struct ListNode* curr = hashGetItem(&seen, prefix);
    if (curr) {
      node->next = curr->next;
    }
  }

  hashFree(&seen);
  struct ListNode* ret = dummy->next;
  free(dummy);
  return ret;
}