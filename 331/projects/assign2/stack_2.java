public class stack_2 extends single_linked_list
{
	private class node
	{
		public node link;
		public int contents;
		
		public node()
		{
			link = null;
			contents = 0;
		}
		
		public node(int data,node n)
		{
			link = n;
			contents = data;
		}
	}
	public stack_2(){}

	
	public void push(int value)
	{
		insert_at_head(value);
	}
	
	public int pop()
	{
		return remove_at_head();
	}
	
	public int empty()
	{
		return empty();
	}
	
	public node first;
	public int total;

}

