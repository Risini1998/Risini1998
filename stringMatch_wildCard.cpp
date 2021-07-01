#include<iostream>
#include<fstream>

using namespace std;

ofstream output;	//to write output a file

void match(string text,string pattern)
{
	int len_text= text.length();		
	int len_pattern= pattern.length();	
	
	cout<<"\n Positions of text \""<<text<<"\" , where pattern \""<<pattern<<"\" is found:\n";
	
	//write output to output file
	output<<"\n Positions of text \""<<text<<"\" , where pattern \""<<pattern<<"\" is found:\n";

	int i,j,flag=0;		//flag for identify whether pattern is found at lease once
	
	//if pattern is null 
	if(pattern==""){			
		cout<<"\n\t---Pattern is empty. Nothing to find in Text---\n";
		output<<"\n\t---Pattern is empty. Nothing to find in Text---\n";
	}
	//if pattern is not null neive string matching start	
	else{
		for(i=0;i<=len_text-len_pattern;i++){	
		
			for(j=0;j<len_pattern;j++){		
			
				//if (j+1) th position of pattern is not underscore or
				//not equal to (i+j+1)th position of text 
				if(pattern[j]!=text[i+j] && pattern[j]!='_')	
					break;					
			}
			
			//if pattern found in (i+1)th position in text
			if(j==len_pattern){
				
				//print position and pattern in text
				cout<<"\n\t"<<i+1<<" - \'"<<text.substr(i,len_pattern)<<"\'\n"; 
				output<<"\n\t"<<i+1<<" - \'"<<text.substr(i,len_pattern)<<"\'\n";
				
				flag=1;			//found pattern once
			}
		}
	}
	
	//if pattern not found in text
	if(flag==0)				
			cout<<"\n\t---Pattern is not found in Text---\n";
			output<<"\n\t---Pattern is not found in Text---\n";	
}

//to read file and return line
string fileread(string filename, int fileno){
	string line,file;
	file=filename + to_string(fileno) + ".txt";	//prepare file name to read file
	ifstream infile;				//file pointer
	infile.open (file.c_str());			//open file to read
	getline(infile,line);				//read line and store
	infile.close();					//close file
	return line;
}

int main(){
	string pattern,text,outfile;	//declare to store user pattern and text string
	bool run=true;
	int i=1;
	int no=6;		//6 test cases
	char con;
	
	do{
		cout<<"\n ---------------------TEST CASE "<<i<<"------------------------";
		text=fileread("Test/Text/text",i);				//read i th text file
		pattern=fileread("Test/Pattern/pattern",i);			//read i th pattern file
		
		outfile= "Test/Output/patternmatch" + to_string(i) + ".output";	//prepare file name to write output
		output.open(outfile.c_str());					//open output file
	
		match(text,pattern);						//search pattern in text
		output.close();							//close output file
	
		i++;
		
		if(i<=no){
			cout<<"\n Continue? [Y/N]";
			cin>>con;
			if(con=='N' || con=='n')
				run=false;
		}
			
	}while(run && i<=no);		//loop if user want continue and have test case to run
	
	return 0;
}
