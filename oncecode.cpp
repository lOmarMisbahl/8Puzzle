#include <bits/stdc++.h>
using namespace std;
set<string> vis ;
//      up down left right 
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
struct TreeNode {
	int zero; 
	string val ;
    vector<TreeNode *> v;
    TreeNode(string s ):val(s){
    	for(int i =0;i<s.size();i++) 
    		if(s[i]=='0')
    			zero = i ;
    	}
    bool isEmpty(){return v.size();}
    void newChild(TreeNode * N)
    {
    	v.push_back(N);
    }

};

int goal(string &s)
{ 
	int match =0;
	 for(int i =1;i<9;i++)
   	   if(s[i]==s[i-1]+1)
   	    	match++;
   	    if(match==8)
   	    return 1; 
   	return 0 ;
}
void print(string s )
{
   for(int i =0;i<3;i++)
    		{ 
      		  for(int j=0;j<3;j++)
      			cout<<s[i*3+j]<<" ";
      			cout<<endl;
      		}

      		cout<<endl;
}
 int  dfs(TreeNode * N)
 { 
 	if(vis.find(N->val) != vis.end())
  	 return 0;


     if(goal(N->val))
      {
      	print(N->val);
      	return  1; 
      }
   	
    vis.insert(N->val);
    int y = N->zero/3,x = N->zero%3,newX,newY;
    for(int i =0;i<4;i++)
    {
         newX= x+dx[i];
         newY= y+dy[i];
         if(newX>2||newX<0||newY>2||newY<0)
         	continue ;
         string newStr = N->val;
         swap(newStr[y*3+x],newStr[newY*3+newX]);
         TreeNode * child = new TreeNode(newStr);
        // N->newChild(child);
         if(dfs(child))
         {
         	print(N->val);
      		return 1 ;
         }
    }
    return 0;
 }



string Generate(int n )
{
    vector<int> arr(n,0);
    string ret  ;
    int found = n ;
    srand(time(NULL));
    while(found){	 
    int index = rand() % n;
    if(arr[index])
    	continue ;
    found -- ;
    ret.push_back(index+'0');
    arr[index]=1 ;
	}
	return ret ;
}
int main()
{
	//TreeNode * T = new TreeNode(Generate(9));
	TreeNode * T = new TreeNode("125340678");
	print(T->val);
    cout<<endl;
    cout<<dfs(T);


    
}

    