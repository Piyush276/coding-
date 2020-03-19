/*
* @Author: piyush
* @Date:   2020-03-04 10:06:16
* @Last Modified by:   piyush
* @Last Modified time: 2020-03-04 10:06:18
*/


 void buildTree(int tree[], int array[], int index, int low, int high) {
     if (low == high) {
         if (array[low] == 0) {
             tree[index] = 1;
         } else {
             tree[index] = 0;
         }
     } else {
         int mid = (low + high) / 2;
         buildTree(tree, array, index * 2, low, mid);
         buildTree(tree, array, index * 2 + 1, mid + 1, high);
         tree[index] = tree[index * 2] + tree[index * 2 + 1];
     }
 }

 void updateTree(int tree[], int index, int low, int high, int pos, int new_val) {
     if (low == high) {
         if (new_val == 0) {
             tree[index] = 1;
         } else {
             tree[index] = 0;
         }
     } else {
         int mid = (low + high) / 2;
         if (pos <= mid) {
             updateTree(tree, index * 2, low, mid, pos, new_val);
         } else {
             updateTree(tree, index * 2 + 1, mid + 1, high, pos, new_val);
         }
         tree[index] = tree[index * 2] + tree[index * 2 + 1];
     }
 }

 int find_kth(int tree[], int index, int low, int high, int k) {
     if (tree[index] < k) {
         return -1;
     }
     if (low == high) {
         return low;
     }
     int mid = (low + high) / 2;
     if (tree[index * 2] >= k) {
         return find_kth(tree, index * 2, low, mid, k);
     } else {
         return find_kth(tree, index * 2 + 1, mid + 1, high, k - tree[index * 2]);
     }
 }

 int main() {
     int n, m;
     scanf("%d%d", &n, &m);
     int arr[n], tree[4 * n + 1];
     for (int i = 0; i < n; i++) {
         scanf("%d", &arr[i]);
     }
     buildTree(tree, arr, 1, 0, n - 1);
     for (int i = 0; i < m; i++) {
         int type, k, pos, val;
         scanf("%d", &type);
         if (type == 1) {
             scanf("%d", &k);
             int ans = find_kth(tree, 1, 0, n - 1, k);
             if (ans == -1) {
                 printf("NO\n");
             } else {
                 printf("%d\n", ans);
             }
         } else {
             scanf("%d%d", &pos, &val);
             if (pos < n) {
                 updateTree(tree, 1, 0, n - 1, pos, val);
             }
         }
     }
     return 0;
 }

