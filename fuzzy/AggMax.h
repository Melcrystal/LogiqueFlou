#ifndef AGGMAX_H_INCLUDED
#define AGGMAX_H_INCLUDED

#include "../core/Expression.h"
#include "../core/BinaryExpression.h"
#include "operators.h"

namespace fuzzy{
	template <class T>
	class AggMax : public fuzzy::Agg<T>{

		public :
			AggMax();
			~AggMax();

			T evaluate(core::Expression<T>*, core::Expression<T>*);

	};

	template <class T>
	AggMax<T>::AggMax(){
	}

	template <class T>
	AggMax<T>::~AggMax(){
	}

    template <class T>
    T AggMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right){
		T l = left->evaluate();
		T r = right->evaluate();
        return (l > r)? l: r;
    }

}

#endif // AGGMAX_H_INCLUDED
