#include "bstree.h"

template<typename Key, typename Value>
bstree<Key, Value> test_copy_ctor(bstree<Key, Value>& lhs)
{
  int order = 1;

  auto set_order = [&](auto& node, int depth) { 
                       node.__order = order++; 
                       node.__recursion_depth = depth;
                       }; 

  // Set the order a node is visited when a pre-order traversal is done
  lhs.specialPreOrderTraverse(set_order);

  bstree<Key, Value> new_tree{lhs};

  return new_tree; 
}
