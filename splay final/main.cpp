#include <iostream>
#include <cstdlib>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#include "classes.h"

void swap(Node* &xp,Node* &yp)
{
    Node* temp = xp;
    xp = yp;
    yp = temp;
}
 
// A function to implement bubble sort descending order
void bubbleSort(Node* arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j]->freq < arr[j+1]->freq)
            swap(arr[j], arr[j+1]);
}		


bool func(Node*& book1,Node*& book2)//v.v.imp must pass parameters by reference 
	{
		return (book1->freq>book2->freq);
	}

	

   vector<Node*> sort_by_freq(Splay& at,Node*& root)
    {
	       
	       vector<Node*> arr={};
		   at.tree_to_vect(root,arr);
		   sort(arr.begin(),arr.end(),func);
		   return arr;
		   //member function pointers complex
	       
	}
	
	
int main() {

  Splay at;string a,b,key;
	Node* root = NULL;
	 vector<int> output;
 vector<Node*> vec;
  vector<Node*> vec2;	



	int input;
	int option=0;
	int type,k=0;


	string guess;
	

  do {
  
cout<<"\n\n\n\n       "    
<<"\n\n     1.	Insert into the Book index with appropriate key term, value and page number if a new term comes."
<<"\n\n     2.	Delete the entry from the book index if the term is no longer needed."
<<"\n\n     3.	If key term is given as input, corresponding value has to be retrieved and the key term should splay to the top of the tree."
<<"\n\n     4.(use 11)	Find the key terms which are frequently searched. Display the number of times each key term has been searched in descending order."
<<"\n\n     5.	Suitable display operations for every operation stated above."
<<"\n\n     6.	Display of all key terms if a partial match occurs for 3 letters - Once the user"
" chooses the appropriate term from the list of key terms displayed - corresponding value has to be displayed."
<<"\n\n     7.   height and depth of a node"
<<"\n\n     8.   min and max node"
<<"\n\n 9.	Given a search key, find and display the siblings of the parent of the search key. "
<<"\n\n  10. find all nodes whose grandchildren are sae height "
<<"\n\n  11. tree to array"
<<"\n\n  12. longest path"
<<"\n\n  13. find aunt and del"
<<"\n\n     0.   makeEmpty and Exit"
<<"\n\n\n\n              Enter option         ";
fflush(stdout);
    cin >> option;
   
    //Node n1;
   Node* arr[100];

    switch (option) {
    
    case 1:
      
      cout<<"\n\n\n                                  Enter book details key,value  ";
        fflush(stdout);
        	cout<<"\n\n\n\n         Book Name   (Key Term)   :     ";
            	cin.ignore(256, '\n'); //to take care of trailing /n in cin>> (at menu when we choose option)
                
				getline(cin>>ws,a); //ws takes care of trailing spaces
				   
				cout<<"\n\n        Book value   :     ";
				//in.ignore(256, '\n');//no need 
				cin>>b;
				
			      
				
 
  
      root = at.Insert(a,b,root);
      
      
      break;
    
    case 2:  
       cout<<"\n\n\n     enter key(book name) to delete    :     ";cin>>key;
      
		 
		     root=at.Search(key,root);
		     
		     root=at.Delete(key,root);
		     
	  
    
     
      break;
      
      case 3:
  
      
		       cout<<"\n\n\n     enter key(book name) to seach for    :     ";cin>>key;
    
		      
		
		     root=at.Search(key,root);
		     
		     if(root!=NULL)
		     {
			     if(root->key!=key) 
		        {
		     	cout<<" element not present ";break;
			     }
			 cout<<"\n   key :   "<<root->key<<"\n   value:  "<<root->value<<"\n    freq:  "<<root->freq;}
		     
		  
     		 break;
     		 
       case 4 :
       	            cout<<"\n\n\n\n\n    sorted by frequencies:\n\n     ";
					   vec=sort_by_freq(at,root);
       	            
       	            for(auto i=begin(vec);i!=end(vec);i++)
       	            {
       	            	cout<<"\n\n      "<<(*i)->key<<"     has been searched for    "<<(*i)->freq<<"      times\n";
					   }
					   vec={};//empty the vec after use
					   break;
    case 5:
      at.display(root);
      break;
      
      case 6:
      	       cout<<"\n\n\n   enter a string, partial match occurs if 3 letters match   :    ";
      	       cin>>guess;
      	       at.matchoptions(root,guess);
      	       /*at.search_guess(root,guess,vec2);
      	       if(vec2.size()==0) {
				 cout<<" no match";break;}
      	       cout<<"\n\n\n     partial matched keys   \n\n\n  ";
      	       for(auto i=begin(vec2);i!=end(vec2);i++)
       	            {
       	            	cout<<"\n\n        "<<((*i)->key);
					}
					*/
					
				cout<<"\n\n   choose key  ";
				cin>>key;
		      
		     root=at.Search(key,root);
		     cout<<root->key;
		     //vec2={};//empty the vector after use;
		     break;
      	       
      	       
     case 7: cout<<" \n\n   enter node whose height to search for ";
                cin>>a;
                cout<<" \n\n    node  is at height  :  "<<at.findHeight(root,a)<<" and depth :  "<<at.findDepth(root,a);
                break;
                
      
     case 9:   cout<<" enter key to find siblings of parents of ";
               cin>>a;at.findaunt(root,a);
               break;
               
    case 10:   
              at.grandchild(root);
               break;
    case 11:
               k=at.count(root);
              
            at.treetoarray(root,arr);
            bubbleSort(arr,k);
               for(int i=0;i<k;i++)
				{
				cout<<"   "<<arr[i]->key<<" has been searched   "<<arr[i]->freq<<"  times";
				}
				break;
				
	 case 12:    at.longestpath(root);break;
	 case 13: cout<<" enter key to find siblings of parents of ";
               cin>>a;at.findauntanddel(root,a);break;

      case 0:
      	cout<<"\n\n";
     	 at.makeEmpty(root);
     	 cout<<"\n\n\n\n";
      	 break;
      	 
    
    default:
      cout << "\n\n  Enter Proper Option number    " << endl;break;
    }

  } while (option != 0);
cout<<"\n\n\n                        exited   \n\n\n\n\n\n";
  return 0;
}





















