procedure foo(f:boolean) return integer
{
	var a,b,c: integer;
	var e: boolean;
	var d: boolean;
	if ((!e || a<c) && (a<b && a<c))
	{
		a = 5;
	}
	else
	{a=20;}
	return a;
}
procedure Main() return integer{
	var a,b: integer;
	var ptr: intptr;
	var c: boolean;
	var d: boolean;
	procedure foo1() return integer
	{return 0;}
	if ((!c && a<b) || (a<b && a<b))
	{
		a = a+1;
	}
	else
	{a=foo(d);
	^ptr=a;}
	return 0;
}
