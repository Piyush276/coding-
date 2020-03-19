/*
* @Author: piyush
* @Date:   2020-02-17 22:32:53
* @Last Modified by:   piyush
* @Last Modified time: 2020-02-18 12:41:38
*/
//// REFERENCE ->     https://www.geeksforgeeks.org/foldable-binary-trees/
////////////////////////////////////////  two approachs 


///////////   FIRST
// void mirror(Node *root){
//     if(root==NULL){
//         return;
//     }
//     mirror(root->left);
//     mirror(root->right);
    
//     swap(root->left,root->right);
// }

// bool is_struct(Node *n1,Node *n2){
//     if(n1==NULL and n2==NULL){
//         return true;
//     }
//     if(n1==NULL or n2==NULL){
//         return false;
//     }
    
//     if(is_struct(n1->left,n2->left) and is_struct(n1->right,n2->right) )
//     return true;
//     else{
//         return false;
//     }
    
    
// }


// bool IsFoldable(Node* root)
// {
//     if(root==NULL)  
//     {
//         return true;
//     }
    
//     mirror(root->left);
//     bool ans=is_struct(root->left,root->right);
//     mirror(root->left);
//     return ans;
// }



///////////////////////////////////			SECOND APPROACH



// bool check(Node *n1, Node *n2){
//     if(n1==NULL and n2== NULL){
//         return true;
//     }
//     if(n1==NULL or n2== NULL){
//         return false;
//     }
    
//     return (check(n1->left,n2->right) and check(n1->right,n2->left));
// }

// bool IsFoldable(Node* root)
// {
//     if(root==NULL)  
//     {
//         return true;
//     }
    
//     return check(root->left,root->right);
    
// }
