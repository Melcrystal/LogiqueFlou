#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "..\core\NaryExpression.h"
#include "..\core\BinaryExpressionModel.h"
#include "..\core\BinaryShadowExpression.h"
#include <vector>

using namespace core;

namespace fuzzy{
    template<class T>
    class SugenoDefuzz :public NaryExpression<T>
	{
	    public:
			SugenoDefuzz();
			virtual ~SugenoDefuzz(){};

			T evaluate(std::vector<const Expression<T>*>*) const;
	};

    template<class T>
	SugenoDefuzz<T>::SugenoDefuzz()
	{}

	template <class T>
	T SugenoDefuzz<T>::evaluate(std::vector<const Expression<T>*>* oper) const
	{
	    typename std::vector<const Expression<T>*>::const_iterator it;
		T num = 0;
		T den = 0;

		// calcul somme des wi voir pdf p : 114
		for (it = oper->begin(); it != oper->end(); it++)
		{
			BinaryExpressionModel<T>*  bem = (BinaryExpressionModel<T>*)(*it);
			BinaryShadowExpression<T>* bse = (BinaryShadowExpression<T>*) bem->getOperator();
			SugenoThen<T>* suth = (SugenoThen<T>*)bse->getTarget();

			num += (*it)->evaluate();
			den += suth->premiseValue();
		}

		if (den != 0)
			return num / den;
		else
			return 0;
	}





}


