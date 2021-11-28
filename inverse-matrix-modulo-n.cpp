#include<iostream>
 
using namespace std;
// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y);
 
// Function to find modulo inverse of a
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1){
        return -1;
    }

        // m is added to handle negative x
        int res = (x % m + m) % m;
        cout << "Modular multiplicative inverse is " << res;
        return res;
    
}
 
// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y)
{
     
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
     
    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
int main(){
int mat[3][3], i, j,K=0;
int determinant = 0;
cout<<"Enter the value of n:\n";
cin>>K;
cout<<"Enter elements of matrix row wise:\n";
for(i = 0; i < 3; i++)
for(j = 0; j < 3; j++)
           cin>>mat[i][j];
printf("\nGiven matrix is:");
for(i = 0; i < 3; i++){
cout<<"\n";
for(j = 0; j < 3; j++)
cout<<mat[i][j]<<"\t";
}
//finding determinant
int multiplicator = modInverse(determinant,K);
for(i = 0; i < 3; i++)
determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
determinant = determinant % K;
cout<<"\n\ndeterminant: "<<determinant;
cout<<"\n\nInverse of matrix is: \n";
for(i = 0; i < 3; i++){
for(j = 0; j < 3; j++){
int ans_i = ((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))%K;
ans_i = ans_i * multiplicator;
ans_i = ans_i < 0 ? ans_i+K: ans_i;
cout<<ans_i%K<<"\t";}
cout<<"\n";
}
 
   return 0;
}


 
