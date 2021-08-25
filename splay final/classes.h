#pragma once  
#include <iostream>
#include <cstdlib>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

    
	      
          
       
         
       

class Node
{
    public:
	string key="";
        string value="";

            int freq=0;
Node* left;
Node* right;


   friend istream& operator>>(istream& in,Node&br)
            {
            	cout<<"\n\n\n\n         Book Name   (Key Term)   :     ";
            	in.ignore(256, '\n'); //to take care of trailing /n in cin>> (at menu when we choose option)
                
				getline(in>>ws,br.key); //ws takes care of trailing spaces
				   
				cout<<"\n\n        Book value   :     ";
				//in.ignore(256, '\n');//no need 
				
			      
				getline(in>>ws,br.value); 
			      
				
					    return in;
			}
			
         friend ostream& operator<<(ostream& out, Node&br)
            {
            	cout<<"\n\n\n\n        Book Name   (Key Term)   :     "<<br.key
				        <<"\n\n        Book value   :     "<<br.value
		
					    <<"\n\n        frequency it was searched for      :     "<<br.freq;
					    return out;
			}
    operator=(Node& b)
    {
    	key=b.key;
    	value=b.value;
    	freq=b.freq;
	}

};

class Splay
{
	public:
Node* root=NULL;
		
Node* New_Node(string& key,string&);

Node* right_rotate(Node* k2);

Node* left_rotate(Node* k2);

void display(Node* );

void inorder(Node* );

void preorder(Node* );

Node* splay(string& key, Node* root);

Node* Insert(string& key,string & value,Node* root);

void postorder(Node* );

void makeEmpty(Node* );

Node* Delete(string& key, Node* root);

Node* Search(string& key, Node* root);

void search_guess(Node*,std::string&,std::vector<Node*>&);

void tree_to_vect(Node* ,std::vector<Node*>& );

int findDepth(Node* root, string x);

int findHeightUtil(Node* root, string x,int& height);

int findHeight(Node* root, string x);

void findaunt(Node*  p,string val);

void grandchild(Node*  p);

                   
          void matchoptions(Node*  t,string val);
		  int count(Node *p) ;  
		  
void treetoarray(Node* p,Node* arr[])
{
     static int index=0;
	if (p!=NULL)
	{
	   arr[index++]=p;
	  treetoarray(p->left,arr);
	  treetoarray(p->right,arr);
	}
}
 void longestpath(Node*  t); 
 void findauntanddel(Node*&  p,string val);




};

