#ifndef NARYSHADOWEXPRESSION_H
#define NARYSHADOWEXPRESSION_H

#include "NaryExpression.h"

namespace core
{
	template <class T>
	class NaryShadowExpression :public NaryExpression<T>
	{
		public:
		    NaryShadowExpression(NaryExpression<T>*);
			virtual ~NaryShadowExpression(){};

			T evaluate(std::vector<Expression<T>*>*) const;
			void setTarget(NaryExpression<T> *);
			NaryExpression<T>* getTarget() const;

		private:
			NaryExpression<T>* target;
	};


	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>*_target) :
		target(_target)
	{}


	template <class T>
	void NaryShadowExpression<T>::setTarget(NaryExpression<T>* exp)
	{
		target = exp;
	}

	template <class T>
	NaryExpression<T>* NaryShadowExpression<T>::getTarget() const
	{
		return this->target;
	}

	template<class T>
	T NaryShadowExpression<T>::evaluate(std::vector<Expression<T>*>* operands) const
	{
		if (target != null)
			return target->evaluate(operands);
	}


}
