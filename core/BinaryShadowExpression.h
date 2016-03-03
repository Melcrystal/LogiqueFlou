#ifndef BINARYSHADOWEXPRESSION_H_INCLUDED
#define BINARYSHADOWEXPRESSION_H_INCLUDED

namespace core{

	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T>{

		public:
			BinaryShadowExpression(BinaryExpression<T>*);
			~BinaryShadowExpression(){};

			T evaluate(Expression<T>*, Expression<T>*);
			void setTarget(BinaryExpression<T>*);

		private:
			BinaryExpression<T>* target;
	};

		template <class T>
		BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* e):
			target(e){
		}

		template <class T>
		T BinaryShadowExpression<T>::evaluate(Expression<T>* l, Expression<T>* r){
			if(target != NULL)
				return target->evaluate(l,r);
		}


}

#endif // BINARYSHADOWEXPRESSION_H_INCLUDED
