#ifndef UNARYEXPRESSIONMODEL_H_INCLUDED
#define UNARYEXPRESSIONMODEL_H_INCLUDED

#include "UnaryExpression.h"

namespace core{

	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {

		public :
			UnaryExpressionModel();
			virtual ~UnaryExpressionModel();

			virtual T evaluate();
			virtual T evaluate(Expression<T>*);

            virtual UnaryExpression<T>* getOperator() const;
            virtual Expression<T>* getOperand() const;

            virtual void setOperator(const UnaryExpression<T>*);
            virtual void setOperand(const Expression<T>*);

		private :
			UnaryExpression<T> *op;
			Expression<T> *operand;

	};


	template <class T>
	UnaryExpressionModel<T>::~UnaryExpressionModel(){
	}

	template <class T>
	T UnaryExpressionModel<T>::evaluate(){
		if (operand != NULL)
			return evaluate(operand);
	}

	template <class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T>* o){
		if (op != NULL)
			return op->evaluate(o);
	}

	template <class T>
	UnaryExpression<T>* UnaryExpressionModel<T>::getOperator() const{
		return op;
	}

	template <class T>
	Expression<T>*  UnaryExpressionModel<T>::getOperand() const{
		return operand;
	}

	template <class T>
	 void UnaryExpressionModel<T>::setOperator(const UnaryExpression<T>* _op){
        op = _op;
	}

	template <class T>
	 void UnaryExpressionModel<T>::setOperand(const Expression<T>* _operand){
			operand = _operand;
	}

}
#endif // UNARYEXPRESSIONMODEL_H_INCLUDED
