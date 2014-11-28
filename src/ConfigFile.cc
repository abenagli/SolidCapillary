// ConfigFile.cpp

#include "ConfigFile.hh"
#include <vector>
#include <utility>
using std::string;
using namespace std;

ConfigFile::ConfigFile( string filename, string delimiter,
                        string comment, string vectSep, string sentry )
	: myDelimiter(delimiter), myComment(comment), myVectorSep(vectSep), mySentry(sentry)
{
	// Construct a ConfigFile, getting keys and values from given file
	
	std::ifstream in( filename.c_str() );
	FILENAME=filename;
	if( !in ) throw file_not_found( filename ); 
	
	in >> (*this);
}


ConfigFile::ConfigFile()
	: myDelimiter( string(1,'=') ), myComment( string(1,'#') )
{
	// Construct a ConfigFile without a file; empty
}


void ConfigFile::remove( const string& key )
{
	// Remove key and its value
	myContents.erase( myContents.find( key ) );
	return;
}


bool ConfigFile::keyExists( const string& key ) const
{
	// Indicate whether key is found
	mapci p = myContents.find( key );
	return ( p != myContents.end() );
}


/* static */
void ConfigFile::trim( string& st )
{
	// Remove leading and trailing whitespace
	static const char whitespace[] = " \n\t\v\r\f";
	st.erase( 0, st.find_first_not_of(whitespace) );
	st.erase( st.find_last_not_of(whitespace) + 1U );
}


std::ostream& operator<<( std::ostream& os, const ConfigFile& cf )
{
	// Save a ConfigFile to os
	for( ConfigFile::mapci p = cf.myContents.begin();
	     p != cf.myContents.end();
		 ++p )
	{
		os << p->first << " " << cf.myDelimiter << " ";
		os << p->second << std::endl;
	}
	return os;
}
void ConfigFile::calculateFormulas(){

	vector< pair < string , string > > configVector;
	string script;
	
        for (int i=0; i<(int)myContentsVec.size(); i++) {
		if( myContentsVec[i].second.at(0) == '$' ){
			script = myContentsVec[i].second;
			//cout<<"prima: "<<script<<endl;
			for (int j=0; j<(int)myContentsVec.size(); j++) {
			
				string dollarKey = "$"+myContentsVec[j].first;
				while((int)script.find(dollarKey) != -1){
	   				script.replace(script.find(myContentsVec[j].first)-1, myContentsVec[j].first.size()+1, myContentsVec[j].second);
					
	   			}
			}
			//cout<<"dopo: "<<script<<endl;
			if (script.at(0) == '$' && script.at(1) == '(') {
				script = script.substr(2,script.rfind(")")-2);
			}/* else if( script.at(0) == '$' ) {
				script = script.substr(1);
			}*/
			FILE *in;
			char buff[512];
			in = popen(script.c_str(), "r");
			string result =""; 
			if(fgets(buff, sizeof(buff), in)!=NULL) {
				string tempString(buff);
				
				tempString=tempString.substr(0, tempString.find("\n"));
				//cout<<"valore: *"<<buff<<"*"<<endl;
				//cout<<"stringa: *"<<tempString<<"*"<<endl;
				myContents[myContentsVec[i].first] = tempString;
				myContentsVec[i].second = tempString;
			}
			
		}
        }

}
void ConfigFile::showValues(){
	map< string,string>::iterator iter;
	for (iter = myContents.begin(); iter != myContents.end(); ++iter) {
			cout<<iter->first<<" "<<iter->second<<endl;
        }
}


std::istream& operator>>( std::istream& is, ConfigFile& cf )
{
	// Load a ConfigFile from is
	// Read in keys and values, keeping internal whitespace
	typedef string::size_type pos;
	const string& delim  = cf.myDelimiter;  // separator
	const string& comm   = cf.myComment;    // comment
	const string& sentry = cf.mySentry;     // end of file sentry
	const pos skip = delim.length();        // length of separator
	
	string nextline = "";  // might need to read ahead to see where value ends
	
	int counter = 0;
	while( is || nextline.length() > 0 )
	{
		// Read an entire line at a time
		string line;
		if( nextline.length() > 0 )
		{
			line = nextline;  // we read ahead; use it now
			nextline = "";
		}
		else
		{
			std::getline( is, line );
		}
		
		// Ignore comments
		line = line.substr( 0, line.find(comm) );
		
		// Check for end of file sentry
		if( sentry != "" && line.find(sentry) != string::npos ) return is;
		
		// Parse the line if it contains a delimiter
		pos delimPos = line.find( delim );
		if( delimPos < string::npos )
		{
			// Extract the key
			string key = line.substr( 0, delimPos );
			line.replace( 0, delimPos+skip, "" );
			
			// See if value continues on the next line
			// Stop at blank line, next line with a key, end of stream,
			// or end of file sentry
			bool terminate = false;
			while( !terminate && is )
			{
				std::getline( is, nextline );
				terminate = true;
				
				string nlcopy = nextline;
				ConfigFile::trim(nlcopy);
				if( nlcopy == "" ) continue;
				
				nextline = nextline.substr( 0, nextline.find(comm) );
				if( nextline.find(delim) != string::npos )
					continue;
				if( sentry != "" && nextline.find(sentry) != string::npos )
					continue;
				
				nlcopy = nextline;
				ConfigFile::trim(nlcopy);
				if( nlcopy != "" ) line += "\n";
				line += nextline;
				terminate = false;
			}
			
			// Store key and value
			ConfigFile::trim(key);
			ConfigFile::trim(line);
			cf.myContents[key] = line;  // overwrites if key is repeated
			pair<string,string> couple(key, line);
			cf.myContentsVec.push_back(couple);
			counter++;
		}
	}
	
	return is;
}

string ConfigFile::setValue( const string& key, string value){
	
	std::fstream cfg(FILENAME.c_str() );
	string delimeter  = getDelimiter();
	

	std::vector<string> lineByline;
	string line;
	while( std::getline( cfg, line ))
	{
		
		int delimPos = line.find( delimeter );
		
		if( line.find( delimeter ) < string::npos ){
			string temp = line.substr( 0, delimPos );
			ConfigFile::trim(temp);
			if (temp==key){
				string preLine = line.substr( 0, delimPos + 1);
				preLine += " ";
				preLine += value;
				int spaceNum = (int)line.find("#")-(int)preLine.length();
				if (spaceNum>0){
					for (int i =0;i<spaceNum;i++){
						preLine+=" ";
					}
				}
				if(line.find("#")< string::npos){
					preLine += line.substr(line.find("#"));
				}
				line = preLine;
				
			}
		}
		lineByline.push_back(line);
	}	
	cfg.close();

	std::ofstream myFile;
	myFile.open(FILENAME.c_str());

	for (int looper = 0; looper < (int) lineByline.size(); looper++) {
		myFile << lineByline[looper]<< "\n";
	}
	myFile.close();
	return "done";

}
/*
string ConfigFile::getLineByKey( const string& key){

	std::fstream cfg(FILENAME.c_str() );
	string delimeter  = getDelimiter();
	

	std::vector<string> lineByline;
	string line;
	
	while( std::getline( cfg, line ))
	{

		int delimPos = line.find( delimeter );
		if( delimPos > 0 ){
			string temp = line.substr( 0, delimPos );
			ConfigFile::trim(temp);
			if (temp==key){
				int commentPos = (int)line.find("#");
				if (commentPos > 0 && commentPos> delimPos) return line.substr( delimPos+1, commentPos-delimPos-1);
				else return line.substr( delimPos+1);
			}
		}
		lineByline.push_back(line);
	}	
	cfg.close();
	return "0";

}*/


