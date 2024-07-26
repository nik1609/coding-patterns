// problem Link: https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
  /*
    1- create an array of inorder traversal
    2- pair<int,bool> : 0 if not leaf, 1 if leaf
    3- find all the leaf
    4- traverse full array
    5- if arr[i].second==TRUE{
        if(i==0) check for diff {
            if(arr[i]-0 ==1 and arr[i+1]-arr[i]==1) 
        else check prd and succ
    }
  */
  
    void createArray(Node* root, vector<int>&arr){
        if(root==NULL) return;
        createArray(root->left, arr);
        arr.push_back(root->data);
        createArray(root->right, arr);
        
    }
    
    void markLeaf(Node* root, unordered_map<int, int>&isLeaf){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL) {
            isLeaf[root->data]++;
            return;
        }
        markLeaf(root->left, isLeaf);
        markLeaf(root->right, isLeaf);
    }
  
    bool isDeadEnd(Node *root)
    {
        vector<int>arr;
        createArray(root,arr);
        unordered_map<int,int>isLeaf;
        markLeaf(root,isLeaf);
        
        int n = arr.size();
        for(int i=0;i<n;i++){
            int pre = 0;
            int suc = 0;
            if(isLeaf[arr[i]]){
                // if its 0th Index
                if(i==0 and i+1<n and arr[i]-0==1 and arr[i+1]-arr[i]==1  ){
                    return true;
                }
                if(i-1>=0 and i+1<n and arr[i]-arr[i-1]==1 and arr[i+1]-arr[i]==1 ){
                    return true;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends