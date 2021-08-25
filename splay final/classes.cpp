#include "classes.h"
#include <iostream>
#include <cstdlib>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
		
  void Splay::longestpath(Node*  t)  
  {
  	int rh=-1,lh=-1;
  	    if(t==NULL)
  	    {
  	    	return;
		  }
		  cout<<"  "<<t->key<<"  ";
		  if(t->right!=NULL)
		  {
		        rh=findHeight(t,t->right->key);
	       }
	       if(t->left!=NULL)
	       {
		       lh=findHeight(t,t->left->key) ;
			}
			if(rh>lh)
			{
				 longestpath(t->right);
			}
			else
			{
				longestpath(t->left);
			}
  	    
  }

 
    void Splay:: inorder(Node*  t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
          cout<<"         "<<t->key;
        inorder(t->right);
    }
       
	 int  partialmatch(string a,string b) 
	  {
	  	  if(a[0]==b[0])
	  	  {
	  	  	   if(a[1]==b[1])
	  	  	   {
	  	  	   	     if(a[2]=b[2])
	  	  	   	     {
	  	  	   	     	   return 1; 
					}
				}
			}
			return 0;
	  }
  void Splay::matchoptions(Node*  t,string val)
    {
        if(t == NULL)
            return;
        matchoptions(t->left,val);
        if(partialmatch(t->key,val))
        {
        	 cout<<"\n   "<<t->key<<"\n    ";
        	
        }
        matchoptions(t->right,val);
    } 
        
int Splay::count(Node *p)
{
    int c =  1;             //Node itself should be counted
    if (p ==NULL)
        return 0;
    else
    {
        c += count(p->left);
        c += count(p->right);
        return c;
    }
}

void Splay::preorder(Node*  p)
{
	if (p!=NULL)
	{
	    cout<<"         "<<p->key;
	  preorder(p->left);
	  preorder(p->right);
	}
}


void Splay::grandchild(Node*  p)
{
	 int rrh,rlh,llh,lrh;
	if (p!=NULL)
	{
	      cout<<"\n\n\n  inside node   "<<p->key;cout<<"            heights:  ";
		  Node* r=p->right;
	      Node* l=p->left;
	      if(r!=NULL)
	      {
	      	 Node* rr=r->right;
	      	 if(rr!=NULL)
	      	 {
			        //rrh=rr->height;
			        
			        rrh=findHeight(p,rr->key);
			        cout<<rrh<<"   ";
			        
			   }
	      	 Node* rl=r->left;
	      	  if(rl!=NULL)
	      	 {
	      	 	  //rlh=rl->height;
	      	 	   rlh=findHeight(p,rl->key);
	      	 	   cout<<rlh<<"   ";
	      	 }
			        
		  }
		  if(l!=NULL)
	      {
	      	Node* lr=l->right;
	      	 if(lr!=NULL)
	      	 {
			       
			        //lrh=lr->height;
			         lrh=findHeight(p,lr->key);
			          cout<<lrh<<"   ";
			   }
	      	 Node* ll=l->left;
	      	  if(ll!=NULL)
	      	 {
			        //llh=ll->height;
			         llh=findHeight(p,ll->key);
			          cout<<llh<<"   ";
		      }
		  }
	      
	      if(llh==lrh)
	      {
	      	if(rlh==rrh)
	      	{
	      		if(rrh==lrh)
	      		{
	      			cout<<" all of key: "<<p->key<<" address: "<<p<<"  's grandchildren are at height "<<rrh;
				  }
			  }
		  }
	      
	 grandchild(p->left);
	  grandchild(p->right);
	}
}


void Splay::findaunt(Node*  p,string val)
{
	if (p!=NULL)
	{
	      Node* r=p->right;
	      Node* l=p->left;
	      if(r!=NULL)
	      {
	      	 Node* rr=r->right;
	      	 if(rr!=NULL)
	      	 {
			        if(rr->key==val)
			        {
			        	cout<<"\n\n grandparent is  :  "<<p->key<<" at address "<<p;
						cout<<"\n\n parent is  :  "<<r->key<<" at address "<<r;
			        	
						if(l!=NULL)
						{
						cout<<"\n\n aunt is : "<<l->key<<" at address "<<l;
				        	}
				        	else
				        	{
				        		cout<<"\n\n aunt doesnt exsist \n\n ";
							}
					}
			        
			   }
	      	 Node* rl=r->left;
	      	  if(rl!=NULL)
	      	 {
			        if(rl->key==val)
			        {
			        	cout<<"\n\n grandparent is  :  "<<p->key<<" at address "<<p;
						cout<<"\n\n parent is  :  "<<r->key<<" at address "<<r;
			        	
						if(l!=NULL)
						{
						cout<<"\n\n aunt is : "<<l->key<<" at address "<<l;
				        	}
				        	else
				        	{
				        		cout<<"\n\n aunt doesnt exsist \n\n ";
							}
					}
			        
			   }
		  }
		  if(l!=NULL)
	      {
	      	Node* lr=l->right;
	      	 if(lr!=NULL)
	      	 {
			        if(lr->key==val)
			        {
			        	cout<<"\n\n grandparent is  :  "<<p->key<<" at address "<<p;
						cout<<"\n\n parent is  :  "<<l->key<<" at address "<<l;
			        	
						if(r!=NULL)
						{
						cout<<"\n\n aunt is : "<<r->key<<" at address "<<r;
				        	}
				        	else
				        	{
				        		cout<<"\n\n aunt doesnt exsist \n\n ";
							}
					}
			        
			   }
	      	 Node* ll=l->left;
	      	  if(ll!=NULL)
	      	 {
			        if(ll->key==val)
			        {
			        	cout<<"\n\n grandparent is  :  "<<p->key<<" at address "<<p;
						cout<<"\n\n parent is  :  "<<l->key<<" at address "<<l;
			        	
						if(r!=NULL)
						{
						cout<<"\n\n aunt is : "<<r->key<<" at address "<<r;
				        	}
				        	else
				        	{
				        		cout<<"\n\n aunt doesnt exsist \n\n ";
							}
					}
			        
			   }
		  }
	      
	 findaunt(p->left,val);
	  findaunt(p->right,val);
	}
}


void Splay::postorder(Node*  p)
{
        if (p!=NULL)
        {
	   postorder(p->left);
	   postorder(p->right);
	   cout<<"          "<<p->key;
	}
}
 


    void Splay::display(Node* root)
    { 
        cout<<"\n\n\n\n      inorder traversal  :\n\n\n       ";
		inorder(root);
		cout<<"\n\n\n\n      preorder traversal  :\n\n\n      ";
        preorder(root);
        cout<<"\n\n\n\n      postorder traversal  :\n\n\n       ";
        postorder(root);
        cout << endl;
    }


inline Node* Splay::left_rotate(Node* k2)
{
	Node* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	return k1;
}


inline Node* Splay::right_rotate(Node* k2)
{
	Node* k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	return k1;
}

 
Node* Splay::splay(string& key, Node* root)
{
	if(root==NULL)
		return NULL;
	Node header;

	header.left = header.right = NULL;
	Node* LeftTreeMax = &header;
	Node* RightTreeMin = &header;


	while(1)
	{
		if(key < root->key)
		{
			if(!root->left)
				break;
			if(key < root->left->key)
			{
				root = left_rotate(root);
				if(!root->left)
					break;
			}
			/* Link to R Tree */
			RightTreeMin->left = root;
			RightTreeMin = RightTreeMin->left;
			root = root->left;
			RightTreeMin->left = NULL;
		}
		else if(key > root->key)
		{
			if(!root->right)
				break;
			if(key > root->right->key)
			{
				root = right_rotate(root);
				if(!root->right)
					break;
			}
		
			LeftTreeMax->right = root;
			LeftTreeMax = LeftTreeMax->right;
			root = root->right;
			LeftTreeMax->right = NULL;
		}
		else
			break;
	}
	
	LeftTreeMax->right = root->left;
	RightTreeMin->left = root->right;
	root->left = header.right;
	root->right = header.left;
	
	return root;
}


Node* Splay::New_Node(string& key,string &value)
{
	Node* p_node = new Node;
	if(!p_node)
	{
		fprintf(stderr, "Out of memory!\n");
		exit(1);
	}
	p_node->key = key;
	p_node->value = value;
	p_node->left = p_node->right = NULL;
	return p_node;
}


    
 void Splay::makeEmpty(Node* node) 
{ 
    if (node == NULL) return; 
  
   
    makeEmpty(node->left); 
    makeEmpty(node->right); 
      
   
    cout << "\n\n          Deleting node:        " << node->key; 
    delete node;
} 
 
Node* Splay::Insert(string& key,string & value ,Node* root)
{
	static Node* p_node = NULL;
	if(!p_node)
		p_node = New_Node(key,value);
	else 
		{
		    p_node->key = key;
		    p_node->value=value;
         	}
	if(!root)
	{
		root = p_node;
		p_node = NULL;
		return root;
	}
	root = splay(key, root);
	
	if(key < root->key)
	{
		p_node->left = root->left;
		p_node->right = root;
		root->left = NULL;
		root = p_node;//overload operator =
	
		
	}
	else if(key > root->key)
	{
		p_node->right = root->right;
		p_node->left = root;
		root->right = NULL;
		root = p_node;
		
	}
	else
		return root;
	p_node = NULL;
	return root;
}



void Splay::findauntanddel(Node*&  p,string val)
{
	if (p!=NULL)
	{
	     findaunt(p,val);
	     p=Delete(val,p);
	}
}


 
Node* Splay::Delete(string& key, Node* root)
{
	Node* temp;
	if(!root)
		return NULL;
	root = splay(key, root);
	if(key != root->key) 
	 {
	  cout<<" element not present";
		return root;
}
	else
	{
		if(!root->left)
		{
			temp = root;
			root = root->right;
		}
		else
		{
			temp = root;
			
			root = splay(key, root->left);
			root->right = temp->right;
		}
		free(temp);
		return root;
	}
}


Node* Splay::Search(string& key, Node* root)
{
	Node* x=splay(key, root);
	if(x!=NULL)
	 {
	 x->freq++;
       }
	return x;
}



    void Splay::tree_to_vect(Node* node,vector<Node*>& temp)
    {
	       
	       if(node==NULL) return;
	       temp.push_back(node);
	       tree_to_vect(node->right,temp);
	       tree_to_vect(node->left,temp);
	       
	}


  
  
  
	void Splay::search_guess(Node* node,string& guess,vector<Node*>& temp)
    {
      	   if(node==NULL) return;int count=0;
			string str;
			str=node->key;
		
			 if(str.length()<3) return;
		bool flag=false;
      	   
      	   for(int i=0;i<=str.length()-3;i++)
      	   { 
      	      
      	   	   
      	   	     
			      for(int j=0;j<=guess.length()-3;j++)
      	   	       {
      	   	       	  count=0;
      	   	       	    for(int k=0;k<3;k++)
						{ 
							if(guess[j+k]==str[i+k])
							  count++;
						}
      	   	       	     if(count==3)
      	   	       	         {temp.push_back(node);flag=true;break;}
					}
					if(flag) break;
			 }
      	   
      	   	      
			 
	       
	      
	       
	      search_guess(node->right,guess,temp);
	       search_guess(node->left,guess,temp); 	
				 
	}
	
	
	int Splay::findDepth(Node* root, string x)
{
    // Base case
    if (root == NULL)
        return -1;
 
    // Initialize distance as -1
    int dist = -1;
 
    // Check if x is current node=
    if ((root->key== x)
 
        // Otherwise, check if x is
        // present in the left subtree
        || (dist = findDepth(root->left, x)) >= 0
 
        // Otherwise, check if x is
        // present in the right subtree
        || (dist = findDepth(root->right, x)) >= 0)
 
        // Return depth of the node
        return dist + 1;
 
    return dist;
}
 
// Helper function to find the height
// of a given node in the binary tree
int Splay::findHeightUtil(Node* root, string x,
                   int& height)
{
    // Base Case
    if (root == NULL) {
        return -1;
    }
 
    // Store the maximum height of
    // the left and right subtree
    int leftHeight = findHeightUtil(
        root->left, x, height);
 
    int rightHeight
        = findHeightUtil(
            root->right, x, height);
 
    // Update height of the current node
    int ans = max(leftHeight, rightHeight) + 1;
 
    // If current node is the required node
    if (root->key == x)
        height = ans;
 
    return ans;
}
 
// Function to find the height of
// a given node in a Binary Tree
int Splay::findHeight(Node* root, string x)
{
    // Store the height of
    // the given node
    int h = -1;
 
    // Stores height of the Tree
    int maxHeight = findHeightUtil(root, x, h);
 
    // Return the height
    return h;
}
	
   

