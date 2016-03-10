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



}
