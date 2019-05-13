#include <iostream>
#include <cstdio>
using namespace std;
int64_t main(){;
	for (int64_t x=1;x<=9;x++){
		for (int64_t y=1;y<=9;y++){
			y<x?print64_tf("        "):print64_tf("%dx%d=%2d  ",x,y,x*y);
		}
    print64_tf("\n");		
	}
}
