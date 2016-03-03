#ifndef ISTRAPEZELEFT_H_INCLUDED
#define ISTRAPEZELEFT_H_INCLUDED

#include "../core/Expression.h"
#include "operators.h"

namespace fuzzy{

	template <class T>
    class IsTrapezeLeft : public Is<T>{

		public:
            IsTrapezeLeft(const T& , const T& );
            ~IsTrapezeLeft();

            T evaluate(core::Expression<T>*);

            T getMin();
            T getMax();

            void setMin(T&);
            void setMax(T&);

		private :
			T min, max;
    };

        template <class T>
        IsTrapezeLeft<T>::IsTrapezeLeft(const T& min_, const T& max_):
        	min(min_),max(max_){
        }

		template <class T>
		IsTrapezeLeft<T>::~IsTrapezeLeft(){
		}

        template <class T>
        T IsTrapezeLeft<T>::evaluate(core::Expression<T>* e){
			T ev = e->evaluate();

            if (ev <= min) return 0;
            return (ev >= max)? 1: (ev-min)/(max-min);
        }

		 template <class T>
		T IsTrapezeLeft<T>::getMin(){
			return min;
		}

		 template <class T>
		T IsTrapezeLeft<T>::getMax(){
			return max;
		}

		template <class T>
		void IsTrapezeLeft<T>::setMin(T& _min){
			min = _min;
		}

		template <class T>
		void IsTrapezeLeft<T>::setMax(T& _max){
			max = _max;
		}


}

#endif // ISTRAPEZELEFT_H_INCLUDED
