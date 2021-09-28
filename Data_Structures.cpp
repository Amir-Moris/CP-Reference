ordered_set (dont`t forget to change data-type)
// dont`t forget to change data-type !!
// find_by_order(k) [iterator] {random access}
// order_of_key(k) [int] {number of items < k}
  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

// ************************************************************************************************************** //
