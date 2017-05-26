class hanoi
{
    public static void main(String []args)
    {
	String tower(int num, int fromPeg, int toPeg)
	{
	    if(num==0)
	    {
		return fromPeg+"->"+toPeg;
	    }
	    else
	    {
		return tower(num-1,toPeg,fromPeg);
	    }
	}
    }			    

}