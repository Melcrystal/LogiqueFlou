#ifndef FACTORYEXPRESSION_H_INCLUDED
#define FACTORYEXPRESSION_H_INCLUDED

#include "Expression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include <set>

namespace core{

	template <class T>
	class FactoryExpression{

		public:

			Expression<T>* hold(Expression<T>*); 
            Expression<T>* newUnaryExpression(UnaryExpression<T>*, Expression<T>*);
            Expression<T>* newBinaryExpression(BinaryExpression<T>*, Expression<T>*, Expression<T>*);


		private:
			std::set<Expression<T>*> memory;

	};

	template <class T>
	Expression<T>* FactoryExpression<T>::hold(Expression<T>* exp){
		memory.insert(exp);
		return exp;
	}

	template <class T>
	Expression<T>* FactoryExpression<T>::newUnaryExpression(UnaryExpression<T>*ope, Expression<T>*o){
		return hold(new UnaryExpressionModel<T>(ope,o));
	}

	template <class T>
	Expression<T>* FactoryExpression<T>::newBinaryExpression(BinaryExpression<T>* ope, Expression<T>*l, Expression<T>*r){
		return hold(new BinaryExpressionModel<T>(ope,l,r));
	}


}

#endif // FACTORYEXPRESSION_H_INCLUDED
