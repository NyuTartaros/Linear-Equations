#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include "DataStruct.h"
#include "elimi.h"

using namespace std;

int row, column;
//fraction **A;
fraction *b;

int i, j, k;

int main()
{
//IO Initialization
    #define FILEIO
    #ifdef FILEIO
    freopen("Ax=b.in", "r", stdin);
    freopen("Ax=b.out", "w", stdout);
    #endif // FILEIO

    #ifndef FILEIO
    cout<<"Input the Rows & Columns:"<<endl;
    cin>>row>>column;
    #endif // stdIO
    #ifdef FILEIO
    cin>>row>>column;
    #endif // FILEIO

//Data Structure Initialization

    /* WHERE IS IT WRONG!? */
    /* WHERE IS IT WRONG!? */
    //A = new fraction[row][column];  /* WHERE IS IT WRONG!? */
    /* WHERE IS IT WRONG!? */
    /* WHERE IS IT WRONG!? */
    //A = new fraction[10][10];
    fraction A[10][10];
    fraction b[10];              //vector X is needless
//INPUT the MATRIX
    #ifndef FILEIO
    cout<<"Input A:"<<endl;
    #endif // stdIO
    for(i=0; i<row; i++)
        for(j=0; j<column; j++)
            cin>>A[i][j].n;
    #ifndef FILEIO
    cout<<"Input b:"<<endl;
    #endif // stdIO
    for(i=0; i<row; i++)
        cin>>b[i].n;
//Elimination
    for(i=0; i<= row-2; i++)
        for(j=i+1; j<=row-1; j++)
            LRowElimi(A[i], A[j], i, j, b, column-1);    //suppose row equals column
    for(i=row-1; i<= 1; i--)
        for(j=i-1; j<=0; j--)
            RRowElimi(A[i], A[j], i, j, b);    //suppose row equals column
    cout<<"b: ";
    for(i=0; i<=column-1; i++)
    {
        #ifdef FILEIO
        if(b[i].d==0)
            cout<< b[i].n<<' ';
        else
            cout<< b[i].n<<'/'<<b[i].d<<' ';
        #endif // FILEIO
        #ifndef FILEIO
        if(b[i].d==0)
            cout<< b[i].n<<' ';
        else
            cout<< b[i].n<<'/'<<b[i].d<<' ';
        #endif // stdIO
    }

    return 0;
}
