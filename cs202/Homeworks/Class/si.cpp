class Beverage {
	public:
		Beverage();
		Beverage(double x);
		double GetPercentAlc() const;
	private:
		double percentAlc;
};
	
Beverage::Beverage(){
	percentAlcohol=0;
}

double Beverage::GetPercentAlc() const {
	return percentAlcohol;
}

Beverage::Beverge(double x) {
	if (x>=0)
		percentAlcohol = x;
	else
		percentAlcohol = 0;
}

const Beverage operator+(const Beverage &newDrink) const {
	Beverage Wine(newDrink.GetPercentAlc + percentAlc);
	return Wine;
}

const Beverage operator+( const int x) const {
	Beverage y(x + percentAlc);
	return y;
}