#include <cstdlib>
#include <utility>
#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include "test.h"
#include "bstree.h"

using namespace std;

int main(int argc, char** argv) 
{
  
  using node_type = bstree<int, int>::node_type;
    
  class print_functor {
     
     int prior_level;

     public:

      print_functor() : prior_level{0}
      {
      }  

      void operator()(const node_type& node, int level) 
      {
         if (level !=  prior_level) {
              
               cout << "current level = " << level << "\n" << flush;
               prior_level = level; 
         }

         const auto&[key, value] = node.__vt.__get_value();

         cout << '[' << setw(3) << node.__order << ".] " << setw(4) << key << '\n' << flush; 
      } 
  };
  
  auto print_key = [](const auto& pr) {
      const auto&[key, value] = pr;
      cout << key << ", ";
  };
  
  // These ordered values produce a complete, i.e., balanced and full, bst.
  std::vector<int> int_vec = {100, 50, 200, 20, 70, 150, 250, -10, 40, 60, 90, 125, 175, 225, 275, -40, 10, 30, 45, 55, 65, 80, 95, 110, 130, 165, 190, 220, 230, 260, 290,\
    -70, -30, -5, 15, 25, 35, 42, 47, 52, 57, 62, 67, 92, 97, 105, 115, 127, 135, 160, 170, 180, 195, 210, 222, 227, 235, 260, 280 };

  bstree<int, int> bal_tree;
  
  for (const auto& i : int_vec) bal_tree.insert(i, i);
  
  cout << "\n--------------\nMaking a copy of the above bal_tree.\n"; 

  bstree<int, int> tree_copy = bal_tree;

  bal_tree.printlevelOrder(cout, print_key);

  int order = 0;
  int depth = 0;
  
// Set the order a node is visited when a pre-order traversal is done
  auto set_order = [&](node_type& node) { 
                       node.__order = ++order; 
                       }; 

  bal_tree.XXpreOrderTraverse(set_order, root, depth);

  bal_tree.levelOrderTraverse(print_functor()); 
  
  tree_copy.mimic_ctor(); // set __order ordering to the call order of a recursive Node ctor implementation.
  
  cout << "\n\nOrder of mimmiced recursive Node copy ctor\n\n";

  tree_copy.levelOrderTraverse(print_functor()); 

  return 0;

  cout << "floor(37) = " << bal_tree.floor(37) << '\n';

  cout << "ceiling(37) = " << bal_tree.ceiling(37) << '\n';
 
  cout << "floor(41) = " << bal_tree.floor(41) << '\n';

  cout << "ceilling(41) = " << bal_tree.ceiling(41) << '\n';

  bal_tree.printlevelOrder(cout, print_key);

  for (const auto& x : int_vec) {

     cout << "--------------------------------\n";
       
     cout << "bal_tree.remove(" << x << ")\n";
     
     bal_tree.remove(x);
     bal_tree.printlevelOrder(cout, print_key);
  } 

  return 0;
  /*      
  cout << "This is the input tree " << tree << " printed in debug level order:\n";
  
  tree.debug_printlevelOrder(cout);

  cout << "We now start the removal loop\n";
  
  for (const auto& key : lst) {
      
      cout << "Tree before removal of Test{" << key << "} " << tree; 
      
      if (key == 65) {
          auto debug = 10;
          ++debug;
      }
               
      //tree.remove(Test{key});
      tree.remove(key);

      cout << "Tree after removal of Test{" << key << "}. " << tree; 
      cout << "\nLevel-order print after the removal of Test{" << key << "}\n";
      
      tree.printlevelOrder(cout, print_key);

      cout << flush << "\nDebug print\n";

      tree.debug_printlevelOrder(cout);
  }

  return 0;
*/
/*

    bstree<Test, Test> tree1 = { 5, 15, 7, 17, 3, 13, 4, 14,  2, 12,  6, 16, 9, 19}; 
    
    cout << "tree1 = " << tree1 << '\n' << "Printing tree1 level order:\n";
    
    tree1.printlevelOrder(cout);
        
    bstree<Test> tree2 = { Test{15}, Test{25}, Test{17}, Test{27}, Test{13}, Test{23}, Test{14}, Test{24},  Test{12}, Test{41},  Test{16}, Test{6}, Test{19}, Test{20}}; 
    
    cout << "\ntree2 = " << tree2 << "\nPrinting tree2 level order:\n";
    
    tree2 = tree1; 
    tree2.printlevelOrder(cout);
    
   cout << "\nAfter 'tree2 = tree1', tree2 = " << tree2 << "\nPrinting tree2 level order:\n" << flush;
   tree2.printlevelOrder(cout);
   
   vector<int> vec = {-5, -15, -7, -17, -3, -13, -4, -14,  -2, -12,  -6, -16, -9, -19}; 
   for (const auto& ref : vec) {

     tree2.remove(ref); 

     cout << "After removing " << ref << " from tree2, tree2 = \n";
     
     tree2.printlevelOrder(cout);
     cout << flush;
   }
   
   return 0;
 * */
}

