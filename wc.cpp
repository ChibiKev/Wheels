/*
 * CSc103 Project 3: unix utilities
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:
 */
#include <map>
#include <string>
using std::string;
#include <set>
using std::set;
#include <getopt.h> // to parse long arguments.
#include <cstdio> // printf
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



#if 0
void countline(n){ //-l
	string n;
	size_t count=0;
	while (getline(cin,n)){
		count++;
	}
	cout << count << endl;
}
#if 0
int importantfunction(vector<string> &words, int n){ //use for countwords and countuniquewords
	vector <string> uniquewords;
	vector <int> break_index;
	sort (words.begin(),words.end());
	for (size_t i=0; i!= words.size()-1;++i){
		if (words[i+1] != words[i]){
			uniquewords.push_back(words[i]);
			break_index.push_back(i);
		}
	}
	uniquewords.push_back(words[words.size()-1]);
	vector <int> wordcount(1,break_index[0]+1);
	for (size_t i=0; i!= break_index.size()-1;++i){
		wordcount.push_back(break_index[i+1] - break_index[i]);
	}
	wordcount.push_back(words.size()-1-break_index[break_index.size()-1]);
	if (n==0){
	return words.size();
	}
	else if (n==1){
	return uniquewords.size();
	}
	return false;
}

void countwords(){ //-w
	vector <string>words;
	string s;
	while (cin >> s){
		words.push_back(s);
	}
	cout << importantfunction(words,0) <<endl;
}


void countuwords(){ //-u
	vector <string> words;
	string s;
	while (cin >> s){
		words.push_back(s);
	}
	cout << importantfunction(words,1) <<endl;
}
#else
void countwords(){ //-w
	string n;
	map<string,int> w;
	while (cin>>n) {
		w[n]++;
	}
	size_t count=0;
	for (map<string,int>::iterator i=w.begin();i!=w.end();i++){
		count=count+(*i).second;
	}
	cout << count <<endl;
}

void countuwords(){ //-u
	string n;
	map<string,int> w;
	while (cin>>n) {
		w[n]++;
	}
	size_t count=0;
	for (map<string,int>::iterator i=w.begin();i!=w.end();i++){
		if ((*i).second>=1){
		count++;
	}
}
	cout << count <<endl;
}

#endif
void maxline(){ //-L
	string n,longest;
	getline(cin,n);
	longest=n;
	int count=1;
	int countline=1;
	while (getline(cin,n)){
		count++;
		if (n.length() > longest.length()) {
			longest=n;
			countline=count;
		}
	}
		cout << countline;
	#if 0 //change to 1 if you want to cout longest word too
	cout << "\t";
		cout << longest;
	#endif
	cout << endl;
}

void justwc(){ //line, word, character
	string n;
	size_t countcharacter=0;
	size_t countline=0;
	size_t countwords=0;
	string longest;

	getline(cin,n); //for one line only
	longest=n;
	size_t countforlines=1;
	size_t countingline=1;
			countline++;
		for (size_t i=0; i < n.length(); i++){
			countcharacter++;
		}
			for (size_t j=0; j < n.length(); j++){
				if (n[j]==' ' && n[j+1]!=' '){
					countwords++;
				}
			}
			if (n[n.length()-1]==' ' || n[n.length()-1]== '\n'){
				countwords--;
			}
	countwords++;

	while (getline(cin,n)){ //for more than one line
		countline++;
		for (size_t i=0; i < n.length(); i++){
			countcharacter++;
		}
			for (size_t j=0; j < n.length(); j++){
				if (n[j]==' ' && n[j+1]!=' '){
					countwords++;
				}
			}
			if (n[n.length()-1]==' ' || n[n.length()-1]== '\n'){
					countwords--;
			}
			countwords++;
			countforlines++;
			if (n.length() > longest.length()) {
			longest=n;
			countingline=countforlines;
		}
		}
	cout << countline << "\t" << countwords << "\t" << countcharacter << "\t" << countingline << "\t" << longest <<endl;
}
#endif
static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of wc.  Supported options:\n\n"
"   -c,--bytes            print byte count.\n"
"   -l,--lines            print line count.\n"
"   -w,--words            print word count.\n"
"   -L,--max-line-length  print length of longest line.\n"
"   -u,--uwords           print unique word count.\n"
"   --help          show this message and exit.\n";

int main(int argc, char *argv[])
{
	// define long options
	static int charonly=0, linesonly=0, wordsonly=0, uwordsonly=0, longonly=0;
	static struct option long_opts[] = {
		{"bytes",           no_argument,   0, 'c'},
		{"lines",           no_argument,   0, 'l'},
		{"words",           no_argument,   0, 'w'},
		{"uwords",          no_argument,   0, 'u'},
		{"max-line-length", no_argument,   0, 'L'},
		{"help",            no_argument,   0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "clwuLh", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'c':
				charonly = 1;
				break;
			case 'l':
				linesonly = 1;
				break;
			case 'w':
				wordsonly = 1;
				break;
			case 'u':
				uwordsonly = 1;
				break;
			case 'L':
				longonly = 1;
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}

	/* TODO: write me... */
	string n;
	size_t countcharacter=0;
	size_t countline=0;
	size_t countwords=0;
	string longest;

	getline(cin,n); //for one line only
	longest=n;
	size_t countforlines=1;
	size_t countingline=1;
			countline++;
		for (size_t i=0; i < n.length(); i++){
			countcharacter++;
		}
			for (size_t j=0; j < n.length(); j++){
				if (n[j]==' ' && n[j+1]!=' '){
					countwords++;
				}
			}
			if (n[n.length()-1]==' ' || n[n.length()-1]== '\n'){
				countwords--;
			}
	countwords++;

	while (getline(cin,n)){ //for more than one line
		countline++;
		for (size_t i=0; i < n.length(); i++){
			countcharacter++;
		}
			for (size_t j=0; j < n.length(); j++){
				if (n[j]==' ' && n[j+1]!=' '){
					countwords++;
				}
			}
			if (n[n.length()-1]==' ' || n[n.length()-1]== '\n'){
					countwords--;
			}
			countwords++;
			countforlines++;
			if (n.length() > longest.length()) {
			longest=n;
			countingline=countforlines;
		}
		}
	if (charonly){
	cout << countcharacter << endl;
	}
	if (linesonly){
	cout << countline << endl;
	}
	if (wordsonly){
	cout << countwords << endl;
	}
	if (uwordsonly){
	cout << "stupid" << endl;
	}
	if (longonly){
	cout << countingline << "\t" << longest << endl;
	}
	if (charonly==0&&linesonly==0&&wordsonly==0&&uwordsonly==0&&longonly==0){
	cout << countline << "\t" << countwords << "\t" << countcharacter << "\t" << countingline << "\t" << longest <<endl;
	}
	return 0;
}