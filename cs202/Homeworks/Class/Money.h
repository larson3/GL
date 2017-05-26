

class Money
{
	public:
	
		Money();
			
		Money(int dollars);
		
		Money(int dollars,int cents);
		
		
		void SetDollars(int dollars);
		
		void SetCents(int cents);
		
		void SetBoth(int dollars, int cents);
		
		int GetDollars();
		
		int GetCents();
		
	


	
	private:
		int m_cents;
		bool m_flag;
		int m_dollars;
		
};
		