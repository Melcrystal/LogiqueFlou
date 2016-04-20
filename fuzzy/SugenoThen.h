#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "operators.h"

using namespace core;

namespace fuzzy
{
	template<class T>
	class SugenoThen :public Then<T>
	{
		public:
			SugenoThen();
			~SugenoThen();

			T evaluate(Expression<T>*, Expression<T>*) const;
			T premiseValue() const;

		private:
			T premiseValu;
	};


	template <class T>
	SugenoThen<T>::SugenoThen() :
		premiseValu(0)
	{}

	template <class T>
	SugenoThen<T>::~SugenoThen()
	{}



	template <class T>
	T SugenoThen<T>::premiseValue() const
	{
		return this->premiseValu;
	}

	template <class T>
	T SugenoThen<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		T left = l->evaluate();
		T right = r->evaluate();
		this->premiseValu = left * right;

		return this->premiseValu;
	}

}

#endif
