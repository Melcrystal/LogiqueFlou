#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H

#include"NaryExpression.h"
#include"Expression.h"

{
    template <class T>
	class NaryExpressionModel :public Expression<T>, public NaryExpression<T>
	{
    public :
        NaryExpressionModel(NaryExpression<T>, std::vector<Expression<T>>);
        virtual ~NaryExpressionModel(){};

        T evaluate() const;
        T evaluate(vector<const Expression<T>*>*) const;
        private:
			NaryExpression<T> ope;
			std::vector<Expression<T>> operands;
	};

	template <class T>
	NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T> _ope, std::vector<Expression<T>> _operands) :
		ope(_ope), operands(_operands)
	{}

	template <class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if (operands != null)
			return evaluate(operands);
	}

	template <class T>
	T NaryExpressionModel<T>::evaluate(vector<const Expression<T>*>* o)  const
	{
		if (ope != null)
			ope.evaluate(o);
    }
}
