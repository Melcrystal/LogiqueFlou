#ifndef NOTMINUS1_H_INCLUDED
#define NOTMINUS1_H_INCLUDED


#include "../core/Expression.h"
#include "operators.h"

namespace fuzzy{
	template <class T>
	class NotMinus1 : public Not<T>{

		public :
			NotMinus1();
			~NotMinus1();

			T evaluate(core::Expression<T>*);

	};

	template <class T>
	NotMinus1<T>::NotMinus1(){
	}

   	template <class T>
	NotMinus1<T>::~NotMinus1(){
	}

    template <class T>
    T NotMinus1<T>::evaluate(core::Expression<T>* e){
		T ev = e->evaluate();
		return 1-ev;
    }

}

#endif // NOTMINUS1_H_INCLUDED
