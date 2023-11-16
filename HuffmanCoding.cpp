#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100

class huffTree{
  public:
      char data;
      int freq;
      huffTree* left;
      huffTree* right;
      huffTree(char data,int freq)
      {
          this->data = data;
          this->freq = freq;
          left=right=NULL;
      }
};

class Compare{
  public:
      bool operator()(huffTree* a,huffTree* b)
      {
          return a->freq > b->freq;
      }
};

huffTree* generateTree(priority_queue<huffTree*,vector<huffTree*>,Compare> pq)
{
    while(pq.size()!=1)
    {
        huffTree *left = pq.top();
        pq.pop();
        huffTree *right = pq.top();
        pq.pop();
        
        huffTree *node = new huffTree('$',left->freq + right->freq);
        node->left = left;
        node->right = right;
        pq.push(node);
    }
    return pq.top();
}


void printcode(vector<int> arr,int top, huffTree *root)
{
    if(root->left)
    {
        arr[top] = 0;
        printcode(arr,top+1,root->left);
    }
    if(root->right)
    {
        arr[top] = 1;
        printcode(arr,top+1,root->right);
    }
    if(!root->left && !root->right)
    {
        cout<<root->data<<" ";
        for(int i=0;i<top;i++)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }
}

void huffmanCode(vector<char> data,vector<int> freq)
{
    priority_queue<huffTree *,vector<huffTree *>,Compare> pq;
    
    for(int i=0;i<data.size();i++)
    {
        huffTree *newnode = new huffTree(data[i],freq[i]);
        pq.push(newnode);
    }
    
    huffTree *root = generateTree(pq);
    
    vector<int> arr(MAX_SIZE);
    int top=0;
    printcode(arr,top,root);
    
}


int main()
{
    int n;cin>>n;
    vector<int> freq(n);
    vector<char> data(n);
    
    cout<<"Enter "<<n<<" characters: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    
    cout<<"Enter Frequencies"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>freq[i];
    }
    
    huffmanCode(data,freq);
    return 0;
}

/*
    Input ->
    6
    a b c d e f
    5 9 12 13 16 45

    Output ->
    f 0
    c 100
    d 101
    a 1100
    b 1101
    e 111
*/

/*
    Complexity Analysis --> 
    Time Complexity -> O(n log(n))
    Space Complexity -> O(n)
*/
