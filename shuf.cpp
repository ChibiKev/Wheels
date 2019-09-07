#include <cstdio>   // printf
#include <cstdlib>  // rand
#include <time.h>   // time
#include <getopt.h> // to parse long arguments.
#include <stdlib.h>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
#include <algorithm>
using std::swap;
using std::min;
using namespace std;

void shuffling(vector <string>&x);
void shuffling2(vector <int>&x);
void shuffle();

void shuffling(vector <string> &x){
	for (size_t i=x.size()-1; i > 0; i--)
	{
		int k= rand() % (i+1);
		string temp= x[i];
		x[i]=x[k];
		x[k]=temp;
	}
}

void shuffling2(vector <int> &x){
	for (size_t i=x.size()-1; i > 0; i--)
	{
		int k= rand() % (i+1);
		int temp= x[i];
		x[i]=x[k];
		x[k]=temp;
	}
}

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of shuf.  Supported options:\n\n"
"   -e,--echo              treat each argument as an input line.\n"
"   -i,--input-range=LO-HI treat each number in [LO..HI] as an input line.\n"
"   -n,--head-count=N      output at most N lines.\n"
"   --help                 show this message and exit.\n";

int main(int argc, char *argv[]) {
	// define long options
	static int echo=0, rlow=0, rhigh=0;
	static size_t count=-1;
	bool userange = false;
	static struct option long_opts[] = {
		{"echo",        no_argument,       0, 'e'},
		{"input-range", required_argument, 0, 'i'},
		{"head-count",  required_argument, 0, 'n'},
		{"help",        no_argument,       0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "ei:n:h", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'e':
				echo = 1;
				break;
			case 'i':
				if (sscanf(optarg,"%i-%i",&rlow,&rhigh) != 2) {
					fprintf(stderr, "Format for --input-range is N-M\n");
					rlow=0; rhigh=-1;
				} else {
					userange = true;
				}
				break;
			case 'n':
				count = atol(optarg);
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}
	/* NOTE: the system's shuf does not read stdin *and* use -i or -e.
	 * Even -i and -e are mutally exclusive... */

	/* TODO: write me... */
	size_t max;
	srand(time(0));

	if (echo== 1 && rhigh != 0){ //for -e and -i used together
	printf(usage,argv[0]);
	return 1;
}

	if (echo){ //-e
	string n;
	vector <string> x;
	while(cin >> n){
		x.push_back(n);
	}
		shuffling(x);
		if(count == (size_t) -1){
			max = x.size()-1;
		}
		else{
			max = count-1;
		}
		for(size_t i = 0; i <= max; i++)
			cout << x[i] << endl;
		}

	else if (userange){ //-i and/or -n
	vector<int> x;
	for(size_t i = rlow; i <= (size_t) rhigh; i++){
		x.push_back(i);
	}
	shuffling2(x);
	if(count == (size_t) -1){
		max = x.size()-1;
	}
	else{
		max = count-1;
	}
	for(size_t i = 0; i <= max; i++){
		cout << x[i] << endl;
	}
}

	else { //for no command at all
	string n;
	vector <string> x;
	while(cin >> n){
		x.push_back(n);
	}
		shuffling(x);
		if(count == (size_t) -1){
			max = x.size()-1;
		}
		else{
			max = count-1;
		}
		for(size_t i = 0; i <= max; i++)
			cout << x[i] << endl;
		}
	return 0;
}
