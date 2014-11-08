#include "DataStruct.h"
#include "fOpera.h"

void LRowElimi(fraction *row1, fraction *row2, int r1, int r2, fraction *b, int column)
{
    int i;
    fraction k=fdivis(row2[r1], row1[r1]);
    for(i=0; i<column; i++)
        row2[i]= fminus(row2[i], fmulti(row1[i], k) );
    b[r2]=  fminus(b[r2], fmulti(b[r1], k));
}

void RRowElimi(fraction *row1, fraction *row2, int r1, int r2, fraction *b)
{
    fraction k=fdivis(row2[r1], row1[r1]);
    row2[r1].n=0,row2[r1].d=0;
    b[r2]= fminus(b[r2], fmulti(b[r1], k));
}
