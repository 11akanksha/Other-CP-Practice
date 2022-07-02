#include <bits/stdc++.h> 

int f(int i,int j){
    if(i==0 && j == 0) return 1;
    if(i<0 || j < 0) return 0;
    
    return f(i,j-1) + f(i-1,j);
}

int uniquePaths(int m, int n) {
	return f(m-1,n-1);
}
