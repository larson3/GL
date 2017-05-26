//John Larson
//CMSC 331, Assign02
public class single_linked_list
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
	
	public node head;
	public node tail;
	public int size;
	
	public single_linked_list()
	{
		head = null;
		tail = null;
		size = 0;
	}
	
	public void insert_at_head(int data)
	{
		node current = head;
		head = new node();
		head.contents = data;
		head.link = current;
		size++;
	}
	public void insert_at_tail(int data)
	{
		node current = tail;
		tail = new node();
		tail.contents = data;
		current.link = tail;
		size++;
	}
	public int remove_at_head()
	{	int contents = head.contents;
		head = head.link;
		size--;
		return contents;
	}
	
	public int empty()
	{
		if(head==null)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}