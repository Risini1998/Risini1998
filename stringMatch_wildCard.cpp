#include<iostream>
#include<string>

using namespace std;
 
int main(){
	string pattern,text;	//declare to store user pattern and text string

	cout<<" Enter TEXT: ";		
	getline(cin, text);		//get line as text for search pattern
	if(text.empty()==true)	//cheack text is empty
		text="";			//if text is empty set text as NULL
		
	cout<<"\n Enter PATTERN: ";	
	getline(cin, pattern);		//get line as search pattern with underscores
	if(pattern.empty()==true)	//cheack pattern is empty
		pattern="";				////if pattern is empty set pattern as NULL
	
	int len_text= text.length();	//length of text string
	int len_pattern= pattern.length();	//length of pattern string
	
	cout<<"\n Positions of text \'"<<text<<"\' where pattern \'"<<pattern<<"\' is found:\n";
	
	int i,j,flag=0;		//flag for identify whether pattern is found at lease once
	
	if(pattern=="")			//if pattern is null 
		cout<<"\n\t---Pattern is empty. Nothing to find in Text---\n";
	
	//if pattern is not null	
	else{
		for(i=0;i<=len_text-len_pattern;i++){	//start check the pattern from each position in text
		
			for(j=0;j<len_pattern;j++){			//check pattern in text from start position
			
				if(pattern[j]!=text[i+j] && pattern[j]!='_')	//if (j+1) th position of pattern is 
					break;					//underscore or equal to (i+j+1)th position of text inner
											//loop exucute. Overwise exit from it.
			}
			
			//if pattern found in (i+1)th position in text
			if(j==len_pattern){
				cout<<"\n\t"<<i+1<<" - \'"<<text.substr(i,len_pattern)<<"\'\n"; //print position and
																				//pattern found in text
			
				flag=1;			//found pattern once
			}
		}
	}
	
	//if pattern not found in text
	if(flag==0)				
			cout<<"\n\t---Pattern is not found in Text---\n";
	
	return 0;
}
