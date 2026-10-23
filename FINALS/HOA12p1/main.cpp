#include <iostream>
#include <algorithm>

int memo[100];
int getMinSteps(int n)
{

    if ( n == 1 ) return 0; // base case
    if( memo[n] != -1 ) return memo[n]; // we have solved it already :)

    int r = 1 + getMinSteps( n - 1 ); // '-1' step . 'r' will contain the optimal answer finally
    if( n%2 == 0 ) r = std::min( r , 1 + getMinSteps( n / 2 ) ) ; // '/2' step
    if( n%3 == 0 ) r = std::min( r , 1 + getMinSteps( n / 3 ) ) ; // '/3' step

    memo[n] = r ; // save the result. If you forget this step, then its same as plain recursion.
    return r;
}

int main(){
    int tests[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
    std::fill(memo, memo + 100, -1); 
    std::cout<<"Steps Taken: "<<std::endl;
    for (int n : tests) {
        std::cout << n << "\t" << getMinSteps(n) <<std::endl;
    }

    return 0;
}