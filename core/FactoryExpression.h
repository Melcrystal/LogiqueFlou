#ifndef FACTORYEXPRESSION_H_INCLUDED
#define FACTORYEXPRESSION_H_INCLUDED

#include "Expression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"

namespace core{

	template <class T>
	class FactoryExpression{

		public:

			Expression<T>* Hold(Expression<T>*); // Attention, HOLD a faire
            UnaryExpression<T>* newUnaryExpression(UnaryExpression<T>*, Expression<T>*);
            BinaryExpression<T>* newBinaryExpression(BinaryExpression<T>*, Expression<T>*, Expression<T>*);


		private:
			Expression<T>* memory;

	};

	template <class T>
	UnaryExpression<T>* FactoryExpression<T>::newUnaryExpression(UnaryExpression<T>*ope, Expression<T>*o){
		return new UnaryExpressionModel<T>(ope,o);
	}

	template <class T>
	BinaryExpression<T>* FactoryExpression<T>::newBinaryExpression(BinaryExpression<T>* ope, Expression<T>*l, Expression<T>*r){
		return new BinaryExpressionModel<T>(ope,l,r);
	}


}

#endif // FACTORYEXPRESSION_H_INCLUDED
