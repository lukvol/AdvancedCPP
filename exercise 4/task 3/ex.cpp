// should be in the implementation file despite being a declaration, 
// the variable seems not to be used in multiple places. 
// The name is an indicator that we need this variable only inside of one function.
char ch;

// should be in the implementation file despite being a declaration, 
// the variable seems not to be used in multiple places. 
// The name is an indicator that we need this variable only inside of one function.
string s;

// extern means that the variable will be defined somewhere else and
// therefore must be in the header file.
extern int error_number;

// goes into the header file, because the declaration of a function goes into the header
static double sq(double);

// goes into the implementation file, because definition of normal variables should be in the implementation file, 
// otherwise the memory could be allocated more then once
int count=1;

// Should be in the header file, since this is a constant which can be used somewhere else
// A problem would arise if it was a large constant since it could be allocated multiple times
// but this is not the case for this pi
const double pi=3.2; // according to Indiana Pi Bill

// The type declaration and definition go into the header, since the layout of the type needs to be known to the compiler
// in all compilation units that need to allocate the type
struct fraction { int c; int d; };

// Variables are defined in the implementation file.
char *prog[]={"echo","hello","world!",NULL};

// goes into the header file, because its the declaration of a function.
extern "C" void c_swap(int *a, int *b);

// goes into the header file, because the declaration of a function goes into the header
double sqrt(double);

// Should be in the header file, since this is a pretty small function which
// can be implicitly inlined
void swap(int &a, int &b) { int c=a; a=b; b=c; }

// Since the code for a template is generated when it is parameterized, the compiler
// needs the full code to instantiate the template and therefore, everything template
// related has to be in the header file
template<typename T> T add(T a, T b) { return a+b; }

// goes into the header file, because it's a namespace and thought to be used in other places. 
// the variable inside is just a declartion and if could be used in multiple location, because of the namespace
namespace { int a; }

// Should be in the header file since declaration of variables go into the header file if the variable is to be accessed elsewhere.
// The name indicates that this struct could be used elsewhere, therefore, the header file would be a good place.
struct user;