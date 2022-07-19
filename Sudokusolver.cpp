//sudoku solver
#include <iostream>
#include<cmath>
using namespace std;
bool kyasafeh(int mat[100][100],int i,int j,int number,int n){
	// for rows and cols
	for(int k=0;k<n;k++){
		if(mat[k][j]==number||mat[i][k]==number){
			return false;
		}
	}

	// small box;
	n=sqrt(n); //3
	int starti=(i/n)*n;
	int startj=(j/n)*n;
	for(int i=starti;i<starti+n;i++){ //starti+n==3+3==6
		for(int j=startj;j<startj+n;j++){
			if(mat[i][j]==number){
				return false;
			}
		}

	}
	return true;

}
bool sudokusolver(int mat[100][100],int i,int j,int n)
{
    //base case
    if(i==n)
    {
        for(int k=0;k<n;k++)
        {
            for(int l=0;l<n;l++)
            {
                 cout<<mat[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(j==n)
    {
       return sudokusolver(mat,i+1,0,n);  
    }
    if(mat[i][j]!=0)
    {
        return sudokusolver(mat,i,j+1,n);
    }


    //recursive case
    for(int number=1;number<=n;number++)
    {
        if(kyasafeh(mat,i,j,number,n))
        {
            mat[i][j]=number;
            bool kyaaggebhirakhsakteh=sudokusolver(mat,i,j+1,n);
            if(kyaaggebhirakhsakteh)
            {
                return true;
            }
            mat[i][j]=0;
        }

    }
    return false;
}
int main() {
    int n=9;
    
    int mat[100][100]=

        { 5,3,0,0,7,0,0,0,0, 
          6,0,0,1,9,5,0,0,0, 
          0,9,8,0,0,0,0,6,0, 
          8,0,0,0,6,0,0,0,3, 
          4,0,0,8,0,3,0,0,1, 
          7,0,0,0,2,0,0,0,6, 
          0,6,0,0,0,0,2,8,0, 
          0,0,0,4,1,9,0,0,5, 
          0,0,0,0,8,0,0,7,9} ;
    
    sudokusolver(mat,0,0,9);
    
}
