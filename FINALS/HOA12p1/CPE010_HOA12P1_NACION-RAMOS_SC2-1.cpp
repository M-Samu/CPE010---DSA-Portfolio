#include <iostream>
#include <algorithm>
#include <vector>

int getMinSteps ( int n )
{
std::vector<int> dp(n + 1, 0);
dp[1] = 0;

for ( int i = 2; i <= n; i++ )
{
dp[i] = 1 + dp[i-1];
if ( i%2 == 0 ) dp[i] = std::min( dp[i], 1 + dp[i/2] );
if ( i%3 == 0 ) dp[i] = std::min( dp[i], 1 + dp[i/3] );
}
return dp[n];
}

int main(){
int tests[] = {1, 4, 7, 10};

for (int n : tests) {

std::cout << "n = " << n << " -> "<< " Steps = " << getMinSteps(n) << std::endl;
}

}