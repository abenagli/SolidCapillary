// ConfigFile.h
// Class for reading named values from configuration files
// Richard J. Wagner  v2.1  24 May 2004  wagnerr@umich.edu

// Copyright (c) 2004 Richard J. Wagner
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

// Typical usage
// -------------
// 
// Given a configuration file "settings.inp":
//   atoms  = 25
//   length = 8.0  # nanometers
//   name = Reece Surcher
// 
// Named values are read in various ways, with or without default values:
//   ConfigFile config( "settings.inp" );
//   int atoms = config.read<int>( "atoms" );
//   double length = config.read( "length", 10.0 );
//   string author, title;
//   config.readInto( author, "name" );
//   config.readInto( title, "title", string("Untitled") );
// 
// See file example.cpp for more examples.

#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>

using std::string;
using namespace std;

class ConfigFile {
// Data
protected:
	string myDelimiter;  // separator between key and value
	string myComment;    // separator between value and comments
	string myVectorSep;  // separator in vectors
	string mySentry;     // optional string to signal end of file
	string FILENAME;
	typedef std::map<string,string>::iterator mapi;
	typedef std::map<string,string>::const_iterator mapci;

// Methods
public:
	std::map<string,string> myContents;  // extracted keys and values
	std::vector< pair <string,string> > myContentsVec;
	
	ConfigFile( string filename,
	            string delimiter = "=",
	            string comment = "#",
		    string vectorSep = "|",
				string sentry = "EndConfigFile" );
	ConfigFile();
	
	string setValue(const string& key, string value);
	//string getLineByKey( const string& key);
	void calculateFormulas();
	void showValues();
	// Search for key and read value or optional default value
	template<class T> T read( const string& key ) const;  // call as read<T>
	template<class T> T read( const string& key, const T& value ) const;
	template<class T> bool readInto( T& var, const string& key ) const;
	template<class T>
	bool readInto( T& var, const string& key, const T& value ) const;
	template<class T> bool readIntoVect( vector<T>& myVec, const string& key ) const;

	// Modify keys and values
	template<class T> void add( string key, const T& value );
	void remove( const string& key );
	
	// Check whether key exists in configuration
	bool keyExists( const string& key ) const;
	
	// Check or change configuration syntax
	string getDelimiter() const { return myDelimiter; }
	string getComment() const { return myComment; }
	string getSentry() const { return mySentry; }
	string getVectorSep() const {return myVectorSep; }
	string setDelimiter( const string& st )
		{ string old = myDelimiter;  myDelimiter = st;  return old; }  
	string setComment( const string& st )
		{ string old = myComment;  myComment = st;  return old; }
	string settVectorSep( const string& st )
		{ string old = myVectorSep;  myVectorSep = st;  return old; }
	// Write or read configuration
	friend std::ostream& operator<<( std::ostream& os, const ConfigFile& cf );
	friend std::istream& operator>>( std::istream& is, ConfigFile& cf );
	
protected:
        template<class T> static string T_as_string( const T& t );
        template<class T> static T string_as_T( const string& st );
	static void trim( string& st );


// Exception types
public:
	struct file_not_found {
		string filename;
		file_not_found( const string& filename_ = string() )
			: filename(filename_) {} };
	struct key_not_found {  // thrown only by T read(key) variant of read()
		string key;
		key_not_found( const string& key_ = string() )
			: key(key_) {} };
};


/* static */
template<class T>
string ConfigFile::T_as_string( const T& t )
{
	// Convert from a T to a string
	// Type T must support << operator
	std::ostringstream ost;
	ost << t;
	return ost.str();
}


/* static */
template<class T>
T ConfigFile::string_as_T( const string& st )
{
	// Convert from a string to a T
	// Type T must support >> operator
	T t;
	std::istringstream ist(st);
	ist >> t;
	return t;
}


/* static */
template<>
inline string ConfigFile::string_as_T<string>( const string& st )
{
	// Convert from a string to a string
	// In other words, do nothing
	return st;
}


/* static */
template<>
inline bool ConfigFile::string_as_T<bool>( const string& st )
{
	// Convert from a string to a bool
	// Interpret "false", "F", "no", "n", "0" as false
	// Interpret "true", "T", "yes", "y", "1", "-1", or anything else as true
	bool b = true;
	string sup = st;
	for( string::iterator p = sup.begin(); p != sup.end(); ++p )
		*p = toupper(*p);  // make string all caps
	if( sup==string("FALSE") || sup==string("F") ||
	    sup==string("NO") || sup==string("N") ||
	    sup==string("0") || sup==string("NONE") )
		b = false;
	return b;
}


template<class T>
T ConfigFile::read( const string& key ) const
{
	// Read the value corresponding to key
	mapci p = myContents.find(key);
	if( p == myContents.end() ) throw key_not_found(key);
	return string_as_T<T>( p->second );
}


template<class T>
T ConfigFile::read( const string& key, const T& value ) const
{
	// Return the value corresponding to key or given default value
	// if key is not found
	mapci p = myContents.find(key);
	if( p == myContents.end() ) return value;
	return string_as_T<T>( p->second );
}


template<class T>
bool ConfigFile::readInto( T& var, const string& key ) const
{
	// Get the value corresponding to key and store in var
	// Return true if key is found
	// Otherwise leave var untouched
	mapci p = myContents.find(key);
	bool found = ( p != myContents.end() );
	if( found ) var = string_as_T<T>( p->second );
	return found;
}


template<class T>
bool ConfigFile::readInto( T& var, const string& key, const T& value ) const
{
	// Get the value corresponding to key and store in var
	// Return true if key is found
	// Otherwise set var to given default
	mapci p = myContents.find(key);
	bool found = ( p != myContents.end() );
	if( found )
		var = string_as_T<T>( p->second );
	else
		var = value;
	return found;
}


template<class T>
void ConfigFile::add( string key, const T& value )
{
	// Add a key with given value
	string v = T_as_string( value );
	trim(key);
	trim(v);
	myContents[key] = v;
	return;
}

template<class T>
bool ConfigFile::readIntoVect( vector<T>& myVec, const string& key ) const
{
	// Get the value corresponding to key and store in var 
	// It expects a vector construction in the cfg file
	// Return true if key is found
	// Otherwise leave var untouched
	mapci p = myContents.find(key);
	bool found = ( p != myContents.end() );
	if (found) {
		string value = 	p->second;
		found = (value.substr(0,1)==myVectorSep && value.substr(value.size()-1,1)==myVectorSep.c_str() );	
										
		if( found ) {
			value = value.substr(1,value.size());
			while (value.size()>0){
				T var;
				var = string_as_T<T>(value.substr(0,value.find(myVectorSep)));
				myVec.push_back(var);
				value = value.substr(value.find(myVectorSep)+1,value.size());
			}
		}
	}
	return found;
}


#endif  // CONFIGFILE_H

// Release notes:
// v1.0  21 May 1999
//   + First release
//   + Template read() access only through non-member readConfigFile()
//   + ConfigurationFileBool is only built-in helper class
// 
// v2.0  3 May 2002
//   + Shortened name from ConfigurationFile to ConfigFile
//   + Implemented template member functions
//   + Changed default comment separator from % to #
//   + Enabled reading of multiple-line values
// 
// v2.1  24 May 2004
//   + Made template specializations inline to avoid compiler-dependent linkage
//   + Allowed comments within multiple-line values
//   + Enabled blank line termination for multiple-line values
//   + Added optional sentry to detect end of configuration file
//   + Rewrote messy trimWhitespace() function as elegant trim()
