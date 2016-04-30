#ifndef EVALUATION_H_INCLUDED
#define EVALUATION_H_INCLUDED

#include <vector>
#include "../core/ValueModel.h"
#include "../core/Expression.h"

namespace core{
	template <class T>
	class Evaluation{
	public:
		typedef std::pair<std::vector<T>, std::vector<T>> Shape;

		static Shape ShapeConst(const T&, const T&, const T&, ValueModel<T>*, Expression<T>*);
	};

	template <class T>
	typename Evaluation<T>::Shape Evaluation<T>::ShapeConst(const T& min, const T& max, const T& step, ValueModel<T>* vm, Expression<T>* exp){
		std::vector<T> x, y;

		for (T i = min; i < max; i += step)
		{
			vm->setValue(i);
			x.push_back(i);
			y.push_back(exp->evaluate());
		}

		return Shape(x, y);

	}
}

#endif