#include "Log.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Lecture.h"

using namespace std;

int main()
{
	/* vector<string> info = {" ", " ", " ", "08/Sep/2012:11:16:02 +0200", "GET /temps/4IF16.html HTTP/1.1", " ", " ", "http://intranet-if.insa-lyon.fr", "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1"};
	Log l;
	l = info;

	cout << endl << l; */

	Lecture<Log> l("ano.log");
	vector<Log> v = l.LectureLog();

	for(Log lo : v)
	{
		cout << lo << endl;
	}
}

/* 192.168.0.0 - - [08/Sep/2012:11:16:02 +0200] "GET /temps/4IF16.html HTTP/1.1" 200 12106 "http://intranet-if.insa-lyon.fr/temps/4IF15.html" "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1" */