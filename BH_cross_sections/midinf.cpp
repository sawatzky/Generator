#include <complex>
#include "nr.h"
using namespace std;

namespace {
	DP func(DP funk(const DP), const DP x)
	{
		return funk(1.0/x)/(x*x);
	}
}

DP NR::midinf(DP funk(const DP), const DP aa, const DP bb, const int n)
{
	DP x,tnm,sum,del,ddel,b,a;
	static DP s;
	int it,j;

	b=1.0/aa;
	a=1.0/bb;
	if (n == 1) {
		return (s=(b-a)*func(funk,0.5*(a+b)));
	} else {
		for(it=1,j=1;j<n-1;j++) it *= 3;
		tnm=it;
		del=(b-a)/(3.0*tnm);
		ddel=del+del;
		x=a+0.5*del;
		sum=0.0;
		for (j=0;j<it;j++) {
			sum += func(funk,x);
			x += ddel;
			sum += func(funk,x);
			x += del;
		}
		return (s=(s+(b-a)*sum/tnm)/3.0);
	}
}
