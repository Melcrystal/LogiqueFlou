#ifndef OPERATORS_H_INCLUDED
#define OPERATORS_H_INCLUDED

#include "../core/BinaryExpression.h"
#include "../core/UnaryExpression.h"
#include "../core/ValueModel.h"
#include "../core/Evalutation.h"

#include <vector>

using namespace core;

namespace fuzzy{

	template <class T>
	class And : public core::BinaryExpression<T>{
	};

	template <class T>
	class Or : public core::BinaryExpression<T>{
	};

	template <class T>
	class Then : public core::BinaryExpression<T>{
	};

	template <class T>
	class Agg : public core::BinaryExpression<T>{
	};

	template <class T>
	class Not : public core::UnaryExpression<T>{
	};

	template <class T>
	class Is : public core::UnaryExpression<T>{
	};

	template <class T>
	class MandaniDefuzz : public core::BinaryExpression<T>{
	public:
		MandaniDefuzz(const T&, const T&, const T&);
		virtual ~MandaniDefuzz(){};

		T evaluate(core::Expression<T>*, core::Expression<T>*) const;
		virtual T defuzz(const typename Evaluation<T>::Shape&) = 0;

	protected:
		T min, max, step, current;
	};

	template<class T>
	MandaniDefuzz<T>::MandaniDefuzz(const T& _min, const T& _max, const T& _step) :
		min(_min), max(_max), step(_step){
	}

	template<class T>
	T MandaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		return defuzz(Evaluation<T>::ShapeConst(min, max, step, (ValueModel<T>*) l, r));
	}


	template <class T>
	class CogDefuzz : public fuzzy::MandaniDefuzz<T>{
	public:
		CogDefuzz(const T&, const T&, const T&);
		virtual ~CogDefuzz(){};

		T defuzz(const typename Evaluation<T>::Shape&);
		T evaluate(core::Expression<T>*, core::Expression<T>*);


	};

	template <class T>
	CogDefuzz<T>::CogDefuzz(const T& _min, const T& _max, const T& _step) :
		MandaniDefuzz<T>(_min, _max, _step){
		}

	template <class T>
	T CogDefuzz<T>::defuzz(const typename Evaluation<T>::Shape& shape){
		T x, y, num = 0, den = 0;
		for (unsigned int i = 0; i < (shape.first.size() - 1); i++)
		{
			x = shape.first.at(i);
			y = shape.second.at(i);
			num += x*y;
			den += y;
		}
		return (num / den);
	}

	template <class T>
	T CogDefuzz<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r){
		return defuzz(Evaluation<T>::ShapeConst(min, max, step, (ValueModel<T>*)l, r));
	}

}

#endif // OPERATORS_H_INCLUDED
