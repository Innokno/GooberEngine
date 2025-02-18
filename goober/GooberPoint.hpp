// Defines a point in a 2D space

struct GooberPoint {	
	private:
		float m_xCoordinate;
		float m_yCoordinate;

	public:
		GooberPoint(float, float);	
		
		float GetXCoordinate();
		float GetYCoordinate();
};
