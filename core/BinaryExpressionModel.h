#ifndef BINARYEXPRESSIONMODEL_H_INCLUDED
#define BINARYEXPRESSIONMODEL_H_INCLUDED

#include "BinaryExpression.h"

using namespace  core;

template <class T>
class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {

	public :
		BinaryExpressionModel();
		virtual ~BinaryExpressionModel();

		virtual T evaluate();
		virtual T evaluate(Expression<T>*, Expression<T>*);

		virtual BinaryExpression<T>* getOperator() const;
		virtual Expression<T>* getLeft() const;
		virtual Expression<T>* getRight() const;

		virtual void setOperator(BinaryExpression<T>*);
		virtual void setLeft(Expression<T>*);
		virtual void setRight(Expression<T>*);

	private :
		BinaryExpression<T>* operator_;
		Expression<T>* left;
		Expression<T>* right;

};

template <class T>
	BinaryExpressionModel<T>::~BinaryExpressionModel(){
	}


template <class T>
T BinaryExpressionModel<T>::evaluate(){
	if (left != NULL && right != NULL)
		return evaluate(left,right);
}

template <class T>
T BinaryExpressionModel<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r){
	if (operator_ != NULL)
		return operator_->evaluate(l,r);
}

	template <class T>
	 BinaryExpression<T>* BinaryExpressionModel<T>::getOperator() const{
		return operator_;
	}

	template <class T>
	 Expression<T>* BinaryExpressionModel<T>::getLeft() const{
		return left;
	}

	template <class T>
	 Expression<T>* BinaryExpressionModel<T>::getRight() const{
		return right;
	}

	template <class T>
	 void BinaryExpressionModel<T>::setOperator(BinaryExpression<T>* _operator){
		operator_ = _operator;
	}

	template <class T>
	 void BinaryExpressionModel<T>::setLeft(Expression<T>* _left){
		left = _left;
	}

	template <class T>
	 void BinaryExpressionModel<T>::setRight(Expression<T>* _right){
		right = _right;
	}

#endif // BINARYEXPRESSIONMODEL_H_INCLUDED
