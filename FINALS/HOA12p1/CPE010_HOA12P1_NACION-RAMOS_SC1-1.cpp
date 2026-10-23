#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> memo;

int getMinSteps ( int n )
{
if ( n == 1 ) return 0;
if( memo[n] != -1 ) return memo[n];
int r = 1 + getMinSteps( n - 1 );
if( n%2 == 0 ) r = std::min( r , 1 + getMinSteps( n / 2 ) ) ;
if( n%3 == 0 ) r = std::min( r , 1 + getMinSteps( n / 3 ) ) ;
memo[n] = r ;
return r;
}

int main(){
int tests[] = {1, 4, 7, 10};

for (int n : tests) {
memo.assign(n + 1, -1);
std::cout << "n = " << n << " -> "<< " Steps = " << getMinSteps(n) << std::endl;
}


}