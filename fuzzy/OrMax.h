#ifndef ORMAX_H_INCLUDED
#define ORMAX_H_INCLUDED

namespace fuzzy{
	template <class T>
	class OrMax : public fuzzy::Or<T>{

		public :
			OrMax();
			~OrMax();

			T evaluate(core::Expression<T>*, core::Expression<T>*);

	};

	template <class T>
	OrMax<T>::OrMax(){
	}

    template <class T>
	OrMax<T>::~OrMax(){
	}

    template <class T>
    T OrMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right){
		T l = left->evaluate();
		T r = right->evaluate();
        return (l > r)? l: r;
    }

}

#endif // ORMAX_H_INCLUDED
