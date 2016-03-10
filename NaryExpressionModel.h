#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H

#include"NaryExpression.h"
#include"Expression.h"

http://fr.nametests.com/test/result/guilhem-/10716862130/namespace core
{
    template <class T>
	class NaryExpressionModel :public Expression<T>, public NaryExpression<T>
	{
    public :
        NaryExpressionModel(NaryExpression<T>, std::vector<Expression<T>>);
        virtual ~NaryExpressionModel(){};

        T evaluate() const;
        T evaluate(vector<const Expression<T>*>*) const;
	}
}
