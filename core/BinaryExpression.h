#ifndef BINARYEXPRESSION_H_INCLUDED
#define BINARYEXPRESSION_H_INCLUDED

#include "Expression.h"

namespace core{

	template <class T>
	class BinaryExpression{

		public :

			virtual T evaluate(Expression<T>*,Expression<T>*) = 0;

	};

}

#endif // BINARYEXPRESSION_H_INCLUDED
