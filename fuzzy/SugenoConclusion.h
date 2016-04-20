#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "../core/NaryExpression.h"
#include <vector>

using namespace core;

namespace fuzzy {

	template <class T>
	class SugenoConclusion : public NaryExpression<T>
	{
		public:
			SugenoConclusion(const std::vector<T> );
			~SugenoConclusion();

			T evaluate(std::vector<Expression<T> >) const;

		private:
			std::vector<T> coef;
	};


	template<class T>
	SugenoConclusion <T>::SugenoConclusion(const std::vector<T> _coef) :
		coef(_coef)
	{}

	template<class T>
	SugenoConclusion <T>::~SugenoConclusion()
	{
		delete[] coef;
	}

	template <class T>
	T SugenoConclusion<T>::evaluate(std::vector<Expression<T> > vec) const
	{
		T sum;
		typename std::vector<T>::const_iterator it = vec.begin();
		for (; it != vec.end(); ++it)
			coef.push_back(vec[it]);

		it = coef.begin();
		for (; it != coef.end(); ++it)
			sum += coef[it];

		return sum;

	}
}

#endif
