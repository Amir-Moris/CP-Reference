// ******************** ordered_set ******************** //
// ordered_multiset reverse upper_bound & lower_bound !! //
// find_by_order(k) [iterator] {iterator on the Kth element} //
// order_of_key(k) [int] {number of items < k} //

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ******************** priority_queue to sort descending ******************** //
priority_queue<T, vector<T>, greater<T>> pqgr;
