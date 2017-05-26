public class queue_2 extends single_linked_list
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
	public queue_2(){}
	
	public void enqueue(int data)
	{
		insert_at_tail(data);
	}
	
	public int dequeue()
	{
		return remove_at_head();
	}
	
	public int empty()
	{
		return empty();
	}
	
	public int total;
	public node first;
	public node last;

}