template <typename BinOp, typename Op1, typename Op2>
class somefunction_t : 
public std::unary_function<typename Op1::argument_type,
					  typename BinOp::result_type> {
protected:
	BinOp o;
	Op1 o1;
	Op2 o2;
public:
	somefunction_t(BinOp binop, Op1 op1, Op2 op2) : o(binop), o1(op1), o2(op2) {}
		typename BinOp::result_type
		operator() (const typename Op1::argument_type &x) {
			return o(o1(x), o2(x));
		}
};