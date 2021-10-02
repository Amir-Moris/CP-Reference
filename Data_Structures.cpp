ordered_set (dont`t forget to change data-type)
// dont`t forget to change data-type !!
// find_by_order(k) [iterator] {random access}
// order_of_key(k) [int] {number of items < k}
// ordered_multiset reverse upper_bound & lower_bound !!
  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename Type> using ordered_set = tree<Type, null_type, less<Type>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename Type> using ordered_multiset = tree<Type, null_type, less_equal<Type>, rb_tree_tag, tree_order_statistics_node_update> ;

// ************************************************************************************************************** //
