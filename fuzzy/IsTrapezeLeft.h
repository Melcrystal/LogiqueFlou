#ifndef ISTRAPEZELEFT_H_INCLUDED
#define ISTRAPEZELEFT_H_INCLUDED

#include "../core/Expression.h"
#include "operators.h"

namespace fuzzy{

	template <class T>
    class IsTrapezeLeft : public Is<T>{

		public:
            IsTrapezeLeft(const T& , const T& , const T&);
            ~IsTrapezeLeft();

            T evaluate(core::Expression<T>*);

            T getMin();
            T getMax();
			T getMid();

            void setMin(T&);
            void setMax(T&);
			void setMid(T&);

		private :
			T min, max, mid;
    };

        template <class T>
        IsTrapezeLeft<T>::IsTrapezeLeft(const T& min_, const T& mid_, const T& max_):
        	min(min_),max(max_),mid(mid_){
        }

		template <class T>
		IsTrapezeLeft<T>::~IsTrapezeLeft(){
		}

        template <class T>
        T IsTrapezeLeft<T>::evaluate(core::Expression<T>* e){
			T ev = e->evaluate();

            if (ev <= min) return 0;
            return (ev >= mid)? 1: (ev-max)/(mid-max);
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
		T IsTrapezeLeft<T>::getMid(){
			return mid;
		}

		template <class T>
		void IsTrapezeLeft<T>::setMin(T& _min){
			min = _min;
		}

		template <class T>
		void IsTrapezeLeft<T>::setMax(T& _max){
			max = _max;
		}

		template <class T>
		void IsTrapezeLeft<T>::setMid(T& _mid){
			mid = _mid;
		}

}

#endif // ISTRAPEZELEFT_H_INCLUDED
