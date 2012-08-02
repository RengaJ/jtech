#ifndef JTECH_MATRIX_H
#define JTECH_MATRIX_H

namespace jtech
{
	class matrix22
	{
		public:
			matrix22();
			matrix22( float diagonal );
			matrix22( float p11, float p12, float p21, float p22 );
			matrix22( )
			
			float dot(matrix22 &m)
			matrix22 cross(matrix22 &m)
			
		protected:
			
	};
}

#endif // JTECH_MATRIX_H