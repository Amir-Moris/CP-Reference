// ******************** ordered_set ******************** //
// dont`t forget to change data-type !! //
// ordered_multiset reverse upper_bound & lower_bound !! //
// find_by_order(k) // [iterator] {iterator on the Kth element} //
// order_of_key(k) // [int] {number of items < k} //

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class Type> using ordered_set = tree<Type, null_type, less<Type>, rb_tree_tag, tree_order_statistics_node_update>;
template<class Type> using ordered_multiset = tree<Type, null_type, less_equal<Type>, rb_tree_tag, tree_order_statistics_node_update>;

// ************************************************************************************** //
