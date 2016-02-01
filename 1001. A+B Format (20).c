#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,sum,d,e,f;
	scanf("%d%d",&a,&b);
	sum=a+b;
	d=sum/1000000;
	e=(sum-1000000*d)/1000;
	f=sum-1000000*d-1000*e;
	if(d!=0) printf("%d,%03d,%03d",d,abs(e),abs(f));
	else if(d==0&&e!=0) printf("%d,%03d",e,abs(f));
	else printf("%d",f);
	return 0;
}
